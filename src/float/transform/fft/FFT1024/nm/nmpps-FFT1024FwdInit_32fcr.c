//***************************************************************************/
//*                     RC Module Inc., Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640x Software                      */
//*                                                                         */
//*   Software design:  A.Brodyazhenko                                      */
//*                                                                         */
//*   File:             nmpps-FFT1024FwdInit_32fcr.c                        */
//*   Contents:         Routine for the struct initialization               */
//*                     of the W-coefficient for FFT1024Fwd                 */
//***************************************************************************/

#include <malloc32.h>
#include <math.h>
#include "fft_32fcr.h"
void nmppsFFT1024FwdInit_32fcr(NmppsFFTSpec_32fcr* spec_32fcr){
	for(int i = 0; i < NUMBUFF1; i++) 
		spec_32fcr->Buffers[i] = 0;
	//for(int i = 4; i < NUMBUFF2; i++) 
	//	spec_32fcr->Buffs[i] = 0;
    
	
    spec_32fcr->Buffers[1]  = spec_32fcr->Buffs[0];         // buff_fft1024
    spec_32fcr->Buffers[0]  = spec_32fcr->Buffs[0] + 512;  // 1.0 or 1/1024

    spec_32fcr->Buffers[11] = spec_32fcr->Buffs[1];      // W1024
    spec_32fcr->Buffers[2]  = spec_32fcr->Buffs[2]; // buff_fft1024mulW

    spec_32fcr->Buffers[3]  = spec_32fcr->Buffs[3];          // W4_16
    spec_32fcr->Buffers[4]  = spec_32fcr->Buffs[3] + 1;      // W2_16
    spec_32fcr->Buffers[5]  = spec_32fcr->Buffs[3] + 2;      // W6_16
    spec_32fcr->Buffers[6]  = spec_32fcr->Buffs[3] + 3;      // W1_16
    spec_32fcr->Buffers[7]  = spec_32fcr->Buffs[3] + 4;      // W3_16
    spec_32fcr->Buffers[8]  = spec_32fcr->Buffs[3] + 5;      // W5_16
    spec_32fcr->Buffers[9]  = spec_32fcr->Buffs[3] + 6;      // W7_16
    spec_32fcr->Buffers[10] = spec_32fcr->Buffs[3] + 7;      // buff_fftxW


/**********************************Fields Fuliling**********************************/
    spec_32fcr->Buffers[0]->im = 0;
    spec_32fcr->Buffers[0]->re = 1.0; // 1.0

    spec_32fcr->Buffers[3]->im = -1.0;                   // W4_16
    spec_32fcr->Buffers[3]->re = -4.3711388286738e-08;  

    spec_32fcr->Buffers[4]->im = -0.70710676908493;      // W2_16  
    spec_32fcr->Buffers[4]->re = 0.70710676908493;

    spec_32fcr->Buffers[5]->im = -0.70710676908493;      // W6_16
    spec_32fcr->Buffers[5]->re = -0.70710676908493;

    spec_32fcr->Buffers[6]->im = -0.38268345594406;      // W1_16
    spec_32fcr->Buffers[6]->re = 0.9238795042038;

    spec_32fcr->Buffers[7]->im = -0.9238795042038;       // W3_16
    spec_32fcr->Buffers[7]->re = 0.38268342614174;

    spec_32fcr->Buffers[8]->im = -0.9238795042038;       // W5_16
    spec_32fcr->Buffers[8]->re = -0.38268342614174;

    spec_32fcr->Buffers[9]->im = -0.38268327713013;      // W7_16
    spec_32fcr->Buffers[9]->re = -0.92387962341309;

/**********************************W1024**********************************/
    for(int i = 0; i < 512; i++) {
        float alpha = (0.006135923151 * (float)i);
        spec_32fcr->Buffers[11][i].im = -sinf(alpha);
        spec_32fcr->Buffers[11][i].re = cosf(alpha);
    }
}

int nmppsFFT1024FwdInitAlloc_32fcr(NmppsFFTSpec_32fcr** spec_32fcr_)
{

    *spec_32fcr_ = (NmppsFFTSpec_32fcr*) malloc(sizeof(NmppsFFTSpec_32fcr));
	NmppsFFTSpec_32fcr* spec_32fcr= *spec_32fcr_;
    if(!spec_32fcr) {
        return 0x1024F;
    }

/*************************************Bank1*************************************/
	nmc_malloc_set_heap(0);
    spec_32fcr->Buffs[0] = (nm32fcr *) malloc((512 + 1) * sizeof(nm32fcr));
    if(!spec_32fcr->Buffs[0])
        return 0x1024F0;

/*************************************Bank2*************************************/
	nmc_malloc_set_heap(1);
    spec_32fcr->Buffs[1] = (nm32fcr *) malloc((512) * sizeof(nm32fcr));
    if(!spec_32fcr->Buffs[1])
        return 0x1024F1;

/*************************************Bank3*************************************/
	nmc_malloc_set_heap(2);
    spec_32fcr->Buffs[2] = (nm32fcr *) malloc(512 * sizeof(nm32fcr));
    if(!spec_32fcr->Buffs[2])
        return 0x1024F2;

/*************************************Bank4*************************************/
	nmc_malloc_set_heap(3);
    spec_32fcr->Buffs[3] = (nm32fcr *) malloc((7 + 512) * sizeof(nm32fcr));
    if(!spec_32fcr->Buffs[3])
        return 0x1024F3;

	nmppsFFT1024FwdInit_32fcr(spec_32fcr);
    return 0;
}