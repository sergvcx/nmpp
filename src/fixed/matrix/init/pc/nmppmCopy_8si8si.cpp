#include "nmpp.h"
void nmppmCopy_8si8si(nm8s* pSrc, int srcBeginIndex,   int srcStep, nm8s* pDst, int dstBeginIndex, int dstStep, int width, int height) {

	nm8s* rowSrc = pSrc;
	nm8s* rowDst = pDst;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int val = nmppsGet_8s(rowSrc, srcBeginIndex +x);
			nmppsPut_8s(rowDst, dstBeginIndex + x, val);
		}
		rowSrc = nmppsAddr_8s(rowSrc, srcStep);
		rowDst = nmppsAddr_8s(rowDst, dstStep);
	}
}