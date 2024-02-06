#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nmpp/nmblas.h"
#include "nmtype.h"

#define SIZE 10
#define PI 3.1415

double x[SIZE] __attribute__ ((section (".data.imu1")));
double y[SIZE] __attribute__ ((section (".data.imu2")));



int main(){
	printf("Input :\n");
	for(int i=0;i<SIZE;i++){
		x[i] = 10*sin(PI/6*i);
		y[i] = 10*cos(PI/6*i);
		printf("x[%d]=%f\ty[%d]=%f\n",i,x[i],i,y[i]);
	}
	
	double alpha =2;
	// rotate by 60 degrees: cos(60) sin(60)
	nmblas_drot(SIZE,x,1,y,1,0.5,0.866);

	printf("\n");
	printf("Result :\n");
	
	for(int i=0;i<SIZE;i++){
		printf("x[%d]=%f\ty[%d]=%f\n",i,x[i],i,y[i]);
	}

	return 0;
}

