#include "fft_32fcr.h"
#include <malloc.h>

void nmppsFFT4096Inv_32fcr(const nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fcr *ispec)
{
    nmppsFFT4096Fwd_32fcr(ix, iX, ispec);
}
