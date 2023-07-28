#include "nmpp.h"
#include "minrep.h"
#include "stdio.h"



int main()
{
	
	int maxW0=70;
	int maxH0=70;
	int maxW1=70;

	nm2s*  src0=nmppsMalloc_2s (maxW0*maxH0);
	nm16s* src1=nmppsMalloc_16s(maxW1*maxW0);
	nm16s* dst =nmppsMalloc_16s(maxW1*(maxH0+1));
	if ((src0==0)||(src1==0)||(dst==0)) return -1;

	unsigned int crc = 0;
	nmppsRandUniform_32s((nm32s*)src0,maxW0*maxH0/16);
	nmppsRandUniform_16s(src1,maxW1*maxW0);
	nmppsSet_16s(0xCCCCCCCC,dst,maxW1*(maxH0+1));
	
	int w1=0;
	for(int h0=1; h0<=maxH0; h0+=1){
		for(int w0=32; w0<=maxW0; w0+=32){
			//printf("h0=%d w0=%d w1=%d %x\n",h0,w0,w1,crc);
			for(int w1=4; w1<=maxW1; w1+=4){
				nmppmMul_mm_2s16s(src0,h0,w0,src1, dst, w1);				
				nmppsCrcAcc_16s (dst, w1*(h0+1),&crc);
			}
		}
	}

	nmppsFree(src0);
	nmppsFree(src1);
	nmppsFree(dst);
	
	printf("crc= 0x%X\n",crc);
	return crc ^ 0x9BC871D6;
}
