#include "fft_32fcr.h"
//#include <malloc.h>
#include <math.h>

void nmppsFFT128FwdInit_32fcr(NmppsFFTSpec_32fcr* spec_32fcr)
{
    int i, j, k;
    int gr1;
    const float pi = 3.141592653;
    float alpha;
	
	//spec_32fcr->Buffs[0] = (nm32fcr *) malloc((8 + 16 + 32 + 64) * sizeof(nm32fcr));
    //spec_32fcr->Buffs[1] = (nm32fcr *) malloc((32 + 8 + 16 + 32) * sizeof(nm32fcr));
    //spec_32fcr->Buffs[2] = (nm32fcr *) malloc((32 + 64) * sizeof(nm32fcr));
    //spec_32fcr->Buffs[3] = (nm32fcr *) malloc((64) * sizeof(nm32fcr));
    


    //NmppsFFTSpec_32fcr *spec_32fcr = (NmppsFFTSpec_32fcr *) malloc(sizeof(NmppsFFTSpec_32fcr));
    //if(!spec_32fcr) {
    //   return 0x128F;
    //}
    //for(i = 0; i < NUMBUFF1; i++) {
    //    spec_32fcr->Buffers[i] = 0;
    //}
    //spec_32fcr->Buffers[0] = (nm32fcr *) malloc(64 * sizeof(nm32fcr)); // SinCos0
    //if (!spec_32fcr->Buffers[0])
    //    return 0x128F0;
	spec_32fcr->Buffers[0] = spec_32fcr->Buffs[3];
    //spec_32fcr->Buffers[1] = (nm32fcr *) malloc(8 * sizeof(nm32fcr)); // W8
    //if (!spec_32fcr->Buffers[1])
	spec_32fcr->Buffers[1] = spec_32fcr->Buffs[0];
    //    return 0x128F1;
    //spec_32fcr->Buffers[2] = (nm32fcr *) malloc(16 * sizeof(nm32fcr)); // W16
	spec_32fcr->Buffers[2] = spec_32fcr->Buffers[1]+8;
    //if (!spec_32fcr->Buffers[2])
    //    return 0x128F2;
    //spec_32fcr->Buffers[3] = (nm32fcr *) malloc(32 * sizeof(nm32fcr)); // W32
	spec_32fcr->Buffers[3] = spec_32fcr->Buffers[2]+16;
    //if (!spec_32fcr->Buffers[3])
    //    return 0x128F3;
    //spec_32fcr->Buffers[4] = (nm32fcr *) malloc(64 * sizeof(nm32fcr)); // W64
	spec_32fcr->Buffers[4] = spec_32fcr->Buffers[3]+32;
    //if (!spec_32fcr->Buffers[4])
    //    return 0x128F4;
    //*addr = spec_32fcr;
    k = 0;
    for(i = 0; i <  8; i++) {
        for(j = 0; j < 64; j = j + 8) {
            alpha = (2 * pi * (float)i * (float)k) / 8.0;
            spec_32fcr->Buffers[0][i + j].im = -sinf(alpha);
            spec_32fcr->Buffers[0][i + j].re = cosf(alpha);
            k++;
        }
        k = 0;
    }
    for(i = 0; i < 64; i++) {
        alpha = (2 * pi * (float)i) / 128.0;
        spec_32fcr->Buffers[4][i].im = -sinf(alpha);
        spec_32fcr->Buffers[4][i].re = cosf(alpha);
    }
    gr1 = 0;
    for(i = 0; i < 8; i++) {
        spec_32fcr->Buffers[1][i].im = spec_32fcr->Buffers[4][gr1].im;
        spec_32fcr->Buffers[1][i].re = spec_32fcr->Buffers[4][gr1].re;
        gr1 += 8;
    }
    gr1 = 0;
    for(i = 0; i < 16; i++) {
        spec_32fcr->Buffers[2][i].im = spec_32fcr->Buffers[4][gr1].im;
        spec_32fcr->Buffers[2][i].re = spec_32fcr->Buffers[4][gr1].re;
        gr1 += 4;
    }
    gr1 = 0;
    for(i = 0; i < 32; i++) {
        spec_32fcr->Buffers[3][i].im = spec_32fcr->Buffers[4][gr1].im;
        spec_32fcr->Buffers[3][i].re = spec_32fcr->Buffers[4][gr1].re;
        gr1 += 2;
    }
	spec_32fcr->dstStep=2;
    return 0;
}
