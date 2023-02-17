#include "nmpp.h"
//#include "minrep.h"
#include "stdio.h"
#include "time.h"
/////////////////////////////////////////////////////////////////////////////////
int KB=1024/8;

int main()
{
	
	int maxSize64=32*KB;
	int maxSize=maxSize64*8;
	clock_t t0,t1;
	
	nm2s* src=nmppsMalloc_2s(maxSize);
	nm4s* dst=nmppsMalloc_4s(maxSize+2*16);
	if ((src==0)||(dst==0)) return -1;


	unsigned int crc = 0;
	nmppsRandUniform_64s((nm64s*)src,maxSize/32);
	nmppsSet_32s((0xCCCCCCCC),(nm32s*)dst,maxSize/8+4);
	for(int testSize=32; testSize<maxSize; testSize+=32)
	{
		t0=clock();
		nmppsConvert_2s4s((nm2s*)src,(nm4s*)dst,testSize);
		t1=clock();
		nmppsCrcAcc_32s((nm32s*)dst,testSize/8+4,&crc);
		if ((testSize&(testSize-1)) == 0 && testSize)
			printf("size=%8d %f\n",testSize, (t1-t0)*1.0/testSize);
	}
	

	nmppsFree(src);
	nmppsFree(dst);
	

	return (crc>>2)^0;
}

