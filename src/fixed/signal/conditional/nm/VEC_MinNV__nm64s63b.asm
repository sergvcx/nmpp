//------------------------------------------------------------------------
//
//  $Workfile:: CompareMinV_64s.asm            $
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

//! \fn void nmppsMinNV_64s(nm64s63b** pSrcVec1, int numVecs, nm64s63b* pDstMax, int nSize);
//!
//! \perfinclude _nmppsMinNV_64s.html

global _nmppsMinNV_64s :label;
<_nmppsMinNV_64s>
.branch;
	ar5=ar7 - 2;
	push ar0,gr0	with gr0=false;
	nb1 = gr0;
	f1crl=gr0;
	
	push ar1,gr1	with gr1=false;
	push ar5,gr5	with gr1++;
	push ar6,gr6	with gr1++;			// gr1=2

	ar0 = [--ar5]   with gr6=gr1;		// pTable
	gr0 = [--ar5];						// numVecs
	ar6 = [--ar5];						// pDstMin
	gr5 = [--ar5];						// nSize
	
	f1crh=80000000h;
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