//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640x Software                      */
//*                                                                         */
//*   Software design:  A.Brodyazhenko                                      */
//*                                                                         */
//*   File:             nmpps-FFT1024Inv_32fcr.c                            */
//*   Contents:         Routine for inverse FFT 1024                        */
//*                     of complex array with 32 bit elements				*/
//***************************************************************************/

#include "nmpp/fft_32fcr.h"
#include <malloc.h>

void nmppsFFT1024Inv_32fcr(const nm32fcr* pSrcVec, nm32fcr* pDstVec, NmppsFFTSpec_32fcr* spec)
{
	nmppsFFT1024Fwd_32fcr(pSrcVec, pDstVec, spec);
}
