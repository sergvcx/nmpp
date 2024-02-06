
/* The using example of forward FFT128 for floating point */ 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nmtype.h"           // The type nm32fcr was declared here (здесь объявлен тип nm32fcr)
#include "nmpp/fft_32fcr.h"


#define SIZE 128

nm32fcr src[SIZE] __attribute__ ((section (".data.imu1")));
nm32fcr dst[SIZE] __attribute__ ((section (".data.imu2")));


int main()
{
  // a generating a sin func
  // генерация функции синуса
  for(int i = 0; i < SIZE; i++) {
  	src[i].re = sinf(i);
	src[i].im = 0;
  }
  
  // a printing of first 10 src elements
  // печать первых 10 элементов src
  for(int i = 0; i < 10; i++) {
  	printf("src[%d].re = %f, src[%d].im = %f, \n", i, src[i].re, i, src[i].im);
  }
  
  printf("\n\n");
  
  // a special fft var which has to will is initialized by nmppsFFT128InitAlloc_32fcr
  // специальная переменная БПФ, которая должна быть инициализирована с помощью nmppsFFT128InitAlloc_32fcr
  NmppsFFTSpec_32fcr* spec;
  
  // an initializing of a special fft var
  // инициализация специальной переменной БПФ
  int ret_val = nmppsFFT128InvInitAlloc_32fcr(&spec);
  if(ret_val) {
	printf("Error %d!\n", ret_val);
	return 1;
  }
  
  // computing forward fft128 from a generated sin func
  // вычисление прямого БПФ128 от сгенерированной функции синуса
  clock_t t0=clock();
  nmppsFFT128Inv_32fcr(src, 1, dst, 1, spec);
  clock_t t1=clock();
  
  // a printing of first 10 dst elements
  // печать первых 10 элементов dst
  for(int i = 0; i < 10; i++) {
  	printf("dst[%d].re = %f, dst[%d].im = %f, \n", i, dst[i].re, i, dst[i].im);
  }
  
printf("clocks=%ld  clocks/element=%.3f \n",t1-t0,float(t1-t0)/SIZE);
  return 0;
}

