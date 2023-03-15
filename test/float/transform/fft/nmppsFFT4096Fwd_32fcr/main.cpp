#include "time.h"
#include "fft_32fcr.h"
#include "nmpp.h"
#include <nmtype.h>
#include <malloc.h>
#include <stdio.h>


#ifndef __GNUC__ 
#define __attribute__(a) 
#endif


nm32fcr src[4096] 		__attribute__ ((section (".data_imu4")));
nm32fcr dst[4096 + 12] 	__attribute__ ((section (".data_imu5")));

#define		SIZE 		4096
#include "math.h"
int main()
{
//	for (float f = 0.0; f < 10; f += 0.01) {
//		float ff = exp(2 * f) - 2 * exp(f);
//		printf("%f %f \n",f, ff);
//	}
//	union {
//		float f;
//		int i;
//	}x,yy,z;
//	x.i =  0x7EFFFFFF;
//	yy.i = 0x7EFFFFFE;
//	x.f = 1.5e+38;
//	z.f = x.f - yy.f;
//	printf("***********\n");
//	
	int i, st;
	clock_t t1, t2;
	//nm32fcr *src, *dst;
	// best config (ticks = 54258)
	//src = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
	//dst = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
	for(i = 0; i < SIZE; i++) {
		src[i].im = 0;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}

	for(i = 0; i < SIZE + 12; i++) {
		src[i].im = 0;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}

	printf("***********\n");
	NmppsFFTSpec_32fcr *rat, *irat;
	st = nmppsFFT4096FwdInitAlloc_32fcr(&rat);
	if(st) {
		return st;
	}
	t1 = clock();
	nmppsFFT4096Fwd_32fcr(src, dst, rat);
	t2 = clock();
	printf("***********\n");
	st = nmppsFFTFree_32fcr(rat);
	
	
	
	printf("***********\n");
	st = nmppsFFT4096InvInitAlloc_32fcr(&irat);
	if(st) {
		return st;
	}
	
	nmppsFFT4096Inv_32fcr(dst, dst, irat);
	
	if(st) {
		return st;
	}
	st = nmppsFFTFree_32fcr(irat);
	printf("***********\n");
	
	if(st) {
		return st;
	}
	float norm;
	nmppsNormDiff_L2_32fcr(src, dst, SIZE, &norm);
	printf("%.7f\n", norm);
	// for(i = 0; i < SIZE + 12; i += 2) {
	// 	printf("[%d]  %.2f  %.2f          %.2f  %.2f\n", i, dst[i].re, dst[i].im, dst[i + 1].re, dst[i + 1].im);
	// }
	if (norm<0.04)
		return 0;
	return *(int*)&norm ;
	
	
}