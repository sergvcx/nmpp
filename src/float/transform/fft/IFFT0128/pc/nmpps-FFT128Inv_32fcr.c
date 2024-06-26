//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640x Software                      */
//*                                                                         */
//*   Software design:  A.Brodyazhenko                                      */
//*                                                                         */
//*   File:             nmpps-FFT128Inv_32fcr.c                             */
//*   Contents:         Routine for inverse FFT 128                         */
//*                     of complex array with 32 bit elements				*/
//***************************************************************************/

#include "nmpp/fft_32fcr.h"

void nmppsFFT128Inv_32fcr(const nm32fcr* pSrcVec, int srcStep,  nm32fcr* pDstVec, int dstStep, NmppsFFTSpec_32fcr* spec)
{
	nmppsFFT128Fwd_32fcr(pSrcVec, srcStep, pDstVec, dstStep, spec);
}
