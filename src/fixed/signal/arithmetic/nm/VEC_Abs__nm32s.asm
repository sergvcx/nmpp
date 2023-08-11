//------------------------------------------------------------------------
//
//  $Workfile:: Abs.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   Abs.Asm
//! \author S.Mushkaev
//! \brief  Абсолютное значение элементов вектора.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vArithm.h"

extern _VEC_TBL_Diagonal_FFFFFFFFh_G:long;
extern core_Abs:label;

begin ".text.nmpp"


//! \fn void nmppsAbs_32s(nm32s *pSrcVec, nm32s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsAbs_32s.html

global _nmppsAbs_32s:label;
<_nmppsAbs_32s>
.branch;
	ar5 = ar7 - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
	
	sb	= 00000002h	with gr0++;
	nb1 = 80000000h	with gr6=gr0;
	ar6 = _VEC_TBL_Diagonal_FFFFFFFFh_G;
	rep 2 wfifo=[ar6++],ftw;
	
	ar0 = [--ar5];	// pSrcVec
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize
		
	f1cr= 80000000h;   		
	delayed call  core_Abs with gr5>>=1;	// nSize in 64-bit longs
		wtw;
		nul;
	

	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;


end ".text.nmpp";
