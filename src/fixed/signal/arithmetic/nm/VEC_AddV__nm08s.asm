//------------------------------------------------------------------------
//
//  $Workfile:: Add.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   Add.Asm
//! \author S.Mushkaev
//! \brief  Функции суммирования для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vArithm.h"



extern core_Add:label;
begin ".text.nmpp"


/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void nmppsAdd (nm8s *pSrcVec1, nm8s *pSrcVec2, nm8s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsAdd_8s.html

global _nmppsAdd_8s:label;
<_nmppsAdd_8s>
.branch;
	ar5 = ar7 - 2;
	
	push ar0,gr0 with gr0=false;
	push ar1,gr1 with gr0++;
	push ar5,gr5 with gr0++;		// gr0=2 
	push ar6,gr6 with gr1=gr0;
	ar0 = [--ar5];	// pSrcVec1
	ar1 = [--ar5];	// pSrcVec2
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize in 8-bit elements
	
	nb1 = 80808080h with gr5>>=3;	// nSize in 64-bit words
	delayed call core_Add with gr1=gr0;
		wtw;						
		gr6=gr0;					// gr6=2
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;
return with gr7=false;
.wait;



end ".text.nmpp";
