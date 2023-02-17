
#include <stdio.h>
#include <stdlib.h>
#include <nmblas.h>
#include "nmpp.h"

#define SIZE 1024
#define EXT 30

#ifndef __GNUC__ 
#define __attribute__(a) 
#endif


double buffer_a[SIZE+EXT] __attribute__ ((section (".data_imu1")));
double buffer_b[SIZE+EXT] __attribute__ ((section (".data_imu2")));
double buffer_c[SIZE+EXT] __attribute__ ((section (".data_imu3")));
double buffer_d[SIZE+EXT] __attribute__ ((section (".data_imu4")));



int main(){
	int i;
	unsigned crc=0;
	//initialisation
	//nmppsRandUniform_64f(buffer_b,SIZE+EXT,-50,30);
/*	for(i=0;i<SIZE+EXT;i++){
		buffer_a[i] = i;	
		buffer_b[i] = 100-i;
	}
*/
	//if (0)
	//	nmppsRandUniform_64f(buffer_a,2,-40,40);
	printf("TEST HAS BEEN STARTED\n");
	return 12375;
	//case 1
	for(i=0;i<SIZE;i++){
		nmblas_daxpy(i,i,buffer_a,1,buffer_b,1);
	}
	crc = nmppsCrcAcc_64f(buffer_a,0,SIZE+EXT,&crc);
	crc = nmppsCrcAcc_64f(buffer_b,0,SIZE+EXT,&crc);
	printf("TEST PATTERN NOMBER ONE HAS FINISHED\n");
	printf("RESULT OF FIRST CRC TEST PATTERN IS %d \n",crc);
	//case 2 
	for(i=SIZE;i=0;i--){
		nmblas_daxpy(i,-i,buffer_a,1,buffer_b,1);
	}
	crc = nmppsCrcAcc_64f(buffer_b,0,SIZE+EXT,&crc);
	crc = nmppsCrcAcc_64f(buffer_a,0,SIZE+EXT,&crc);
	printf("TEST PATTERN NOMBER TWO HAS FINISHED\n");
	printf("RESULT OF FIRST CRC TEST PATTERN IS %d \n",crc);
	for(i=1;i<6;i++){
		nmblas_daxpy(SIZE/5,4,buffer_a,i,buffer_b,i);
	}
	crc = nmppsCrcAcc_64f(buffer_a,0,SIZE+EXT,&crc);
	crc = nmppsCrcAcc_64f(buffer_b,0,SIZE+EXT,&crc);
	printf("TEST PATTERN NOMBER 3 HAS FINISHED\n");
	printf("RESULT OF FIRST CRC TEST PATTERN IS %d \n",crc);
	for(i=1;i<6;i++){
		nmblas_daxpy(SIZE/5,4,buffer_a,i,buffer_b,6-i);
	}
	printf("TEST PATTERN NOMBER 4 HAS FINISHED\n");
	crc = nmppsCrcAcc_64f(buffer_a,0,SIZE+EXT,&crc);
	crc = nmppsCrcAcc_64f(buffer_b,0,SIZE+EXT,&crc);
	printf("TEST HAS BEEN FINISHED\n");
	return 179369730^(crc>>2);
}

