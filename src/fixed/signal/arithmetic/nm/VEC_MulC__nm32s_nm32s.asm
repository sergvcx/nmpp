//------------------------------------------------------------------------
//
//  $Workfile:: Mul_V32N32.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:03 $
//
//! \if file_doc
//!
//! \file   Mul_V32N32.asm
//! \author S.Mushkaev
//! \brief  Функции умножения для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------
//import from macros.mlb;

extern core_vsum_data_0	:label;
extern _nmppsTmpBuffer16_G_:long[16];

begin ".text.nmpp"
/////////////////////////////////////////////////////////////////////////////////////////

//! \fn void nmppsMulC (nm32s *pSrcVec, int32b nVal, nm32s *pDstVec, int nSize)
//!
//! \perfinclude _nmppsMulC_32s.html

global _nmppsMulC_32s:label;
<_nmppsMulC_32s>
.branch;


	ar5 = ar7 - 2;
	push ar0,gr0;
	push ar5,gr5;
	push ar6,gr6;

	ar0 = [--ar5] with gr0=false;		// pSrcVec
	gr5 = [--ar5] with gr7 = false;			// Scalar value(Hi)
	
	//-- WFIFO init ---------------------------
	ar6 = _nmppsTmpBuffer16_G_;
	[ar6++] = gr5;
	[ar6++] = gr7;
	[ar6++] = gr7;
	[ar6++] = gr5;
	ar6-=4;
	nb1 = 80000000h;
	sb  = 2;
	rep 2 wfifo=[ar6++],ftw;
	//-----------------------------------------
	ar6 = [--ar5] with gr0++;			// pDstVec
    gr5 = [--ar5] with gr0++;			// nSize

	
	delayed call core_vsum_data_0 with gr5 >>= 1;
		with gr6=gr0;
		wtw;
		
	
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
return;
.wait;


end ".text.nmpp";
