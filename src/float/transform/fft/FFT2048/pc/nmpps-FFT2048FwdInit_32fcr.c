//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640x Software                      */
//*                                                                         */
//*   Software design:  A.Brodyazhenko                                      */
//*                                                                         */
//*   File:             nmpps-FFT2048FwdInit_32fcr.c                        */
//*   Contents:         Routine for the struct initialization               */
//*                     of the W-coefficient for FFT2048Fwd                 */
//***************************************************************************/

#include "nmpp/fft_32fcr.h"
#include <malloc.h>
#include <math.h>


void nmppsFFT2048FwdInit_32fcr(NmppsFFTSpec_32fcr* spec_32fcr)
{
	for(int i = 8; i < NUMBUFF1; i++) 
		spec_32fcr->Buffers[i] = 0;
    int i, j, k;
    int gr1;
    const float pi = 3.141592653;
    float alpha;
   
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
    for(i = 0; i < 1024; i++) {
        alpha = (2.0 * pi * (float)i) / 2048.0;
        spec_32fcr->Buffers[8][i].im = -sinf(alpha);
        spec_32fcr->Buffers[8][i].re = cosf(alpha);
    }
    gr1 = 0;
    for(i = 0; i < 8; i++) {
        spec_32fcr->Buffers[1][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[1][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 128;
    }
    gr1 = 0;
    for(i = 0; i < 16; i++) {
        spec_32fcr->Buffers[2][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[2][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 64;
    }
    gr1 = 0;
    for(i = 0; i < 32; i++) {
        spec_32fcr->Buffers[3][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[3][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 32;
    }
    gr1 = 0;
    for(i = 0; i < 64; i++) {
        spec_32fcr->Buffers[4][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[4][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 16;
    }
    gr1 = 0;
    for(i = 0; i < 128; i++) {
        spec_32fcr->Buffers[5][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[5][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 8;
    }
    gr1 = 0;
    for(i = 0; i < 256; i++) {
        spec_32fcr->Buffers[6][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[6][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 4;
    }
    gr1 = 0;
    for(i = 0; i < 512; i++) {
        spec_32fcr->Buffers[7][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[7][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 2;
    }
	spec_32fcr->dstStep=2;
    return 0;
}


int nmppsFFT2048FwdInitAlloc_32fcr(NmppsFFTSpec_32fcr** spec_32fcr_)
{
    int i, j, k;
    //int gr1;
    //const float pi = 3.141592653;
    //float alpha;
	//*addr = spec_32fcr;
    *spec_32fcr_ = (NmppsFFTSpec_32fcr*) malloc(sizeof(NmppsFFTSpec_32fcr));
    NmppsFFTSpec_32fcr *spec_32fcr=*spec_32fcr_;
	if(!spec_32fcr) {
        return 0x4096F;
    }
    for(i = 0; i < NUMBUFF1; i++) {
        spec_32fcr->Buffers[i] = 0;
    }
    spec_32fcr->Buffers[0] = (nm32fcr *) malloc(64 * sizeof(nm32fcr)); // SinCos0
    if (!spec_32fcr->Buffers[0])
        return 0x4096F0;
    spec_32fcr->Buffers[1] = (nm32fcr *) malloc(8 * sizeof(nm32fcr)); // W8
    if (!spec_32fcr->Buffers[1])
        return 0x4096F1;
    spec_32fcr->Buffers[2] = (nm32fcr *) malloc(16 * sizeof(nm32fcr)); // W16
    if (!spec_32fcr->Buffers[2])
        return 0x4096F2;
    spec_32fcr->Buffers[3] = (nm32fcr *) malloc(32 * sizeof(nm32fcr)); // W32
    if (!spec_32fcr->Buffers[3])
        return 0x4096F3;
    spec_32fcr->Buffers[4] = (nm32fcr *) malloc(64 * sizeof(nm32fcr)); // W64
    if (!spec_32fcr->Buffers[4])
        return 0x4096F4;
    spec_32fcr->Buffers[5] = (nm32fcr *) malloc(128 * sizeof(nm32fcr)); // W128
    if (!spec_32fcr->Buffers[5])
        return 0x4096F5;
    spec_32fcr->Buffers[6] = (nm32fcr *) malloc(256 * sizeof(nm32fcr)); // W256
    if (!spec_32fcr->Buffers[6])
        return 0x4096F6;
    spec_32fcr->Buffers[7] = (nm32fcr *) malloc(512 * sizeof(nm32fcr)); // W512
    if (!spec_32fcr->Buffers[7])
        return 0x4096F7;
    spec_32fcr->Buffers[8] = (nm32fcr *) malloc(1024 * sizeof(nm32fcr)); // W1024
    if (!spec_32fcr->Buffers[8])
        return 0x4096F8;
	nmppsFFT2048FwdInit_32fcr(spec_32fcr);
    
	
    /*
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
    for(i = 0; i < 1024; i++) {
        alpha = (2.0 * pi * (float)i) / 2048.0;
        spec_32fcr->Buffers[8][i].im = -sinf(alpha);
        spec_32fcr->Buffers[8][i].re = cosf(alpha);
    }
    gr1 = 0;
    for(i = 0; i < 8; i++) {
        spec_32fcr->Buffers[1][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[1][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 128;
    }
    gr1 = 0;
    for(i = 0; i < 16; i++) {
        spec_32fcr->Buffers[2][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[2][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 64;
    }
    gr1 = 0;
    for(i = 0; i < 32; i++) {
        spec_32fcr->Buffers[3][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[3][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 32;
    }
    gr1 = 0;
    for(i = 0; i < 64; i++) {
        spec_32fcr->Buffers[4][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[4][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 16;
    }
    gr1 = 0;
    for(i = 0; i < 128; i++) {
        spec_32fcr->Buffers[5][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[5][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 8;
    }
    gr1 = 0;
    for(i = 0; i < 256; i++) {
        spec_32fcr->Buffers[6][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[6][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 4;
    }
    gr1 = 0;
    for(i = 0; i < 512; i++) {
        spec_32fcr->Buffers[7][i].im = spec_32fcr->Buffers[8][gr1].im;
        spec_32fcr->Buffers[7][i].re = spec_32fcr->Buffers[8][gr1].re;
        gr1 += 2;
    }
	*/
	
    return 0;
}
