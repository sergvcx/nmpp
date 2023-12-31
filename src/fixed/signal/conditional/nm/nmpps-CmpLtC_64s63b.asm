//------------------------------------------------------------------------
//
//  $Workfile:: AddVN.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   AddVN.asm
//! \author S.Mushkaev
//! \brief  Функции суммирования для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------

extern core_CmpLtC:label;
extern _VEC_TBL_MinusOne_G:long;

begin ".text.nmpp"

/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void nmppsCmpLtC_64s63b (nm64s *pSrcVec, int64b nVal, nm64s *pDstVec, int nSize) 
//!
//! \perfinclude nmppsCmpLtC_64s63b.html

global _nmppsCmpLtC_64s63b:label;
<_nmppsCmpLtC_64s63b>
.branch;
	ar5 = ar7 - 2;
	
	push ar0,gr0;
	push ar1,gr1;
	push ar5,gr5;
	push ar6,gr6;

	ar0 = [--ar5];	// SrcBuff
	gr7 = [--ar5];  // dummy allign
	ar1,gr1 = [--ar5];	// nVal
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize


	
	nb1 = 00000000h;	// nSize in 64-bit longs
	wtw;
	ar5 = ar7;
	push ar1,gr1;
	ar1 = ar5;
	gr0 = 2;
	f1crh = 0FFFFFFFFh;
	f1crl = 0FFFFFFFEh;	
	delayed call core_CmpLtC;
		gr6 = 2;
	
	pop ar1,gr1;	
	
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;

return with gr7=false;
.wait;



end ".text.nmpp";
