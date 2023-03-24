#include <math.h>
#include "nmpp.h"
#include "time.h"
#include <stdio.h>

#define		N_ST	400 // число целых чисел

unsigned int in[N_ST/4]  __attribute__ ((section (".data.imu1")));
unsigned int out[N_ST/4] __attribute__ ((section (".data.imu2")));



int main()
{
	clock_t t1, t2;
	unsigned int crc = 0;
	for(int i = 0; i < N_ST; i += 4) {
	 	in[i] = 1;
	 	in[i + 1] = 2;
	 	in[i + 2] = 3;
	 	in[i + 3] = 4;
	 	out[i] = 0;
	 	out[i + 1] = 0;
	 	out[i + 2] = 0;
	 	out[i + 3] = 0;
	}
	t1 = clock();
	nmppsConvertRisc_32u8u(in, (nm8u*)out, N_ST);
	t2 = clock();

	nmppsCrcAcc_32u(out, N_ST, &crc);
	printf("%d\n", t2 - t1);

	for(int i = 0; i < N_ST/4 + 10; i++) {
		printf("%d  %d \n", i, out[i]);
	}
	return (crc>>2)^0;
}