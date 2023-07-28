//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640X Software                      */
//*                                                                         */
//*   Fast Fourie Transform Library                                         */
//*   (C-callable functions)                                                */
//*                                                                         */
//*   File:             FFT3.asm                                            */
//*   Contents:         Routine for forward FFT 32 of complex array         */
//*                     with 32 bit elements                                */
//*                                                                         */
//*   Software design:  S.Mushkaev                                          */
//*                                                                         */
//*                                                                         */
//***************************************************************************/

    //--------------------------------------------------------------------
    //! \fn int nmppsFFT32FwdRaw(nm32sc*	src, nm32sc*	dst, NmppsFFTSpec*	spec)
	//!
	//! \perfinclude nmppsFFT32FwdRaw.html
    //--------------------------------------------------------------------




data ".data_fft_L"

	GAddCmplxMask:long[2]=(
		0000000100000000hl,
		00000000FFFFFFFFhl);
		

	core_tbl_sb_nb_w_int_RightShift7:long[8]=(
			1000000000000000000000001000001010000000000000000000000010000010bl,	// sb 7
			1111111110000000000000000000000011111111100000000000000000000000bl,	// nb 7
			
			0000000000000000hl,	// ShiftR 7
			0000000000000001hl,
			00000000FF000000hl,
			0000000000000000hl,
			0000000100000000hl,
		   0FF00000000000000hl);

end ".data_fft_L";


begin ".text_fft"


//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//  Main Forward FFT-32 procedure                                          //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//
// total  instructions = 442 ticks
// scalar instructions = 192 ticks
// vector instructions = 442-192 = 250 ticks
//
// Data-flow scheme 
//[ar0:lo]+[ar0:hi] -> [ar1:lo]
//[ar0:lo]-[ar0:hi] -> [ar2:lo]
//                     [ar1:lo]*[ar4:re]->[ar2:hi]
//                     [ar1:lo]*[ar4:im]->[ar1:hi]
//                     [ar2:lo]*[ar4:re]->[ar1:lo]
//                     [ar2:lo]*[ar4:im]->[ar2:lo]					              
//                                        [ar1:lo]|[ar2:lo]->[ar6:odd ]
//                                        [ar1:hi]|[ar2:hi]->[ar6:even]
//                           
global _nmppsFFT128Fwd288:label;             
global _nmppsFFT128Fwd:label;
<_nmppsFFT128Fwd>
.branch;
	ar5=ar7 - 2	 with gr7=false;
	push ar0,gr0 with gr7++;			
	push ar1,gr1 with gr7++;		
	push ar2,gr2;		
	push ar4,gr4; 
	push ar6,gr6 with gr6=gr7;			// gr6=2
	ar0 = [--ar5];						// src[32*2]
	gr1 = [--ar5];						// dst[32*2]
	ar5 = [--ar5];						// spec
	ar6 = [ar5++];						// tmp[32*2]
	gr2 = [ar5++];						// tmp[32*2]
	ar4 = [ar5++];						// weights[16*2*2]
	gr7 = ar6;							
	//--------------------------------------------------------
	ar1 = gr1;	// ar1=[ar1:lo]
	nb1 = 80000000h;
	sb  = 02020202h;
	vr  = 64;
	ar2 = gr2;	// ar2=[ar2:lo]
	rep 16 ram =[ar0++],wtw;							// stage[0] X[0..255]  
	ar5 = ar0;
	rep 16 data=[ar0++] with ram+data;					// stage[1] S[0..255]=X[0..255]+X[256..511]
	rep 16 [ar1++]=afifo;								// stage[1]		
	rep 16 data=[ar5++] with ram-data;					// stage[2] S[256..511]=X[0..255]-X[256..511] 
	rep 16 [ar2++]=afifo; 								// stage[2] 
	//--------------------------------------------------------
	gr4 = ar2; 	// gr4=[ar2:hi]
	ar1 = gr1;	// in :ar1=[ar1:lo]
				// out:ar2=[ar2:hi]
	// (+) * W.re
	rep 16 wfifo=[ar1++] ,ftw,wtw;							// stage[2]
	rep 16 data =[ar4++] ,ftw,wtw 	with vsum ,data,vr;		// stage[3]
	rep 16 data =[ar4++] 		 	with vsum ,data,afifo;	// stage[4]
	rep 16 [ar2++]=afifo;									// stage[4] W.Re*X[0..15]
	
	// (+) * W.Im
	ar1 = gr1; 	// in :ar1=[ar1:lo]
				// out:ar1=[ar1:hi]
	rep 16 wfifo=[ar1++],ftw,wtw;							// stage[4]
	rep 16 data =[ar4++],ftw,wtw  	with vsum ,data,0;		// stage[5]
	rep 16 data =[ar4++]		  	with vsum ,data,afifo;	// stage[6]
	rep 16 [ar1++]=afifo;									// stage[6] W.Re*X[0..15]
		
	ar2 = gr2;	// in :ar2=[ar2:lo]
	ar1 = gr1;	// out:ar1=[ar1:lo]
	// (-) * W.re
	rep 16 wfifo=[ar2++],ftw,wtw;							// stage[6]
	rep 16 data =[ar4++],ftw,wtw  	with vsum ,data,vr;		// stage[7]
	rep 16 data =[ar4++]		  	with vsum ,data,afifo;	// stage[8]
	rep 16 [ar1++]=afifo;									// stage[8] W.Re*X[16..31]
	
	ar2 = gr2;	// in :ar2=[ar2:lo]
	ar5 = gr2;	// out:ar5=[ar2:lo]
	// (-) * W.im
	rep 16 wfifo=[ar2++],ftw,wtw;							// stage[8]
	rep 16 data =[ar4++],ftw,wtw  	with vsum ,data,0;		// stage[9]
	rep 16 data =[ar4++]			with vsum ,data,afifo;	// stage[10]
	rep 16 [ar5++]=afifo;									// stage[10] W.Im*X[16..31]
	
	//---- complex conjugation sum --------------------------------------------------------
	sb  = gr6; 							// sb=00000002h;
	ar1 = gr1;							// ar1=[ar1:lo]
	ar2 = gr2 		with gr4 = gr6<<1;	// ar2=[ar2:lo]
	ar4 = ar6+gr6 	with gr6 = gr6<<1;
	ar0 = GAddCmplxMask;
	rep 2  wfifo=[ar0++],ftw,wtw;							// stage[10]
	 
	// 480-422-390
	rep 16 ram =[ar1++];									// stage[11]
	rep 16 data=[ar2++] ,wtw with vsum ,data,ram;			// stage[11]
	rep 16 [ar4++gr4]=afifo;								// stage[11]
	rep 16 ram =[ar2++];									// stage[12]
	rep 16 data=[ar1++]  	with vsum ,data,ram;			// stage[12]
	rep 16 [ar6++gr6]=afifo;								// stage[12]
	
	//----------- normalization (right shift 7)---------------------
	
	ar6 = gr7;
	ar1 = gr1;
	ar0 = core_tbl_sb_nb_w_int_RightShift7;
	sb  = [ar0++];
	nb1 = [ar0++];	
	rep 6  wfifo=[ar0++],ftw,wtw;
	rep 32 data=[ar6++] with vsum ,shift data,0;			// stage[13]
	rep 32 [ar1++]=afifo;
	
	pop ar6,gr6;
	pop ar4,gr4;
	pop ar2,gr2;
	pop ar1,gr1;
	pop ar0,gr0;
return with gr7=false;
.wait;



	
end ".text_fft";