#include <stdlib.h>


void nmppmCopy_32fc(
		double*	SrcMtr,
			int		nSrcStride,
			double*	DstMtr,
			int		nDstStride,
			int		nHeight,
			int		nWidth)

{
	int i;
	for(i=0;i<nHeight;i++)
	{
		nmppsCopy_64s(SrcMtr,DstMtr,nWidth);
		SrcMtr+=nSrcStride;
		DstMtr+=nDstStride;
	}
}