//------------------------------------------------------------------------
//
//  $Workfile:: MultipleAdd16.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   MultipleAdd16.Asm
//! \author S.Mushkaev
//! \brief  Функции умножения с накоплением для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------
//#include "vArithm.h"


data ".data_nmplv_G"

end ".data_nmplv_G";

import from "nmpp/macros.mlb";

extern core_Add4V:label;
begin ".text.nmpp"



/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void nmppsAdd4V (nm16s **ppSrcVec, nm16s *pDstVec, int nSize, int nNumberOfVectors) 
//!
//! \perfinclude _nmppsSum4_16s.html
global _nmppsAdd4V_16s:label;
<_nmppsAdd4V_16s>
.branch;
	ar5 = ar7 - 2;
	
	PUSH_REGS();
	ar4 = [--ar5];	// Buffers
	ar6 = [--ar5];	// DstBuffer
	gr5 = [--ar5];	// SizeOfBuffers
	
	gr0 = 2;
	ar0 = [ar4++] with gr1=gr0;
	ar1 = [ar4++] with gr2=gr0;
	ar2 = [ar4++] with gr3=gr0;
	ar3 = [ar4++] with gr6=gr0;
	
	nb1 = 80008000h with gr5>>=2;	// nSize in 64-bit longs
	call core_Add4V;
	
	POP_REGS();
	return ;
.wait;
end ".text.nmpp";
 


