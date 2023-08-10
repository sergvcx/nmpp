
/* Usage of forward and inverse float-point FFT-128 with static buffer allocation  */ 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nmtype.h"          // The type nm32fcr was declared here (здесь объявлен тип nm32fcr)
#include "fft_32fcr.h"
#include "string.h"


#define SIZE 128

	
__attribute__ ((section (".data.imu0"))) nm32fcr fwdBuffer0 [120];
__attribute__ ((section (".data.imu1"))) nm32fcr fwdBuffer1 [120];
__attribute__ ((section (".data.imu2"))) nm32fcr fwdBuffer2 [96];
__attribute__ ((section (".data.imu3"))) nm32fcr fwdBuffer3 [64];

__attribute__ ((section (".data.imu0"))) nm32fcr invBuffer0 [120];
__attribute__ ((section (".data.imu1"))) nm32fcr invBuffer1 [120];
__attribute__ ((section (".data.imu2"))) nm32fcr invBuffer2 [96];
__attribute__ ((section (".data.imu3"))) nm32fcr invBuffer3 [64];

__attribute__ ((section (".data.imu5"))) nm32fcr src[SIZE];
__attribute__ ((section (".data.imu5"))) nm32fcr dst[SIZE];

int main()
{
	printf("Usage of forward and inverse float-point FFT-128 with static buffer allocation\n"); 
	// специальная структура прямого БПФ, которая должна быть инициализирована с помощью nmppsFFT128FwdInit_32fcr
	NmppsFFTSpec_32fcr specFwd;
	specFwd.Buffs[0] = fwdBuffer0;
	specFwd.Buffs[1] = fwdBuffer1;
	specFwd.Buffs[2] = fwdBuffer2;
	specFwd.Buffs[3] = fwdBuffer3;
	nmppsFFT128FwdInit_32fcr(&specFwd); // инициализация БПФ
	
	// специальная структура обратного БПФ, которая должна быть инициализирована с помощью nmppsFFT128InvInit_32fcr
	NmppsFFTSpec_32fcr specInv;
	specInv.Buffs[0] = invBuffer0;
	specInv.Buffs[1] = invBuffer1;
	specInv.Buffs[2] = invBuffer2;
	specInv.Buffs[3] = invBuffer3;
	nmppsFFT128InvInit_32fcr(&specInv); // инициализация БПФ
	
	// генерация функции синуса
	for(int i = 0; i < SIZE; i++) {
		src[i].re = sinf(i*3.1415926535/32);
		src[i].im = 0;
	}

	// печать первых элементов src
	printf("\n");
	for(int i = 0; i < 10; i++) 
		printf("src[%d].re = %f, src[%d].im = %f, \n", i, src[i].re, i, src[i].im);
	
	// вычисление прямого БПФ от сгенерированной функции синуса
	clock_t t0=clock();
	nmppsFFT128Fwd_32fcr(src, 1, dst, 1, &specFwd);
	clock_t t1=clock();

	// печать первых 10 элементов спектра
	printf("\n");
	for(int i = 0; i < 10; i++) {
		printf("dst[%d].re = %f, dst[%d].im = %f, \n", i, dst[i].re, i, dst[i].im);
	}

	printf("FWD FFT 128 clocks=%ld  clocks/element=%.3f \n",t1-t0,float(t1-t0)/SIZE);
	
	// вычисление обратного БПФ 
	memset(src,0,128*sizeof(nm32fcr));
	t0=clock();
	nmppsFFT128Inv_32fcr(dst, 1, src, 1, &specInv);
	t1=clock();

	// печать первых 10 элементов восстановленного сигнала
	printf("\n");
	for(int i = 0; i < 10; i++) {
		printf("src-inv[%d].re = %f, src-inv[%d].im = %f, \n", i, src[i].re, i, src[i].im);
	}

	printf("INV FFT 128 clocks=%ld  clocks/element=%.3f \n",t1-t0,float(t1-t0)/SIZE);
	return 0;
}

