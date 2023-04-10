#include <math.h>
#include "nmpp.h"
#include "time.h"
#include <stdio.h>
#include <string.h>

#define		N	400 // число целых чисел

unsigned int in[N]  __attribute__ ((section (".data.imu1")));
unsigned int out[N/4] __attribute__ ((section (".data.imu2")));



int main()
{
	clock_t t1, t2;
	for(int i = 0; i < N; i++) {
	 	in[i] = i;
	}
	memset(out,0,N);
	
	t1 = clock();
	nmppsConvertRisc_32u8u(in, (nm8u*)out, N);
	t2 = clock();

	for(int i = 0; i < 16; i++) {
		printf("in[%d]  %08x \n", i, in[i]);
	}
	for(int i = 0; i < 4; i++) {
		printf("out[%d] %08x \n", i, out[i]);
	}
	return (t2-t1);
}