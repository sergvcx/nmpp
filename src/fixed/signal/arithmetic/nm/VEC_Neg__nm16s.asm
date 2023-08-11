//------------------------------------------------------------------------
//
//  $Workfile:: Neg_8s $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   Neg_8s.Asm
//! \author S.Mushkaev
//! \brief  Изменение знака элементов вектора на противоположный.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vArithm.h"


extern core_0_sub_data:label;

begin ".text.nmpp"


/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void nmppsNeg (nm16s *pSrcVec, nm16s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsNeg_16s.html

global _nmppsNeg_16s:label;
<_nmppsNeg_16s>
.branch;
	ar5 = ar7 - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
	
	
	nb1 = 80008000h	with gr0++;
	
	ar0 = [--ar5];				// pSrcVec
	ar6 = [--ar5]with gr6=gr0;	// pDstVec
	gr5 = [--ar5];				// nSize
						
	delayed call  core_0_sub_data with gr5>>=2;	// nSize in 64-bit longs
		wtw;
		nul;
		
	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;

end ".text.nmpp";
