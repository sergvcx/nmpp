#include <stdio.h>
#include <stdlib.h>
#include "nmpp/nmblas.h"
#include "time.h"
#include "nmtype.h"

#define SIZE 1600

double x[SIZE] __attribute__ ((section (".data.imu1")));
double y[SIZE] __attribute__ ((section (".data.imu2")));

int main(){
	for(int i=0;i<SIZE;i++){
		x[i] = i;
		y[i] = 0;
		printf("x[%d]=%f\ty[%d]=%f\n",i,x[i],i,y[i]);
	}
	clock_t t0,t1;
	t0=clock();
	nmblas_dcopy(SIZE,x,2,y,1);
	t1=clock();
	for(int i=0;i<SIZE;i++){
		printf("y[%d]=%f\n",i,y[i]);
	}
	//return t1-t0;
	return 0;
}

