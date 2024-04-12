#include "nmpp/nmpli.h"

extern "C"{
// R, G, B, 0
static int wgh1Cr[]={ 0x8000,-0x7446,-0xbba,0 };
static int wgh2Cr[]={ 0x8000,-0x7446,-0xbba,0 };

static int wgh1Cb[]={ -0x1d56,-0x62aa,0x8000,0 };
static int wgh2Cb[]={ -0x1d56,-0x62aa,0x8000,0 };

static int * wgh1;
static int * wgh2;

void nmppiRGB32ToCbCr_8u32s(nm8u * pRGB, nm32s* pDst, int nSize)
{  int i,j, k;
   unsigned int * p;
   unsigned char * rgb; 
   p=(unsigned int*)pDst;
   rgb=(unsigned char *)pRGB;
  j=0;
  for (i=0; i<nSize; i++)
  { 
     k= wgh1[0]*(char)(rgb[j]^0x80);
     k+=wgh1[1]*(char)(rgb[j+1]^0x80);
     k+=wgh1[2]*(char)(rgb[j+2]^0x80);
     j+=4;
     p[i]=k;
     i++;
     k= wgh2[0]*(char)(rgb[j]^0x80);
     k+=wgh2[1]*(char)(rgb[j+1]^0x80);
     k+=wgh2[2]*(char)(rgb[j+2]^0x80);
     j+=4;
     p[i]=k;
  }
}
void nmppiRGB32ToCbCr_8s32s(nm8s * pRGB, nm32s* pDst, int nSize)
{  int i,j, k;
   int * p; 
   char * rgb; 
   p=(int*)pDst;
   rgb=(char*)pRGB;

  j=0;
  for (i=0; i<nSize; i++)
  {
     k= wgh1[0]*rgb[j];
     k+=wgh1[1]*rgb[j+1];
     k+=wgh1[2]*rgb[j+2];
     j+=4;
     p[i]=k;
     i++;
     k= wgh2[0]*rgb[j];
     k+=wgh2[1]*rgb[j+1];
     k+=wgh2[2]*rgb[j+2];
     j+=4;
     p[i]=k;
  }
}
};

void nmppiRGB32ToCb_8u32s(nm8u * pRGB, nm32s* pDst, int nSize) {
	wgh1 = wgh1Cb;
	wgh2 = wgh1Cb;
	nmppiRGB32ToCbCr_8u32s(pRGB, pDst, nSize);
}

void nmppiRGB32ToCr_8u32s(nm8u * pRGB, nm32s* pDst, int nSize) {
	wgh1 = wgh1Cr;
	wgh2 = wgh1Cr;
	nmppiRGB32ToCbCr_8u32s(pRGB, pDst, nSize);
}

void nmppiRGB32ToCb_8s32s(nm8s * pRGB, nm32s* pDst, int nSize) {
	wgh1 = wgh1Cb;
	wgh2 = wgh1Cb;
	nmppiRGB32ToCbCr_8s32s(pRGB, pDst, nSize);
}

void nmppiRGB32ToCr_8s32s(nm8s * pRGB, nm32s* pDst, int nSize) {
	wgh1 = wgh1Cr;
	wgh2 = wgh1Cr;
	nmppiRGB32ToCbCr_8s32s(pRGB, pDst, nSize);
}