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
//! \fn void void nmppsAddEx_64s (const nm64s *pSrcVec1, int srcStep1, const nm64s *pSrcVec2, int srcStep2, nm64s *pDstVec, int dstStep, int nSize  )
//!
//! \perfinclude _nmppsAdd_64s.html


global _nmppsAddEx_64s:label;

<_nmppsAddEx_64s>
.branch;
	ar5 = ar7 - 2;
	
	push ar0,gr0;
	push ar1,gr1;
	push ar5,gr5;
	push ar6,gr6;
	ar0 = [--ar5];	// pSrcVec1
	gr0 = [--ar5];	// step
	ar1 = [--ar5] with gr0<<=1;	// pSrcVec2
	gr1 = [--ar5]; 
	ar6 = [--ar5] with gr1<<=1;	// pDstVec
	gr6 = [--ar5];
	gr5 = [--ar5] with gr6<<=1;	// nSize in 64-bit elements
	
	nb1 = 0;		
	delayed call core_Add;
		wtw;						
		nul;					
		
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;
return with gr7=false;
.wait;






end ".text.nmpp";
