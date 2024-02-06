#include "nmpp/fft_32fcr.h"

void nmppsFFT128Fwd_32fcr(const nm32fcr* pSrcVec, int srcStep, nm32fcr* pDstVec, int dstStep, NmppsFFTSpec_32fcr* spec)
{
    int i;
    nm32fcr buff128[64], buff128xW[64];
    for(i = 0; i < 64; i++) {
        buff128[i].im = pSrcVec[2 * i*srcStep].im;
        buff128[i].re = pSrcVec[2 * i*srcStep].re;
        buff128xW[i].im = pSrcVec[(2 * i + 1)*srcStep].im;
        buff128xW[i].re = pSrcVec[(2 * i + 1)*srcStep].re;
    }
    nmppsFFT64Fwd_32fcr(buff128, buff128, spec);
    nmppsFFT64Fwd_32fcr(buff128xW, buff128xW, spec);
    for(i = 0; i < 64; i++) {
        pDstVec[i*dstStep].im = buff128[i].im + (spec->Buffers[4][i].re * buff128xW[i].im + spec->Buffers[4][i].im * buff128xW[i].re);
        pDstVec[i*dstStep].re = buff128[i].re + (spec->Buffers[4][i].re * buff128xW[i].re - spec->Buffers[4][i].im * buff128xW[i].im);
        pDstVec[(i + 64)*dstStep].im = buff128[i].im - (spec->Buffers[4][i].re * buff128xW[i].im + spec->Buffers[4][i].im * buff128xW[i].re);
        pDstVec[(i + 64)*dstStep].re = buff128[i].re - (spec->Buffers[4][i].re * buff128xW[i].re - spec->Buffers[4][i].im * buff128xW[i].im);
    }
}
