#include "time.h"
#include "fft_32fcr.h"
#include "nmpp.h"
#include <nmtype.h>
#include <malloc.h>
#include <stdio.h>

#define		SIZE 		512

#ifndef __GNUC__ 
#define __attribute__(a) 
#endif


nm32fcr src[SIZE] __attribute__ ((section (".data.imu2")));
nm32fcr dst[SIZE] __attribute__ ((section (".data.imu5")));


int main()
{
	int i, st;
	clock_t t1, t2;
//	nm32fcr *src, *dst;
// best config (ticks = 3675)
//	src = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
//	dst = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
	for(i = 0; i < SIZE; i++) {
		src[i].im = 1;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}
	NmppsFFTSpec_32fcr *rat, *irat;
	st = nmppsFFT512FwdInitAlloc_32fcr(&rat);
	if(st) {
		return st;
	}
	st = nmppsFFT512InvInitAlloc_32fcr(&irat);
	if(st) {
		return st;
	}
	t1 = clock();
	nmppsFFT512Fwd_32fcr(src, dst, rat);
	t2 = clock();
	nmppsFFT512Inv_32fcr(dst, dst, irat);
	st = nmppsFFTFree_32fcr(rat);
	if(st) {
		return st;
	}
	st = nmppsFFTFree_32fcr(irat);
	if(st) {
		return st;
	}
	float norm;
	
	nmppsNormDiff_L2_32fcr(src, dst, SIZE, &norm);
	printf("norm=%.7f\n", (double)norm);
	// for(i = 0; i < SIZE; i++){
	// 	printf("%.2f %.2f\n", dst[i].re, dst[i].im);
	// }
	if (norm<0.02)
		return 0;
	return 123 ;
	
	
	//return t2 - t1;
}