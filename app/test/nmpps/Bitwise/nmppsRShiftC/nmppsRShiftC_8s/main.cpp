#include "nmpp.h"

#include <time.h>

nm64s *L0;
nm64s *L1;
nm64s *G0;
nm64s *G1;
const int KB=1024/8;
const int SizeL0=30*KB;
const int SizeL1=30*KB;

const int SizeG0=30*KB;
const int SizeG1=30*KB;

//! \fn void nmppsRShiftC_8s(nm8s*, int, nm8s*,int)

int main()
{
	


	L0=nmppsMalloc_64s(SizeL0);
	G0=nmppsMalloc_64s(SizeG0);
	if ((L0==0)||(G0==0))	return -1;


	unsigned int crc = 0;

	int	MaxCharSize = 1024;
	MaxCharSize=MIN(MaxCharSize,LONG2char(SizeL0));
	MaxCharSize=MIN(MaxCharSize,LONG2char(SizeG0));

	nmppsRandUniform_64s((nm64s*)L0,SizeL0);
	nm64s c=0xCCCCCCCCAAAAAAAAl;
	nmppsSet_64s((nm64s*)G0,c,(SizeG0));


	for(int CharSize=0;CharSize<MaxCharSize;CharSize+=8)
	{
 		int Shift=nmppcRandMinMax(0,7);
		nmppsRShiftC_8s((nm8s*)L0,Shift,(nm8s*)G0,CharSize);
		nmppsCrcAcc_32u((nm32u*)G0,MIN(char2INT(CharSize)+128,LONG2INT(SizeG0)),&crc);
	}


	nmppsFree(L0);
	nmppsFree(G0);

	

	return crc>>2;
}
