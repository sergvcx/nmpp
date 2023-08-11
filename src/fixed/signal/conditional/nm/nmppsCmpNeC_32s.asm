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

extern core_CmpNeC:label;
extern _VEC_TBL_Diagonal_FFFFFFFFh_G:long;

begin ".text.nmpp"

/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void nmppsCmpNeC_32s (nm32s *pSrcVec, int32b nVal, nm32s *pDstVec, int nSize) 
//!
//! \perfinclude nmppsCmpNeC_32s.html

global _nmppsCmpNeC_32s:label;
<_nmppsCmpNeC_32s>
.branch;
	ar5 = ar7 - 2;
	
	push ar0,gr0;
	push ar1,gr1;
	push ar5,gr5;
	push ar6,gr6;

	ar0 = [--ar5];	// SrcBuff
	gr0 = [--ar5];	// nVal
	ar6 = [--ar5];	// pDstVec
	gr5 = [--ar5];	// nSize

	ar5 = _VEC_TBL_Diagonal_FFFFFFFFh_G set ;
	
	nb1 = 80000000h with gr5>>=1;	// nSize in 64-bit longs
	sb  = 00000002h;
	rep 2 wfifo = [ar5++],ftw,wtw;
	
	vr = gr0 ;
	gr0 = 2;
	f1cr = 0FFFFFFFEh;
    f2cr = 0FFFFFFFEh;  
	delayed call core_CmpNeC;
		gr6 = 2;
			
	
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;

return with gr7=false;
.wait;



end ".text.nmpp";
