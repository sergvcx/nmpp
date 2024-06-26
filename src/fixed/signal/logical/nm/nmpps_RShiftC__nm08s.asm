//------------------------------------------------------------------------
//
//  $Workfile:: ARSH8.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:04 $
//
//! \if file_doc
//!
//! \file   ARSH8.asm
//! \author Павел Лукашевич
//! \brief  Функции сдвига для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------


	extern core_vsum_shift_data_0:label;
	extern core_vsum_data_0:label;

data ".data_nmplv_G"
	global	core_tbl_w_char_ARSH:long[24*8]=(

				00000000000000001hl,//arshift 0
				00000000000000010hl,
				00000000000000040hl,
				00000000000000100hl,
				00000000000001000hl,
				00000000000004000hl,
				00000000000010000hl,
				00000000000100000hl,
				00000000000400000hl,
				00000000001000000hl,
				00000000010000000hl,
				00000000040000000hl,
				00000000100000000hl,
				00000001000000000hl,
				00000004000000000hl,
				00000010000000000hl,
				00000100000000000hl,
				00000400000000000hl,
				00001000000000000hl,
				00010000000000000hl,
				00040000000000000hl,
				00100000000000000hl,
				01000000000000000hl,
				04000000000000000hl,

				00000000000000001hl,//arshift 1
				00000000000000010hl,
				000000000000000c0hl,
				00000000000000100hl,
				00000000000001000hl,
				0000000000000c000hl,
				00000000000010000hl,
				00000000000100000hl,
				00000000000c00000hl,
				00000000001000000hl,
				00000000010000000hl,
				000000000c0000000hl,
				00000000100000000hl,
				00000001000000000hl,
				0000000c000000000hl,
				00000010000000000hl,
				00000100000000000hl,
				00000c00000000000hl,
				00001000000000000hl,
				00010000000000000hl,
				000c0000000000000hl,
				00100000000000000hl,
				01000000000000000hl,
				0c000000000000000hl,

				00000000000000000hl,//arshift 2
				00000000000000001hl,
				00000000000000010hl,
				00000000000000000hl,
				00000000000000100hl,
				00000000000001000hl,
				00000000000000000hl,
				00000000000010000hl,
				00000000000100000hl,
				00000000000000000hl,
				00000000001000000hl,
				00000000010000000hl,
				00000000000000000hl,
				00000000100000000hl,
				00000001000000000hl,
				00000000000000000hl,
				00000010000000000hl,
				00000100000000000hl,
				00000000000000000hl,
				00001000000000000hl,
				00010000000000000hl,
				00000000000000000hl,
				00100000000000000hl,
				01000000000000000hl,

				00000000000000000hl,//arshift 3
				00000000000000001hl,
				000000000000000f0hl,
				00000000000000000hl,
				00000000000000100hl,
				0000000000000f000hl,
				00000000000000000hl,
				00000000000010000hl,
				00000000000f00000hl,
				00000000000000000hl,
				00000000001000000hl,
				000000000f0000000hl,
				00000000000000000hl,
				00000000100000000hl,
				0000000f000000000hl,
				00000000000000000hl,
				00000010000000000hl,
				00000f00000000000hl,
				00000000000000000hl,
				00001000000000000hl,
				000f0000000000000hl,
				00000000000000000hl,
				00100000000000000hl,
				0f000000000000000hl,

				00000000000000000hl,//arshift 4
				00000000000000001hl,
				00000000000000004hl,
				00000000000000000hl,
				00000000000000100hl,
				00000000000000400hl,
				00000000000000000hl,
				00000000000010000hl,
				00000000000040000hl,
				00000000000000000hl,
				00000000001000000hl,
				00000000004000000hl,
				00000000000000000hl,
				00000000100000000hl,
				00000000400000000hl,
				00000000000000000hl,
				00000010000000000hl,
				00000040000000000hl,
				00000000000000000hl,
				00001000000000000hl,
				00004000000000000hl,
				00000000000000000hl,
				00100000000000000hl,
				00400000000000000hl,

				00000000000000000hl,//arshift 5
				00000000000000001hl,
				000000000000000fchl,
				00000000000000000hl,
				00000000000000100hl,
				0000000000000fc00hl,
				00000000000000000hl,
				00000000000010000hl,
				00000000000fc0000hl,
				00000000000000000hl,
				00000000001000000hl,
				000000000fc000000hl,
				00000000000000000hl,
				00000000100000000hl,
				0000000fc00000000hl,
				00000000000000000hl,
				00000010000000000hl,
				00000fc0000000000hl,
				00000000000000000hl,
				00001000000000000hl,
				000fc000000000000hl,
				00000000000000000hl,
				00100000000000000hl,
				0fc00000000000000hl,

				00000000000000000hl,//arshift 6
				00000000000000000hl,
				00000000000000001hl,
				00000000000000000hl,
				00000000000000000hl,
				00000000000000100hl,
				00000000000000000hl,
				00000000000000000hl,
				00000000000010000hl,
				00000000000000000hl,
				00000000000000000hl,
				00000000001000000hl,
				00000000000000000hl,
				00000000000000000hl,
				00000000100000000hl,
				00000000000000000hl,
				00000000000000000hl,
				00000010000000000hl,
				00000000000000000hl,
				00000000000000000hl,
				00001000000000000hl,
				00000000000000000hl,
				00000000000000000hl,
				00100000000000000hl,

				00000000000000000hl,//arshift 7
				00000000000000000hl,
				000000000000000ffhl,
				00000000000000000hl,
				00000000000000000hl,
				0000000000000ff00hl,
				00000000000000000hl,
				00000000000000000hl,
				00000000000ff0000hl,
				00000000000000000hl,
				00000000000000000hl,
				000000000ff000000hl,
				00000000000000000hl,
				00000000000000000hl,
				0000000ff00000000hl,
				00000000000000000hl,
				00000000000000000hl,
				00000ff0000000000hl,
				00000000000000000hl,
				00000000000000000hl,
				000ff000000000000hl,
				00000000000000000hl,
				00000000000000000hl,
				0ff00000000000000hl
				);


	global	core_tbl_nb_sb_char_ARSH:long[16]=(
			
				0a8a8a8a8a8a8a8a8hl,//nb shr 0
				0a2a2a2a2a2a2a2a2hl,//sb shr 0
			
				0e8e8e8e8e8e8e8e8hl,//nb shr 1
				0a2a2a2a2a2a2a2a2hl,//sb shr 1

				08888888888888888hl,//nb shr 2
				08a8a8a8a8a8a8a8ahl,//sb shr 2

				0f8f8f8f8f8f8f8f8hl,//nb shr 3
				08a8a8a8a8a8a8a8ahl,//sb shr 3

				08282828282828282hl,//nb shr 4
				0a2a2a2a2a2a2a2a2hl,//sb shr 4

				0fefefefefefefefehl,//nb shr 5
				0a2a2a2a2a2a2a2a2hl,//sb shr 5

				08080808080808080hl,//nb shr 6
				0a2a2a2a2a2a2a2a2hl,//sb shr 6

				0ffffffffffffffffhl,//nb shr 7
				0a2a2a2a2a2a2a2a2hl //sb shr 7
				);
								
end ".data_nmplv_G";

import from "nmpp/macros.mlb";

begin ".text.nmpp"

///////////////////////////////////////////////////////////////////////////////////////
//
//! \fn void nmppsRShiftC_8s(nm8s *pSrcVec, int nShift, nm8s *pDstVec, int nSize) 
//!
//! \perfinclude _nmppsRShiftC_8s.html


global _nmppsRShiftC_8s:label;
<_nmppsRShiftC_8s>
.branch;
	ar5 = ar7 - 4;
	push ar0,gr0;
	
	gr0 = [ar5];		//	int				nShift	 :[0, 1, 2, .., 31].

	ar0 = core_tbl_nb_sb_char_ARSH with gr0<<=2;
	ar5-=2;
	ar0+= gr0 with gr0<<=2;//gr0 = nShift*16
	nb1 = [ar0++] with gr7 = gr0<<1;//gr7 = nShift*16*2
	sb  = [ar0];
	ar0 = core_tbl_w_char_ARSH with gr0 += gr7;//gr0 = nShift*16*2 + nShift*16
	ar0+= gr0;			// w table select 
	rep 24 wfifo=[ar0++],ftw;

	
	push ar5,gr5	with gr0=false;
	push ar6,gr6	with gr0++;
	
//	gr7 = [ar5++]	with gr0++;			// 	int				nShift	:[0, 1, 2, .., 31].
//	gr5 = [ar5++]	with gr6=gr0;		//	int				VecSize,	//nSize of input buffer in 8 bit elements. nSize=[256, 512, .., n*256].
//	ar6 = [ar5++]	with gr7<<=31;		//	nm32u*	DstVec,		//Output buffer		:long Global[nSize/8].
//	ar0 = [ar5++];						//	nm32u*	SrcVec,		//Input buffer		:long Local [nSize/8].

	gr5 = [ar5++]	with gr0++;			//	int				VecSize,	//Size of input buffer in 8 bit elements. Size=[256, 512, .., n*256].
	ar6 = [ar5++]	with gr6=gr0;		//	nm32u*	DstVec,		//Output buffer		:long Global[Size/8].
	gr7 = [ar5++]	;					// 	int				Shift	:[0, 1, 2, .., 31].
	ar0 = [ar5++] with gr7<<=31;		//	nm32u*	SrcVec,		//Input buffer		:long Local [Size/8].
		

	if =0 delayed goto Even_RightShift	with gr5>>=3;// nSize in 64-bit vectors
		nul;
		nul;

	<Odd_RightShift>
	delayed call core_vsum_shift_data_0;
		wtw;
		nul;
	goto End_RightShift;
	
	<Even_RightShift>
	delayed call core_vsum_data_0;
		wtw;
		nul;

	<End_RightShift>


	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
	return;
.wait;
end ".text.nmpp";
