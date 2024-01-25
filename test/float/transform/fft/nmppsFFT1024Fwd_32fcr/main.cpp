#include "time.h"
//#include "fft_32fcr.h"
#include "nmpp.h"
#include <nmtype.h>
#include <malloc.h>
#include <stdio.h>

#define		SIZE 		1024


#ifndef __GNUC__ 
#define __attribute__(a) 
#endif


nm32fcr src[SIZE] __attribute__ ((section (".data.imu6")));
nm32fcr dst[SIZE] __attribute__ ((section (".data.imu5")));

int main()
{
	int i, st;
	clock_t t1, t2;
	//nm32fcr *src, *dst;
	// best config (ticks = 8655) src - imu6, dst - imu5
	// src = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
	// dst = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
	for(i = 0; i < SIZE; i++) {
		src[i].im = 0;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}

//for(int i=0; i<1; i++){
	NmppsFFTSpec_32fcr *rat, *irat;
	st = nmppsFFT1024FwdInitAlloc_32fcr(&rat);

	if(st) {
		return st;
	}

	st = nmppsFFT1024InvInitAlloc_32fcr(&irat);

	if(st) {
		return st;
	}

	t1 = clock();
	nmppsFFT1024Fwd_32fcr(src, dst, rat);
	//nmppsFFT1024Fwd_32fcr(src, dst, rat);
	//nmppsFFT1024Fwd_32fcr(src, dst, rat);
	t2 = clock();
	nmppsFFT1024Inv_32fcr(dst, dst, irat);
	st = nmppsFFTFree_32fcr(rat);
	if(st) {
		return st;
	}
	st = nmppsFFTFree_32fcr(irat);
	if(st) {
		return st;
	}
	union {
		float f;
		int   h;
	} norm;

	nmppsNormDiff_L2_32fcr(src, dst, SIZE, &norm.f);
	printf("norm=%f\n", norm.f);
	 for(i = 0; i < SIZE; i++){
	 	printf("%.2f %.2f\n", dst[i].re, dst[i].im);
	 }
	if (norm.f>0.02)
		return 100*norm.f;
//}
	return 0 ;
	
}