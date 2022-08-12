#include "math.h"
#include "nmtype.h"

void nmppsSqrt_32f(const nm32f* pSrcVec, nm32f* pDstVec, int nSize) {
	int i;
	for (i = 0; i < nSize; i++) {
		pDstVec[i] = sqrtf(pSrcVec[i]);
	}
}