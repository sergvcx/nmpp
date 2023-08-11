//------------------------------------------------------------------------
//
//  $Workfile:: CompareMinV_32s.asm            $
//
//  Vector-processing library
//
//  Copyright (c) RC Module
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

begin ".text.nmpp"

extern core_CompareMinNV:label;
/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void nmppsMinNV_32s(nm32s31b** pSrcVec1, int numVecs, nm32s31b* pDstMax, int nSize);
//!
//! \perfinclude _nmppsMinEvery_32s.html

global _nmppsMinNV_32s :label;
<_nmppsMinNV_32s>
.branch;
	ar5=ar7 - 2;
	push ar0,gr0;
	push ar1,gr1	with gr1=false;
	push ar5,gr5	with gr1++;
	push ar6,gr6	with gr1++;			// gr1=2

	ar0 = [--ar5]   with gr6=gr1;		// pTable
	gr0 = [--ar5];						// numVecs
	ar6 = [--ar5];						// pDstMin
	gr5 = [--ar5];						// nSize
	
	nb1 =80000000h with gr5>>=1;
	f1cr=80000000h;
	delayed call core_CompareMinNV;
		wtw;
		nul;
	
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;
return;
.wait;

end ".text.nmpp";