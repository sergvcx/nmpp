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

extern core_activate_data_xor_data:label;

begin ".text_nmplv"


/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void nmppsAbs1 (nm32s *pSrcVec, nm32s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsAbs1_32s.html

global _nmppsAbs1_32s:label;
<_nmppsAbs1_32s>
.branch;
	ar5 = ar7 - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
	
	ar0 = [--ar5]	with gr0++;		// pSrcVec
	ar6 = [--ar5]	with gr6=gr0;	// pDstVec
	gr5 = [--ar5];	// nSize
		
	f1cr= 80000000h;   		
	call  core_activate_data_xor_data with gr5>>=1;	// nSize in 64-bit longs
		

	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;


end ".text_nmplv";
