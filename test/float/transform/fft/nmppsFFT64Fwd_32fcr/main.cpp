#include "fft_32fcr.h"
#include "nmpp.h"
#include "time.h"
#include <nmtype.h>
#include <malloc.h>
#include <stdio.h>

#define		SIZE 		64

int main()
{
	int i, st;
	clock_t t1, t2;
	nm32fcr *src, *dst;
	// best config (ticks = 520)
	src = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
	dst = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
	for(i = 0; i < SIZE; i++) {
		src[i].im = 1;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}
	NmppsFFTSpec_32fcr *rat, *irat;
	st = nmppsFFT64FwdInitAlloc_32fcr(&rat);
	if(st) {
		return st;
	}
	st = nmppsFFT64InvInitAlloc_32fcr(&irat);
	if(st) {
		return st;
	}
	t1 = clock();
	nmppsFFT64Fwd_32fcr(src, dst, rat);
	t2 = clock();
	nmppsFFT64Inv_32fcr(dst, dst, irat);
	st = nmppsFFTFree_32fcr(rat);
	if(st) {
		return st;
	}
	float norm;
	nmppsNormDiff_L2_32fcr(src, dst, SIZE, &norm);
	st = nmppsFFTFree_32fcr(irat);
	if(st) {
		return st;
	}
	printf("%.7f\n", norm);

	// for(i = 0; i < SIZE; i++) {
	// 	printf("%.5f %.5f\n", dst[i].re, dst[i].im);
	// }
	if (norm<0.02)
		return 0;
	return *(int*)&norm ;
	
	
	//return t2 - t1;
}