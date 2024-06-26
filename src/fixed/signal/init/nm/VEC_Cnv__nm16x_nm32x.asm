//------------------------------------------------------------------------
//
//  $Workfile:: Convert16to32.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:08 $
//
//! \if file_doc
//!
//! \file   Convert16to32.asm 
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
    WConvert16to32: long[8] =   ( 1l, 100000000hl, 0l dup 4, 1l, 100000000hl);
end ".data_nmplv";
begin ".text.nmpp"
/////////////////////////////////////////////////////////////////////////////////////////


//! \fn void nmppsConvert_16s32s(nm16s* pSrcVec, nm32s* pDstVec, int nSize)
//!
//! \perfinclude nmppsConvert_16s32s.html

global _nmppsConvert_16s32s:label;
<_nmppsConvert_16s32s>
.branch;
	nb1 = 80000000h;
	goto JumpFromSigned;
		

/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void nmppsConvert_16u32u(nm16u* pSrcVec, nm32u* pDstVec, int nSize)
//!
//! \perfinclude nmppsConvert_16u32u.html

global _nmppsConvert_16u32u:label;
<_nmppsConvert_16u32u>
.branch;
	nb1 = 80008000h;
	<JumpFromSigned>
	ar5 = WConvert16to32 set;
	sb  = 00020002h;
	rep 8 wfifo =[ar5++],ftw;

	ar5 = ar7 - 2;
	push ar0,gr0	with gr0=false;
	push ar5,gr5	with gr0++;
	push ar6,gr6	with gr0++;		//gr0=2

	ar0 = [--ar5]	with gr6=gr0;	// pSrcVec , gr6=2
	ar6 = [--ar5] ;					// pDstVec
	gr5 = [--ar5] ;					// nSize in 8-bit elements 
	gr7 = ar0		with gr5>>=2;
	ar5 = ar6+gr6	with gr6<<=1;	// gr6=4
		
	delayed call core_vsum_data_0;
		wtw;
		ftw;		
		
	ar0 = gr7;
	ar6 = ar5;
	delayed call core_vsum_data_0;
		wtw;
		nul;

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
	return;
.wait;
end ".text.nmpp";
