#include "fft_32fcr.h"
#include "nmpp.h"
#include "time.h"
#include <nmtype.h>
#include <malloc.h>
#include <stdio.h>

#define		SIZE 		128

int main()
{
	printf("fft 128 test\n");
	
	int i, st;
	clock_t t1, t2;
	nm32fcr *src, *dst;
	// best config (ticks = 1091)
	src = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
	dst = (nm32fcr *)malloc(SIZE * sizeof(nm32fcr));
	for(i = 0; i < SIZE; i++) {
		src[i].im = 1;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}
	NmppsFFTSpec_32fcr *rat, *irat;
	st = nmppsFFT128FwdInitAlloc_32fcr(&rat);
	if(st) {
		return st;
	}
	printf("alloc fwd passed\n");
	st = nmppsFFT128InvInitAlloc_32fcr(&irat);
	if(st) {
		return st;
	}
	printf("alloc inv passed\n");
	t1 = clock();
	nmppsFFT128Fwd_32fcr(src, 1, dst, 1, rat);
	t2 = clock();
	printf("fwd passed\n");
	nmppsFFT128Inv_32fcr(dst, 1, dst, 1, irat);
	printf("inv passed\n");
	st = nmppsFFTFree_32fcr(rat);
	if(st) {
		return st;
	}
	printf("free fwd passed\n");
	st = nmppsFFTFree_32fcr(irat);
	if(st) {
		return st;
	}
	printf("free inv passed\n");
	float norm;
	nmppsNormDiff_L2_32fcr(src, dst, SIZE, &norm);
	printf("norm  passed\n");
	printf("%.7f\n", norm);

	// for(i = 0; i < SIZE; i++){
	// 	printf("%.5f %.5f\n", dst[i].re, dst[i].im);
	// }
	if (norm<0.02)
		return 0;
	return *(int*)&norm ;
	
	
	//return t2 - t1;
}