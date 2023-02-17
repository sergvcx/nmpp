//#include <malloc.h>
#include "malloc32.h"

//#include "nmplv/vSupport.h"
//#include "nmplv/vInit.h"
//#include "nmplv/vBitwise.h"


#ifdef __NM__
	void * malloc32(unsigned size) { return malloc(size); }
#else 
void * malloc32(size) {	malloc((size) << 2);}
#endif 




nm8s*  nmppsMallocFrame_8s (unsigned sizeInt8 , unsigned boundaryInt8 , NmppsFrame_8s * pFrame){return (nm8s* )nmppsMallocFrame_64u((sizeInt8+ 7)>>3,(boundaryInt8+ 7)>>3,(NmppsFrame_64u*)pFrame);}
nm8u*  nmppsMallocFrame_8u (unsigned sizeInt8 , unsigned boundaryInt8 , NmppsFrame_8u * pFrame){return (nm8u* )nmppsMallocFrame_64u((sizeInt8+ 7)>>3,(boundaryInt8+ 7)>>3,(NmppsFrame_64u*)pFrame);}
nm16s* nmppsMallocFrame_16s(unsigned sizeInt16, unsigned boundaryInt16, NmppsFrame_16s* pFrame){return (nm16s*)nmppsMallocFrame_64u((sizeInt16+3)>>2,(boundaryInt16+3)>>2,(NmppsFrame_64u*)pFrame);}
nm16u* nmppsMallocFrame_16u(unsigned sizeInt16, unsigned boundaryInt16, NmppsFrame_16u* pFrame){return (nm16u*)nmppsMallocFrame_64u((sizeInt16+3)>>2,(boundaryInt16+3)>>2,(NmppsFrame_64u*)pFrame);}
nm32s* nmppsMallocFrame_32s(unsigned sizeInt32, unsigned boundaryInt32, NmppsFrame_32s* pFrame){return (nm32s*)nmppsMallocFrame_64u((sizeInt32+1)>>1,(boundaryInt32+1)>>1,(NmppsFrame_64u*)pFrame);}
nm32u* nmppsMallocFrame_32u(unsigned sizeInt32, unsigned boundaryInt32, NmppsFrame_32u* pFrame){return (nm32u*)nmppsMallocFrame_64u((sizeInt32+1)>>1,(boundaryInt32+1)>>1,(NmppsFrame_64u*)pFrame);}
nm64s* nmppsMallocFrame_64s(unsigned sizeInt64, unsigned boundaryInt64, NmppsFrame_64s* pFrame){return (nm64s*)nmppsMallocFrame_64u(sizeInt64,boundaryInt64,(NmppsFrame_64u*)pFrame);}
nm64u* nmppsMallocFrame_64u(unsigned sizeInt64, unsigned boundaryInt64, NmppsFrame_64u* pFrame){      
	pFrame->pull=malloc32(sizeInt64*2+boundaryInt64*4);
	pFrame->data=(nm64u*)pFrame->pull;
	if (pFrame->pull)
		pFrame->data+=boundaryInt64;
	return pFrame->data;
}
void   nmppsFreeFrame(void* buffer){
	if (((NmppsFrame_64u*)buffer)->pull)
		free(((NmppsFrame_64u*)buffer)->pull);
}