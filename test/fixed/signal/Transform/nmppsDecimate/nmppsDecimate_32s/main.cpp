#include "nmpp.h"
#include "time.h"
#include "stdio.h"

#define MAX_SIZE 1024
#define MAX_STEP 8
int main (){
	

	nm32s* src  =nmppsMalloc_32s(MAX_SIZE);
	nm32s* dst  =nmppsMalloc_32s(MAX_SIZE+128);
	if ((src==0)||(dst==0)) return -1;

	nmppsSet_32s(0xCDCDCDCD,dst,MAX_SIZE+128);
	nmppsRandUniform_32s(src,MAX_SIZE);
	
	clock_t t1,t0;
	unsigned crc = 0;
	
	for (int startPos=0; startPos<2; startPos++){
		for (int step=2; step<MAX_STEP; step+=2){
			for (int size =2;size<=MAX_SIZE/step;size+=2){
				t0 = clock();
				nmppsDecimate_32s(src, startPos, step, dst, size);
				t1 = clock();
				nmppsCrcAcc_32s(dst,size+128,&crc);
			}
		}	
	}
	printf("32 crc=0x%X",crc);
	return crc^0x617bb9fd;
	//return t1-t0;
	
}