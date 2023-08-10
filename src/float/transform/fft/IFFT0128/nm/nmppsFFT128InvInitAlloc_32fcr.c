//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640x Software                      */
//*                                                                         */
//*   Software design:  A.Brodyazhenko                                      */
//*                                                                         */
//*   File:             nmpps-FFT128InvInit_32fcr.c                         */
//*   Contents:         Routine for the struct initialization               */
//*                     of the W-coefficients for FFT128Inv                 */
//***************************************************************************/

#include <malloc32.h>
#include <math.h>
#include "fft_32fcr.h"

int nmppsFFT128InvInitAlloc_32fcr(NmppsFFTSpec_32fcr** spec_32fcr_)
{
    int i, j, k;
    //int gr1;
    //const float pi = 3.141592653;
    //float alpha;
    //nm32fcr *SinCos = (nm32fcr *) malloc0(64 * sizeof(nm32fcr));
	nmc_malloc_set_heap(0);
    *spec_32fcr_ = (NmppsFFTSpec_32fcr *) malloc(sizeof(NmppsFFTSpec_32fcr));
	NmppsFFTSpec_32fcr * spec_32fcr = *spec_32fcr_;
    if(!spec_32fcr) {
        return 0x128B;
    }
    for(i = 0; i < NUMBUFF2; i++) {
        spec_32fcr->Buffs[i] = 0;
    }
    nmc_malloc_set_heap(0);
	spec_32fcr->Buffs[0] = (nm32fcr *) malloc((8 + 16 + 32 + 64) * sizeof(nm32fcr));
    if(!spec_32fcr->Buffs[0])
        return 0x128B0;

    //spec_32fcr->Buffers[4] = spec_32fcr->Buffs[0];            // W8_0
    //spec_32fcr->Buffers[6] = spec_32fcr->Buffs[0] + 8;       // W16_0
    //spec_32fcr->Buffers[8] = spec_32fcr->Buffs[0] + 24;    // W32_0
    //spec_32fcr->Buffers[10] = spec_32fcr->Buffs[0] + 56;   // W64_0

	nmc_malloc_set_heap(1);
    spec_32fcr->Buffs[1] = (nm32fcr *) malloc((32 + 8 + 16 + 32) * sizeof(nm32fcr));
    if(!spec_32fcr->Buffs[0])
        return 0x128B1;

    //spec_32fcr->Buffers[1] = spec_32fcr->Buffs[1];            // SinCos1
    //spec_32fcr->Buffers[5] = spec_32fcr->Buffs[1] + 32;      // W8_1
    //spec_32fcr->Buffers[7] = spec_32fcr->Buffs[1] + 40;     // W16_1
    //spec_32fcr->Buffers[9] = spec_32fcr->Buffs[1] + 56;   // W32_1

	nmc_malloc_set_heap(2);
    spec_32fcr->Buffs[2] = (nm32fcr *) malloc((32 + 64) * sizeof(nm32fcr));
    if(!spec_32fcr->Buffs[0])
        return 0x128B2;

    //spec_32fcr->Buffers[0] = spec_32fcr->Buffs[2];         // SinCos0
    //spec_32fcr->Buffers[2] = spec_32fcr->Buffs[2] + 32;   // buff_fft

	nmc_malloc_set_heap(3);
    spec_32fcr->Buffs[3] = (nm32fcr *) malloc3((64) * sizeof(nm32fcr));
    if(!spec_32fcr->Buffs[3])
        return 0x128B3;

    //spec_32fcr->Buffers[3] = spec_32fcr->Buffs[3];       // buff_fftxW
    
    //*addr = spec_32fcr;
    //k = 0;
    //for(i = 0; i <  8; i++) {
    //    for(j = 0; j < 64; j = j + 8) {
    //        alpha = (2 * pi * (float)i * (float)k) / 8.0;
    //        SinCos[i + j].im = sinf(alpha) * 0.0078125; // 1/128 = 0.0078125
    //        SinCos[i + j].re = cosf(alpha) * 0.0078125;
    //        k++;
    //    }
    //    k = 0;
    //}
    //for(i = 0; i < 32; i++) {
    //    spec_32fcr->Buffers[0][i].im = SinCos[i].im;
    //    spec_32fcr->Buffers[0][i].re = SinCos[i].re;
    //    spec_32fcr->Buffers[1][i].im = SinCos[i + 32].im;
    //    spec_32fcr->Buffers[1][i].re = SinCos[i + 32].re;
    //}
    //for(i = 0; i < 64; i++) {
    //    alpha = (0.04908738521 * (float)i);
    //    spec_32fcr->Buffers[10][i].im = sinf(alpha);
    //    spec_32fcr->Buffers[10][i].re = cosf(alpha);
    //}
    //gr1 = 0;
    //for(i = 0; i < 8; i++) {
    //    spec_32fcr->Buffers[4][i].im = spec_32fcr->Buffers[10][gr1].im;
    //    spec_32fcr->Buffers[4][i].re = spec_32fcr->Buffers[10][gr1].re;
    //    spec_32fcr->Buffers[5][i].im = spec_32fcr->Buffers[10][gr1].im;
    //    spec_32fcr->Buffers[5][i].re = spec_32fcr->Buffers[10][gr1].re;
    //    gr1 += 8;
    //}
    //gr1 = 0;
    //for(i = 0; i < 16; i++) {
    //    spec_32fcr->Buffers[6][i].im = spec_32fcr->Buffers[10][gr1].im;
    //    spec_32fcr->Buffers[6][i].re = spec_32fcr->Buffers[10][gr1].re;
    //    spec_32fcr->Buffers[7][i].im = spec_32fcr->Buffers[10][gr1].im;
    //    spec_32fcr->Buffers[7][i].re = spec_32fcr->Buffers[10][gr1].re;
    //    gr1 += 4;
    //}
    //gr1 = 0;
    //for(i = 0; i < 32; i++) {
    //    spec_32fcr->Buffers[8][i].im = spec_32fcr->Buffers[10][gr1].im;
    //    spec_32fcr->Buffers[8][i].re = spec_32fcr->Buffers[10][gr1].re;
    //    spec_32fcr->Buffers[9][i].im = spec_32fcr->Buffers[10][gr1].im;
    //    spec_32fcr->Buffers[9][i].re = spec_32fcr->Buffers[10][gr1].re;
    //    gr1 += 2;
    //}
    //free(SinCos);
	nmppsFFT128InvInit_32fcr(spec_32fcr);
    return 0;
}