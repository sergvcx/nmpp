#include "nmpp.h"
#include "minrep.h"



/////////////////////////////////////////////////////////////////////////////////
nm64s *L0;
nm64s *L1;
nm64s *G0;
nm64s *G1;
 int KB=1024/8;
 int SizeL0=60*KB;
 int SizeL1=60*KB;

 int SizeG0=60*KB;
 int SizeG1=60*KB;

//! \fn	void nmppsConvert_8s4s(nm8s* pSrc,nm4s* pDst,int)
int main()
{
	

	L0=nmppsMalloc_64s(SizeL0);
	L1=nmppsMalloc_64s(SizeL1);
	G0=nmppsMalloc_64s(SizeG0);
	G1=nmppsMalloc_64s(SizeG1);
	if ((L0==0)||(L1==0)||(G0==0)||(G1==0)) return -1;


	unsigned int crc = 0;

	nmppsRandUniform_32u((nm32u*)L0,SizeL0*2);
	nmppsSet_32u((0xCCCCCCCC),(nm32u*)G0,SizeG0*2);
	for(int nSize=16; nSize<SizeL0*8; nSize+=16)
	{
		nmppsConvert_8s4s(( nm8s*)L0,(nm4s*)G0,nSize);	
		nmppsCrcAcc_32u((nm32u*)G0,nSize/8+128,&crc);
	}

	nmppsFree(L0);
	nmppsFree(L1);
	nmppsFree(G0);
	nmppsFree(G1);

	

	return (crc>>2)^0;
}

