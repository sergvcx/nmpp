#include <nmtype.h>
#include <malloc32.h>
#include <nmpp.h>
#include <stdio.h>


#define PI 3.1415

int main()
{
	float* src0 = (float *) nmppsMalloc_32f(64);
	float* src1 = (float *) nmppsMalloc_32f(64);
	unsigned crc=0;
	for(int i = 0; i < 64; i++) {
		src0[i] = i*PI;
		src1[i] = i*PI+0.1;
	}
	float norm;
	
	
	for(int size=2; size<64; size+=2){
		//#ifdef NEURO 
		nmppsNormDiff_Inf_32f(src0,src1,size,&norm);
		//#endif
		printf ("%f\n",norm);
		nmppsCrcAcc_32f(&norm,0,1,&crc);
	}
	
	//nmppsNormDiff_Inf_32f(src0,src1,32,&norm);
	free(src0);
	free(src1);
	return (crc>>2)^216756152 ;
}