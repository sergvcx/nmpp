//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM6403 Software                      */
//*                                                                         */
//*   Fast Fourie Transform Library                                         */
//*   (C-callable functions)                                                */
//*                                                                         */
//*   File:             FFT2048.asm                                         */
//*   Contents:         Routine for forward FFT 2048 of complex array       */
//*                     with 32 bit elements                                */
//*                                                                         */
//*   Software design:  S.Mushkaev                                          */
//*                                                                         */
//*   Version           1.2                                                 */
//*   Start date:       03.07.2000                                          */
//*   Release   $Date: 2005/02/10 11:47:59 $*/
//*                                                                         */
//*                                                                         */
//***************************************************************************/
extern W1_2048_7bit	:long;
extern W2_2048_7bit	:long;
extern W1_2048_6bit	:long;
extern W2_2048_6bit	:long;

extern W1_2048:word;
extern W2_2048:word;
extern DefaultShiftR_2048:word;		

begin ".text_fft"
    //--------------------------------------------------------------------
    //! \fn void FFT_Fwd2048Set6bit()
	//!
	//! \n
    //--------------------------------------------------------------------
global _FFT_Fwd2048Set6bit:label;
<_FFT_Fwd2048Set6bit>
.branch;
	ar5=ar7 - 2;
				gr7 = W1_2048_6bit;
	[W1_2048] = gr7;
				gr7 = W2_2048_6bit;
	[W2_2048] = gr7;
				gr7 = 12;			
	delayed return;
		[DefaultShiftR_2048] = gr7;		
		nul;
.wait;


end ".text_fft";
