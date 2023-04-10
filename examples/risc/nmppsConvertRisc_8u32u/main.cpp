#include <math.h>
#include "nmpp.h"
#include "time.h"
#include <stdio.h>
#include <string.h>

#define		N	400 // число элементов

unsigned int  in[N/4] __attribute__ ((section (".data.imu1")));
unsigned int out[N]   __attribute__ ((section (".data.imu2")));

int main()
{
	clock_t t1, t2;
	in[0] = 0x03020100;
	for(int i = 1; i < N/4; i++) {
	 	in[i] = in[i - 1] + 0x04040404;
	}
	t1 = clock();
	nmppsConvertRisc_8u32u((nm8u *)in, out, N);
	t2 = clock();
	
	
	for(int i = 0; i < 4; i++) {
		printf("in[%d]  %08x \n", i, in[i]);
	}
	for(int i = 0; i < 16; i++) {
		printf("out[%d] %08x \n", i, out[i]);
	}
	
	return (t2-t1);
}