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

extern _VEC_TBL_MinusOne_G:long;
extern core_Abs:label;

begin ".text_nmplv"




/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void nmppsAbs_64s(nm64s *pSrcVec, nm64s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsAbs_64s.html

global _nmppsAbs_64s:label;

<_nmppsAbs_64s>
.branch;
	ar5 = ar7 - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
	
	sb	= 00000000h	with gr0++;
	nb1 = 00000000h	with gr6=gr0;
	ar6 = _VEC_TBL_MinusOne_G;
	rep 1 wfifo=[ar6++],ftw;
	
	ar0 = [--ar5];	// pSrcVec
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize
	//wtw;
						
	f1crl= 00000000h;   
	f1crh= 80000000h;
	delayed call  core_Abs with gr5;	// nSize in 64-bit longs
		wtw;
		nul;

	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;

end ".text_nmplv";
