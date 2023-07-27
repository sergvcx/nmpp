#include "nmpp.h"
#include "time.h"
#include "stdio.h"

#define MAX_SIZE 1024
#define MAX_STEP 16

int main (){
	

	nm16s* src  =nmppsMalloc_16s(MAX_SIZE);
	nm16s* dst  =nmppsMalloc_16s(MAX_SIZE+128);
	if ((src==0)||(dst==0)) return -1;

	nmppsSet_16s(0xCDCD,dst,MAX_SIZE+128);
	nmppsRandUniform_16s(src,MAX_SIZE);
	
	clock_t t1,t0;
	unsigned crc = 0;
	
	for (int startPos=0; startPos<4; startPos++){
		for (int step=4; step<MAX_STEP; step+=4){
			for (int size =4; size<=MAX_SIZE/step; size+=4){
				t0 = clock();
				nmppsDecimate_16s(src, startPos, step, dst, size);
				t1 = clock();
				nmppsCrcAcc_16s(dst,size+128,&crc);
			}
		}	
	}
	
	printf("16 crc=0x%X",crc);
	return crc^0xba345429;
	//return t1-t0;
	
}