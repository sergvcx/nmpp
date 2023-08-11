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

extern _VEC_TBL_Diagonal_FFh_G:long;
extern core_Abs:label;

begin ".text.nmpp"


//! \fn void nmppsAbs_8s(nm8s *pSrcVec, nm8s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsAbs_nm8s.html

global _nmppsAbs_8s:label;
<_nmppsAbs_8s>
.branch;
	ar5 = ar7 - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
	
	sb	= 02020202h	with gr0++;
	nb1 = 80808080h	with gr6=gr0;
	ar6 = _VEC_TBL_Diagonal_FFh_G;
	rep 8 wfifo=[ar6++],ftw;
	
	ar0 = [--ar5];	// pSrcVec
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize
	
	f1cr= 80808080h;   				
	delayed call  core_Abs with gr5>>=3;	// nSize in 64-bit longs
		wtw;	
		nul;

	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;
end ".text.nmpp";
