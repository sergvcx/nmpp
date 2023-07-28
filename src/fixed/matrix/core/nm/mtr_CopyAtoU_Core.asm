//------------------------------------------------------------------------
//
//  $Workfile:: mtrCopyAtoU_Common $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:05:15 $
//
//! \if file_doc
//!
//! \file   mtrCopyDspCommon.asm
//! \author Павел Лукашевич
//! \brief  Функции инициализации и копирования для матриц.
//!
//! \endif
//!
//------------------------------------------------------------------------

extern core_Mul2D2W8_AddVr:label;

data ".data_nmplm_G"
//tables 8*2*2*8 = 256long
	core_Wt_Dsp00:long[32]=(

		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,

		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,

		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,

		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl

		);
	core_Wt_Dsp01:long[32]=(

		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,

		00000000000000000hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,

		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,

		00000000000000001hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl
		);
	core_Wt_Dsp02:long[32]=(


		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,

		00000000000000000hl,
		00000000000000000hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,

		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,

		00000000000000001hl,
		00000000000000100hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl
		);
	core_Wt_Dsp03:long[32]=(


		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,

		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,

		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,

		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl
		);
	core_Wt_Dsp04:long[32]=(


		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,

		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,

		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,

		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl
		);
	core_Wt_Dsp05:long[32]=(


		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,

		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,

		00000010000000000hl,
		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,

		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl
		);
	core_Wt_Dsp06:long[32]=(


		00000000000000000hl,
		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,

		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00001000000000000hl,
		00100000000000000hl,

		00001000000000000hl,
		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,

		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00000000000000000hl,
		00000000000000000hl
		);
	core_Wt_Dsp07:long[32]=(


		00000000000000000hl,
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,

		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00100000000000000hl,

		00100000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,
		00000000000000000hl,

		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000001000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00000000000000000hl
		);
end ".data_nmplm_G";

begin ".text_nmplm"
/////////////////////////////////////////////////////////////////////////////////
//	mtr_CopyDspCore
/////////////////////////////////////////////////////////////////////////////////
//	ar0  	Pointer to Src matrix
//	gr0  	Src matrix Stride in 32bit words
//	ar6  	Pointer to Dst matrix
//	gr6  	Dst matrix Stride in 32bit words
//	gr2  	Copying matrix height
//	gr3  	Copying matrix width in 64bit words
//	gr4		nDstOffset
//	gr7  	nb1 reg
/////////////////////////////////////////////////////////////////////////////////
// Registers : |   |ar1|ar2|ar3|   |ar5|   |   |
//			   |   |gr1|gr2|gr3|gr4|gr5|   |gr7| will be changed after return !
/////////////////////////////////////////////////////////////////////////////////
global mtr_CopyAtoU_Core:label;
<mtr_CopyAtoU_Core>

	ar4 = core_Wt_Dsp00 with gr4 = gr4<<5;//Mul 32
	ar4 +=gr4;
	
	gr4 = gr7;
	nb1 = gr4;

	gr5 = ar6;//dst
	ar1 = gr5;
	gr1 = gr6;

	push ar0,gr0;
	push ar6,gr6;

	push ar0,gr0;
	push ar1,gr1;
	push ar6,gr6;

//<EndBorderProcessing>

	ar5 = ar6 with gr5 = gr3<<1;
	ar6 = ar5 + gr5 with gr1 = gr3-1;

	ar1 = ar0 with gr1<<=1;
	ar0 = ar1 + gr1;

	gr5 = ar6;
	ar1 = gr5 with gr1 = gr6;

	delayed call core_Mul2D2W8_AddVr with gr5 = gr2;//reg0,reg1,reg6 changed
		nul;
		nul;

//<StartBorderProcessing>
	pop ar6,gr6;
	pop ar1,gr1;
	pop ar0,gr0;

	ar4 += 2*16;

	delayed call core_Mul2D2W8_AddVr with gr5 = gr2;//reg0,reg1,reg6 changed
		nul;
		nul;

//<Exit>
	pop ar6,gr6 with gr7 = gr4;
	pop ar0,gr0;

	return;
.wait;
end ".text_nmplm"; 