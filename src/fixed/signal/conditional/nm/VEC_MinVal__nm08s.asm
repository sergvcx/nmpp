//------------------------------------------------------------------------
//
//  $Workfile:: GetMax.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:10 $
//
//! \if file_doc
//!
//! \file   GetMax.asm
//! \author S.Mushkaev
//! \brief  Статистические функции.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vMinMax.h"
import from macros.mlb;
extern	_nmppsTmpBuffer64_G_: long;
extern	_nmppsTmpBuffer16_G_: long;
extern core_MinVal_v8nm8s:label;
extern core_MinVal:label;




begin ".text.nmpp"
/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void nmppsMin_8s7b(nm8s *pSrcVec, int nSize, int8b &nMinValue) 
//!
//! \perfinclude _nmppsMin_8s7b.html



global _nmppsMin_8s7b:label;
<_nmppsMin_8s7b>
.branch;
	ar5=ar7 - 2;
	PUSH_REGS();
	ar0 = [--ar5];									// pSrcVec
	gr5 = [--ar5];									// nSize of pSrcVec
	gr6 = [--ar5];									// Pointer to Minimum
	
	gr0 =2 with gr5 >>=3;							// nSize in 64-bit longs
	gr4 =80808080h;
	nb1 =gr4;
	f1cr=gr4;
	wtw;
	
	ar4 = _nmppsTmpBuffer64_G_;
	delayed call core_MinVal;
		ar6=_nmppsTmpBuffer16_G_;
	
	delayed call core_MinVal_v8nm8s;
		ar0=ar6;
		nul;

	[gr6]=gr7;							
	POP_REGS();
return;
.wait;



	

end ".text.nmpp";
