#include "nmblas.h"
#define SIZE 10

double src[SIZE];
int main(){
	for(int i=0;i<SIZE;i++){
		src[i] = i;
	}
	
	double result = nmblas_dasum(SIZE,src,1);
	return 0;
}

