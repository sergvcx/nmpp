//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM6403 Software                      */
//*                                                                         */
//*   Vector Processing  Library                                            */
//*   (C-callable functions)                                                */
//*                                                                         */
//*   $Workfile:: Prod16.asm                                               $*/
//*                                                                         */
//*   Contents:        Shift routines                                       */
//*                                                                         */
//*   Software design: Lukashevich Pavel                                    */
//*                                                                         */
//*   Version          1.0                                                  */
//*   Start date:      17.0.2002                                            */
//*   Release  $Date: 2004/11/22 13:50:11 $*/
//*                                                                         */
//*                                                                         */
//***************************************************************************/
//#include "vProd.h"

import from "nmpp/macros.mlb";
extern core_vsum_data_0:label;

data ".data_nmplv_G"

    WConvert16to64: long[4*4] =  (			1hl, 0hl dup 3,	// Extract 1-st byte
								 0hl	  ,	1hl, 0hl dup 2,	// Extract 2-rd byte
								 0hl dup 2,	1hl, 0hl	  ,	// Extract 3-rd byte
								 0hl dup 3,	1hl				// Extract 4-rd byte
								 );
								
end ".data_nmplv_G";

begin ".text.nmpp"
.branch;


//! \fn void nmppsDotProd_8s16s (nm8s *pSrcVec1, nm16s *pSrcVec2, int nSize, int64b *pnRes, void* pTmpBuff) 
//!
//! \perfinclude nmppsDotProd_8s16s.html

global _nmppsDotProd_8s16s:label;
<_nmppsDotProd_8s16s>
	ar5 = ar7 - 2;

	PUSH_REGS();

	gr2 = [--ar5];	// Input0 buffer
	ar0 = [--ar5];	// Input1 buffer
	gr1 = [--ar5];	// V0,V1 vectors Size
	gr3 = [--ar5];	// Output buffer 
	ar6 = [--ar5];	// Temporary buffer 

	push ar6,gr6;
	//Convert to 64 bit
	ar5 = WConvert16to64;

	sb  = 00020002h;
	nb1 = 00000000h;
	rep 16 wfifo =[ar5++],ftw;

	gr0 = 2;
	gr6 = gr0;	//gr6=2
	gr7 = ar0		with gr5 = gr1>>2;
	ar5 = ar6+gr6	with gr6<<=2;	// gr6=8
		
	delayed call core_vsum_data_0;
		wtw;
		ftw;		
				
	ar6 = ar5		with gr6>>=2;	// gr6=2
	ar5 = ar6+gr6	with gr6<<=2;	// gr6=8
	ar0 = gr7;
	delayed call core_vsum_data_0;
		wtw;
		ftw;
		
	ar6 = ar5		with gr6>>=2;	// gr6=2
	ar5 = ar6+gr6	with gr6<<=2;	// gr6=8
	ar0 = gr7;
	delayed call core_vsum_data_0;
		wtw;
		ftw;

	ar6 = ar5		with gr6>>=2;	// gr6=2
	ar5 = ar6+gr6	with gr6<<=2;	// gr6=8
	delayed call core_vsum_data_0;
		ar0 = gr7;
		wtw;

	//	ar0 =  Input0 buffer
	//	ar4 =  Input1 buffer
	//	ar6 =  Output buffer 
	//	gr6 =  V0,V1 vectors Size
	pop ar6,gr6;
	ar0 = gr2;
	ar4 = ar6;
	ar6 = gr3;
	gr6 = gr1;


	//Calculate Product of two vectors
	sb	= 02020202h;
	gr7 = 00000000h;
	nb1 = gr7 with gr6>>=3;


	rep 8 wfifo=[ar4++],ftw;
	.wait;
		nb1 = gr7 with gr6--;
		rep 1 wtw with vfalse;
	.branch;

<NextMul08>
	if > delayed goto NextMul08 with gr6--;
		rep 1 data=[ar0++] with vsum, data,afifo;
		rep 8 wfifo=[ar4++],ftw,wtw;
	
	rep 1 [ar6] = afifo;

	POP_REGS();

return;

.wait;
end ".text.nmpp"; 
