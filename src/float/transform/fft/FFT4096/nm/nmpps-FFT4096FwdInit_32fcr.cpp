//***************************************************************************/
//*                     RC Module Inc., Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640x Software                      */
//*                                                                         */
//*   Software design:  A.Brodyazhenko                                      */
//*                                                                         */
//*   File:             nmpps-FFT4096FwdInit_32fcr.c                        */
//*   Contents:         Routine for the struct initialization               */
//*                     of the W-coefficients for FFT2048Fwd                */
//***************************************************************************/

#include "math.h"
#include "nmpp.h"
#include "malloc32.h"
#include "fft_32fcr.h"
extern "C" {
	
void nmppsFFT4096FwdInit_32fcr(NmppsFFTSpec_32fcr* spec_32fcr)
{
	//for(int i = 0; i < NUMBUFF1; i++) 
	//	spec_32fcr->Buffers[i] = 0;

    const float pi = 3.141592653;

    
	nmppsFFT2048FwdInit_32fcr(spec_32fcr);
	
	spec_32fcr->Buffers[12] = spec_32fcr->Buffs[4];
    spec_32fcr->Buffers[13] = spec_32fcr->Buffs[5];
    spec_32fcr->Buffers[14] = spec_32fcr->Buffs[6];
    spec_32fcr->Buffers[15] = spec_32fcr->Buffs[7];
    
    for(int i = 0; i < 2048; i++) {
        float alpha = (2.0 * pi * (float)i) / 4096.0;
        spec_32fcr->Buffers[15][i].im = -sinf(alpha);
        spec_32fcr->Buffers[15][i].re = cosf(alpha);
    }
}
	
int nmppsFFT4096FwdInitAlloc_32fcr(NmppsFFTSpec_32fcr** spec_32fcr_)
{
    

    int status = nmppsFFT2048FwdInitAlloc_32fcr(spec_32fcr_);
    if(status) return 0x4096F0;

	NmppsFFTSpec_32fcr *spec_32fcr=*spec_32fcr_;

	nmc_malloc_set_heap(0);
    spec_32fcr->Buffs[4] = (nm32fcr *) malloc((2048) * sizeof(nm32fcr)); // buff_fft4096
    if(!spec_32fcr->Buffs[4])
        return 0x4096F1;

	nmc_malloc_set_heap(1);
	spec_32fcr->Buffs[5] = (nm32fcr *) malloc((2048) * sizeof(nm32fcr)); // buff_fft4096xW
    if(!spec_32fcr->Buffs[5])
        return 0x4096F2;

	nmc_malloc_set_heap(2);
    spec_32fcr->Buffs[6] = (nm32fcr *) malloc((2048) * sizeof(nm32fcr)); // buff_fft4096_addi
    if(!spec_32fcr->Buffers[6])
        return 0x4096F3;

	nmc_malloc_set_heap(3);
	spec_32fcr->Buffs[7] = (nm32fcr *) malloc((2048) * sizeof(nm32fcr)); // W4096
    if(!spec_32fcr->Buffs[7])
        return 0x4096F4;

    nmppsFFT4096FwdInit_32fcr(spec_32fcr);

    return 0;
}

};