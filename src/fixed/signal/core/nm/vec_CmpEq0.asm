//------------------------------------------------------------------------
//
//  $Workfile:: Cmp_Eq0.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2019/01/15 13:50:05 $
//
//! \if file_doc
//!
//! \file   Cmp_Eq0.asm
//! \author Иван Жиленков
//! \brief  Функции векторного ядра.
//!
//! \endif
//!
//------------------------------------------------------------------------


begin ".text_nmvcore"

import from "nmpp/minrep.mlb";
DEF_MIN_REP();

macro VEC_CMP_EQ_0(N)
.if (NMPP_MIN_REP <= N);
	delayed return;
		rep N data,ram = [ar0++gr0] with 0-data ;
		rep N with not activate afifo and not activate ram;
		rep N [ar6++gr6] = afifo;
.endif;
end   VEC_CMP_EQ_0;

Cmp_rep0:label;

    //------------------------------------------------------------------------
    //! \fn void core_CmpEq0(nmreg nb1, nmreg ar0, nmreg gr0, nmreg ar1, nmreg gr1, nmreg gr5, nmreg ar6, nmreg gr6)
    //!
    //------------------------------------------------------------------------

global core_CmpEq0 :label;
<core_CmpEq0>
.branch;
	push ar2,gr2 with gr2=gr5<<27 ;
	push ar5,gr5 with gr5>>=5;	
	if =0 delayed goto Cmp_repN with gr2>>=25;
		ar2 = Cmp_rep0 with gr5--;
	<next_Cmp_rep32>
		nul;
		rep 32 data,ram = [ar0++gr0] with 0-data;
	if <>0 delayed goto next_Cmp_rep32 with gr5--;
		rep 32 with not activate afifo and not activate ram;
		rep 32 [ar6++gr6] = afifo;
	<Cmp_repN>
	ar2+=gr2;
	delayed goto ar2; 
		pop ar5,gr5;
		pop ar2,gr2;
	<Cmp_rep0>
	delayed return;
		nul;
		nul;
		nul;
	VEC_CMP_EQ_0(1);
	VEC_CMP_EQ_0(2);
	VEC_CMP_EQ_0(3);
	VEC_CMP_EQ_0(4);
	VEC_CMP_EQ_0(5);
	VEC_CMP_EQ_0(6);
	VEC_CMP_EQ_0(7);
	VEC_CMP_EQ_0(8);
	VEC_CMP_EQ_0(9);
	VEC_CMP_EQ_0(10);
	VEC_CMP_EQ_0(11);
	VEC_CMP_EQ_0(12);
	VEC_CMP_EQ_0(13);
	VEC_CMP_EQ_0(14);
	VEC_CMP_EQ_0(15);
	VEC_CMP_EQ_0(16);
	VEC_CMP_EQ_0(17);
	VEC_CMP_EQ_0(18);
	VEC_CMP_EQ_0(19);
	VEC_CMP_EQ_0(20);
	VEC_CMP_EQ_0(21);
	VEC_CMP_EQ_0(22);
	VEC_CMP_EQ_0(23);
	VEC_CMP_EQ_0(24);
	VEC_CMP_EQ_0(25);
	VEC_CMP_EQ_0(26);
	VEC_CMP_EQ_0(27);
	VEC_CMP_EQ_0(28);
	VEC_CMP_EQ_0(29);
	VEC_CMP_EQ_0(30);
	VEC_CMP_EQ_0(31);
return;
.wait;




end ".text_nmvcore";
