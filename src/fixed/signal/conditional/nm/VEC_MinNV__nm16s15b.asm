//------------------------------------------------------------------------
//
//  $Workfile:: CompareMinV_8s.asm             $
//
//  Vector-processing library
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:09 $
//
//! \if file_doc
//!
//! \file   CompareMinV_8s.asm
//! \author S. Mushkaev
//! \brief  Elementwise min comparision
//!
//! \endif
//!
//------------------------------------------------------------------------

begin ".text_nmplv"

extern vec_CompareMinNV:label;
/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void nmppsMinNV_8s(nm8s7b**  pSrcVec1, nm8s7b* pSrcVec2, int numVecs, nm8s7b*  pDstMin, int nSize);
//!
//! \perfinclude _nmppsMinEvery_8s.html

global _nmppsMinNV_16s :label;
<_nmppsMinNV_16s>
.branch;
	ar5=sp-2;
	push ar0,gr0;
	push ar1,gr1	with gr1=false;
	push ar5,gr5	with gr1++;
	push ar6,gr6	with gr1++;			// gr1=2

	ar0 = [--ar5]   with gr6=gr1;		// pTable
	gr0 = [--ar5];						// numVecs
	ar6 = [--ar5];						// pDstMin
	gr5 = [--ar5];						// nSize
	
	nb1 =80008000h with gr5>>=2;
	f1cr=80008000h;
	delayed call vec_CompareMinNV;
		wtw;
		nul;
	
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;
return;
.wait;

end ".text_nmplv";





	