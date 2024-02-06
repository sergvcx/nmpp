//------------------------------------------------------------------------
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//
//! \if file_doc
//!
//! \file   nmppsDecimate.asm
//! \author Иван Жиленков
//! \brief  
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmpp/nmc.hs"
//void core_ClipMul4D4W4_AddVr(nmreg nb1, 
//								nmreg sb, 
//								nmreg F1CR, 
//								nmreg vr, 
//								nmreg ar0, nmreg gr0, 
//								nmreg ar1, nmreg gr1, 
//								nmreg ar2, nmreg gr2, 
//								nmreg ar3, nmreg gr3, 
//								nmreg ar4, nmreg gr4, 
//								nmreg gr5, 
//								nmreg ar6, nmreg gr6)

//void nmppsDecimate_32s(nm32s* pSrc, int startPos, int step, nm32s* pDst, int nSize);


.section .data.nmpp
 	.align 3
	weights: .quad 		0x0000000000000001,0, \
						0x0000000100000000,0, \
					 \
						0,0x0000000000000001, \
						0,0x0000000100000000


.section .text.nmpp
BRANCH
.global _nmppsDecimate_32s

_nmppsDecimate_32s:
	ar5 = ar7 - 2;
	push ar0, gr0;
	push ar1, gr1;
	push ar2, gr2;
	push ar3, gr3;
	push ar4, gr4;
	push ar5, gr5;
	push ar6, gr6;
	
	ar0 = [--ar5]	with gr6 = false;
	SET vr  gr6		//vr = 0
	gr4 = [--ar5]	with gr6++;
	gr0 = [--ar5]	with gr6++;
	ar6 = [--ar5];
	gr5 = [--ar5]	with gr4 <<=3;
		
	SET nb1 80000000h	
	
	SET sb  2
	wtw;
	with gr5>>=1; 
	ar4 = weights;
	delayed call core_Mul2D2W2_AddVr;
		ar1 = ar0 + gr0 	with gr0<<=1;
		ar4 += gr4			with gr1 = gr0;
	
	pop ar6, gr6;
	pop ar5, gr5;
	pop ar4, gr4;
	pop ar3, gr3;
	pop ar2, gr2;
	pop ar1, gr1;
	pop ar0, gr0;

	return;
WAIT
