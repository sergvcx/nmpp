//------------------------------------------------------------------------
//
//  $Workfile:: Convert16to64.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:08 $
//
//! \if file_doc
//!
//! \file   Convert16to64.asm
//! \author S.Mushkaev 
//! \brief  Функции преобразования элементов вектора.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vConvert.h"

import from "nmpp/macros.mlb";
extern core_vsum_data_0:label;
data ".data_nmplv"
    WConvert16to64: long[4*4] =  (			1hl, 0hl dup 3,	// Extract 1-st byte
								 0hl	  ,	1hl, 0hl dup 2,	// Extract 2-rd byte
								 0hl dup 2,	1hl, 0hl	  ,	// Extract 3-rd byte
								 0hl dup 3,	1hl				// Extract 4-rd byte
								 );
end ".data_nmplv";
begin ".text.nmpp"
/////////////////////////////////////////////////////////////////////////////////////////


//! \fn void nmppsConvert_16s64s(nm16s* pSrcVec, nm64s* pDstVec, int nSize)
//!
//! \perfinclude nmppsConvert_16s64s.html

global _nmppsConvert_16s64s:label;
<_nmppsConvert_16s64s>
.branch;
	nb1 = 00000000h;
	goto JumpFromSigned;
		

/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void nmppsConvert_16u(nm16u* pSrcVec, nm64u* pDstVec, int nSize)
//!
//! \perfinclude _nmppsConvert_16u.html

global _nmppsConvert_16u64u:label;
<_nmppsConvert_16u64u>
.branch;
	nb1 = 80008000h;
	<JumpFromSigned>
	ar5 = WConvert16to64;
	sb  = 00020002h;
	rep 16 wfifo =[ar5++],ftw;

	ar5 = ar7 - 2;
	push ar0,gr0	with gr0=false;
	push ar5,gr5	with gr0++;
	push ar6,gr6	with gr0++;		//gr0=2

	ar0 = [--ar5]	with gr6=gr0;	// pSrcVec , gr6=2
	ar6 = [--ar5] ;					// pDstVec
	gr5 = [--ar5] ;					// nSize in 8-bit elements 
	gr7 = ar0		with gr5>>=2;
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


	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
	return;
.wait;
end ".text.nmpp";
