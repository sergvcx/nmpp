
/* The using example of forward FFT1024 for floating point */ 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nmtype.h"           // The type nm32fcr was declared here (здесь объявлен тип nm32fcr)
#include "nmpp/fft_32fcr.h"


#define SIZE 1024


nm32fcr buffer0 [512 + 1] __attribute__ ((section (".data.imu0")));
nm32fcr buffer1 [512]     __attribute__ ((section (".data.imu1")));
nm32fcr buffer2 [512]     __attribute__ ((section (".data.imu2")));
nm32fcr buffer3 [7 + 512] __attribute__ ((section (".data.imu3")));

nm32fcr src[SIZE] __attribute__ ((section (".data.imu5")));
nm32fcr dst[SIZE] __attribute__ ((section (".data.imu5")));

int main()
{
	// special fft var which has to will is initialized by nmppsFFT1024InitAlloc_32fcr
	// специальная переменная БПФ, которая должна быть инициализирована с помощью nmppsFFT1024InitAlloc_32fcr
	NmppsFFTSpec_32fcr spec;
	spec.Buffs[0] = buffer0;
	spec.Buffs[1] = buffer1;
	spec.Buffs[2] = buffer2;
	spec.Buffs[3] = buffer3;
	// initializing of a special fft var
	// инициализация специальной переменной БПФ
	nmppsFFT1024FwdInit_32fcr(&spec);
	
	// generating a sin func
	// генерация функции синуса
	for(int i = 0; i < SIZE; i++) {
		src[i].re = sinf(i*3.1415926535/128);
		src[i].im = 0;
	}
	// src[0].re = 1;

	// printing of 10 first src elements
	// печать первых 10 элементов src
	for(int i = 0; i < 10; i++) 
		printf("src[%d].re = %f, src[%d].im = %f, \n", i, src[i].re, i, src[i].im);


	printf("\n\n");

	// computing forward fft1024 from a generated sin func
	// вычисление прямого БПФ1024 от сгенерированной функции синуса
	clock_t t0=clock();
	nmppsFFT1024Fwd_32fcr(src, dst, &spec);
	clock_t t1=clock();

	// printing of 10 first dst elements
	// печать первых 10 элементов dst
	for(int i = 0; i < 10; i++) {
		printf("dst[%d].re = %f, dst[%d].im = %f, \n", i, dst[i].re, i, dst[i].im);
	}

	printf("clocks=%ld  clocks/element=%.3f \n",t1-t0,float(t1-t0)/SIZE);
	return 0;
}

