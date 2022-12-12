#include <stdio.h>
#include <stdlib.h>
#include <nmblas.h>
#include <nmpp.h>

#define SIZE 1024

#ifdef __GNUC__ //  NMC-GCC C++ compilier 
float buffer_a[SIZE] __attribute__ ((section (".data_imu1")));
float buffer_b[SIZE] __attribute__ ((section (".data_imu2")));
#else 		// NMSDK C++ compiler
#pragma data_section ".data_imu1"
float buffer_a[SIZE];
#pragma data_section ".data_imu2"
float buffer_b[SIZE];
#endif 

int main(){

	int i=0;
	int r;
	float result =0;
	unsigned crc=0;
	nmppsRand_32f(buffer_a,SIZE,-10,10);
	nmppsRand_32f(buffer_b,SIZE,-10,10);
	
	for(i=0;i<SIZE;i+=2){
		result = nmblas_sdot(i,buffer_a,1,buffer_b,1);
		printf("the result is %f %x\n",result, *(int*)&result );
		crc = nmppsCrcAcc_32f(&result,18,1,&crc);
	}

	return crc>>2;
}

