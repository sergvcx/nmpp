#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nmpp/nmblas.h"
#include "nmtype.h"

#define SIZE 10
#define PI 3.1415

double x[SIZE] __attribute__ ((section (".data.imu1")));
double y[SIZE] __attribute__ ((section (".data.imu2")));

double param[5];
int main(){
	int i;

	param[1] = 0.707;//h11
	param[2] = -0.707;//h21
	param[3] = 0.707;//h12
	param[4] = 0.707;//h22

	// DROTM - BLAS level one. Applies a modified Givens rotation.

	for(int i=0;i<SIZE;i++){
		x[i] = 10*sin(PI/6*i);
		y[i] = 10*cos(PI/6*i);
		printf("x[%d]=%f\ty[%d]=%f\n",i,x[i],i,y[i]);
	}
	printf("\n");

	param[0] = -2; 
	printf("PARAM is -2\n");
	nmblas_drotm(SIZE,x,1,y,1,param);

	for(int i=0;i<SIZE;i++){
		printf("x[%d]=%f\ty[%d]=%f\n",i,x[i],i,y[i]);
	}
	printf("\n");

	return 0;
}
	