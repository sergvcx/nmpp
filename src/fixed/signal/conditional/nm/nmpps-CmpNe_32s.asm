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

extern core_CmpNeV:label;
/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void nmppsCmpNe_32s(nm32s* pSrcVec1, nm32s* pSrcVec2, nm32s* pDstMax, int nSize);
//!
//! \perfinclude _nmppsCmpNe_32s.html

global _nmppsCmpNe_32s:label;
<_nmppsCmpNe_32s>
.branch;
	ar5=ar7 - 2;
	push ar0,gr0	with gr0=false;
	push ar1,gr1	with gr0++;
	push ar5,gr5	with gr0++;
	push ar6,gr6	with gr1=gr0;

	ar0 = [--ar5] with gr6=gr0;		    // pSrcVec1
	ar1 = [--ar5];						// pSrcVec2
	ar6 = [--ar5];						// pDstMin
	gr5 = [--ar5];						// nSize
	
	f1cr = 0FFFFFFFEh;
    f2cr = 0FFFFFFFEh;
	nb1  = 080000000h with gr5>>=1;
	delayed call core_CmpNeV;
		wtw;
		nul;
		
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;
return;
.wait;

end ".text.nmpp";
