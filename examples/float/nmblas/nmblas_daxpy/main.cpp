#include <stdio.h>
#include <stdlib.h>
#include "nmblas.h"
#include "nmtype.h"

#define SIZE 10

double x[SIZE] __attribute__ ((section (".data.imu1")));
double y[SIZE] __attribute__ ((section (".data.imu2")));


int main(){
	printf("Input:\n");
	for(int i=0;i<SIZE;i++){
		x[i] = i;
		y[i] = i;
		printf("x[%d]=%f\ty[%d]=%f\n",i,x[i],i,y[i]);
	}
	
	double alpha =2;
	//y=alpha * x + y
	nmblas_daxpy(SIZE,alpha,x,1,y,1);
	printf("Result:\n");
	for(int i=0;i<SIZE;i++){
		printf("y[%d]=%f\n",i,y[i]);
	}

	return 0;
}

