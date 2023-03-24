#include <stdio.h>
#include <stdlib.h>
#include "nmblas.h"
#include "nmpp.h"
#include "math.h"

#define SIZE 1024
//unsigned int buff[1000];
double buffer_a[SIZE] __attribute__ ((section (".data.imu1")));
int main(){
	int result = nmblas_idamax(32,buffer_a,1);
	return result;
}
int main1(){
	//asm("pswr clear 0x40;");
	int i=0;
	int r;
	
	unsigned int result =0;
	unsigned int crc=0;
	float *pointer;
	//nmppsRandUniform_64f(buffer_a,SIZE,-30,30);
	//nmppsSet_64f(buffer_a,SIZE,0);
	
	//double ddd=NAN;
	
	//printf("%llx\n",*((long long*)&ddd));
	//printf("")

	for(int i=0; i<SIZE; i++ )
		buffer_a[i]=i;
	
	//dis7] =  -1000000;
	buffer_a[600]  = -845;
	buffer_a[10]  =  -45;
	buffer_a[35]  =  63;
	buffer_a[36]  =  63;
	buffer_a[37]  =  63;
	buffer_a[122]  =  126;
	buffer_a[70]  =   104;
	buffer_a[601]  = -845;
	buffer_a[567] =  -700;

	/*for(i=0;i<SIZE;i++){
		printf("THE ARR_X[%d]  %f\n",i,buffer_a[i]);
		printf("%llu\n",buffer_a[i]);
	}*/

/////////////////////////////////////////////////////////////////////// case 1 
	printf("TEST HAS BEEN STARTED\n");
	
	//for(int i=0; i<32; i++ )
	//	printf("%i %f\n",i,buffer_a[i]);
	
	for (int i=0;i<32; i++){
		buffer_a[i]=100+i;
		result = nmblas_idamax(32,buffer_a,1);
		printf("result=%i %f\n",result,buffer_a[result]);
	}
	if (0) for (int i=32; i<48; i++){
		result = nmblas_idamax(i,buffer_a,1);
		printf("size=%i %f\n",result,buffer_a[result]);
	//result^= nmblas_idamax(32,buffer_a,1);
	}
	return result;
	
	//for(i=0;i<SIZE;i++){
	for(i=32;i<1024;i++){
		result = nmblas_idamax(i,buffer_a,1);
		//printf("ARR[%d] THE INDEX OF MAX IS  %d\n",i,result);
	
		printf("res=%d\n", result) ;
		//return result;
		
		nmppsCrcAcc_32u(&result,1,&crc);
		
		//pointer	= (float*)&result;
		//crc = nmppsCrcAcc_64f(pointer,0,1,&crc);	
	}
	

	return crc^0xD3763898;
	//register int sir asm("gr5");
	//asm volatile ("pswr clear 0x40;\n\t":::);
	//
	//result = nmblas_idamax(10,buffer_a,1);
	//
	//asm volatile ("sir = FPIOIR;\n\t":::);
	//asm volatile ("%0 = sir;\n\t":"=r" (sir)::);
	//
	//printf("Bad data - FPIOIR: 0x%x\n", sir);
	//
	//asm volatile ("pswr set 0x40;\n\t":::);


	//for(int i=0; i<SIZE; i++ )
	//	printf("%f\n",result);
	
	printf("index=%d \n",result);
	printf("CURRENT CRC IS %d\n",crc);
	printf("TEST PATTER NUMBER 1 HAS FINISHED\n");
	//return (crc>>2)^0;
/////////////////////////////////////////////////////////////////////// case 2 
	
	for(i=0;i<6;i++){
		result = nmblas_idamax(20,buffer_a,i);
		//printf("THE INDEX OF MAX IS  %d\n",result);
		nmppsCrcAcc_32u(&result,1,&crc);
		//crc = nmppsCrcAcc_32f(pointer,0,1,&crc);
	}
	printf("CURRENT CRC IS %d\n",crc);
	printf("TEST PATTER NUMBER 2 HAS FINISHED\n");
/////////////////////////////////////////////////////////////////////// case 3 
	
	for(i=0;i<6;i++){
		result = nmblas_idamax(SIZE/6,buffer_a,i);
		//printf("THE INDEX OF MAX IS  %d\n",result);
		nmppsCrcAcc_32u(&result,1,&crc);
		//crc = nmppsCrcAcc_32f(pointer,0,1,&crc);
	}
	printf("TEST PATTER NUMBER 3 HAS FINISHED\n");
/////////////////////////////////////////////////////////////////////// case 4 
	printf("THE FINAL CRC %d\n",crc);
	printf("TEST HAS BEEN FINISHED\n");
	return (crc>>2)^ 0x2ce6f03b;

}


