//------------------------------------------------------------------------
//
//  $Workfile:: Copy.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:08 $
//
//! \if file_doc
//!
//! \file   Copy.asm
//! \author S.Mushkaev
//! \brief  Функции инициализации и копирования.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vCopy.h"

extern core_data:label;


begin ".text.nmpp"
 
		
//! \fn void nmppsCopy_8s(nm8s* pSrcVec, nm8s* pDstVec, int nSize);
//!
//! \perfinclude _nmppsCopy_8s.html

global _nmppsCopy_8s:label;
<_nmppsCopy_8s>
.branch;
    ar5 = ar7 - 2	with gr7=gr5;
	push ar0,gr0	with gr0=false;
	push ar6,gr6	with gr0++;
    ar0 = [--ar5]	with gr0++;		// pSrcVec
	ar6 = [--ar5]	with gr6=gr0;	// pDstVec
	delayed call core_data;
		gr5 = [--ar5];				// nSize
		gr5>>=3;
	pop ar6,gr6;
	pop ar0,gr0		with gr5=gr7;
	return;
.wait;


end ".text.nmpp";