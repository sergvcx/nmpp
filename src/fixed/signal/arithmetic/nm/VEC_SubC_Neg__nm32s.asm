//------------------------------------------------------------------------
//
//  $Workfile:: SubNV.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   SubNV.asm
//! \author S.Mushkaev
//! \brief  Функции вычитания для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------

extern core_ram_sub_data:label;
extern  _nmppsTmpBuffer16_G_:long;

begin ".text.nmpp"

	
/////////////////////////////////////////////////////////////////////////////////////////
//! \fn void nmppsSubCRev(nm32s *pSrcVec, int32b nVal, nm32s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsSubCRev_32s.html

global _nmppsSubCRev_32s:label;
<_nmppsSubCRev_32s>
.branch;
	ar5 = ar7 - 2	with gr7=false;
	push ar0,gr0	with gr7++;
	push ar1,gr1	with gr7++;
	push ar5,gr5	with gr0=gr7;
	push ar6,gr6	with gr6=gr7;
	ar0 = [--ar5];						// pSrcVec
	gr1 = [--ar5];						// nVal
	ar6 = [--ar5];						// pDstVec
	gr5 = [--ar5];						// nSize
	
	ar1 = _nmppsTmpBuffer16_G_+2;
	nb1 = 80000000h;
	wtw;
	delayed call core_ram_sub_data 	with gr5>>=1;		// nSize in 64-bit longs
		[--ar1]=gr1;	
		[--ar1]=gr1;
	
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar1,gr1;
	pop ar0,gr0;
return;
.wait;





end ".text.nmpp";
