//------------------------------------------------------------------------
//
//  $Workfile:: Math_Mul3D3W2.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:06 $
//
//! \if file_doc
//!
//! \file   Math_Mul3D3W2.asm
//! \author Сергей Ландышев
//! \brief  Функции векторного ядра.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vConvert.h"




begin ".text_nmvcore"

import from "nmpp/minrep.mlb";
DEF_MIN_REP();
      

macro MTR_MUL3D3W2_REP(N)
.if (NMPP_MIN_REP <= N);
		rep N data=[ar0++gr0],ftw,wtw with vsum ,data,vr;
		rep N data=[ar1++gr1],ftw,wtw with vsum ,data,afifo;
 		delayed return; 
			rep N data=[ar2++gr2] with vsum ,data,afifo;
			rep N [ar6++gr6]=afifo;
			nul;
		nul;
		nul;
.endif;
end MTR_MUL3D3W2_REP;

    //------------------------------------------------------------------------
    //! \fn void core_Mul3D3W2_AddVr(nmreg nb1, nmreg sb, nmreg vr, nmreg ar0, nmreg gr0, nmreg ar1, nmreg gr1, nmreg ar2, nmreg gr2, nmreg ar4, nmreg gr4, nmreg gr5, nmreg ar6, nmreg gr6)
    //!
    //------------------------------------------------------------------------

global core_Mul3D3W2_AddVr:label;
      <core_Mul3D3W2_AddVr>
.branch;
	Mul3D3W2_AddVr_rep0:label;
	push ar5,gr5		with gr7=gr5>>5;
	ar5 = ar4		with gr5<<=27;
	rep 6 wfifo=[ar4++],ftw,wtw;
	///ar4 = ar5		with gr5>>=23;

					with gr7;
	if =0 delayed goto Mul3D3W2_AddVr_repN with gr7--;
		ar4 = ar5		with gr5>>=23+1;
		with gr7;
	
	<Next_Mul3D3W2_AddVr_rep32>
		rep 32 data =[ar0++gr0],ftw,wtw with vsum ,data,vr;
 		rep 32 data =[ar1++gr1],ftw,wtw with vsum ,data,afifo;
		rep 6  wfifo=[ar4++],ftw;
		rep 32 data =[ar2++gr2],wtw with vsum ,data,afifo;
	if <>0 delayed  goto Next_Mul3D3W2_AddVr_rep32 with gr7--; 
		ar4 = ar5;
		rep 32 [ar6++gr6]=afifo;

	<Mul3D3W2_AddVr_repN>
	ar5 = Mul3D3W2_AddVr_rep0;
	ar5+=gr5;
	delayed goto ar5; 
		pop ar5,gr5;
		nul;
	<Mul3D3W2_AddVr_rep0>
		ftw;
		wtw;   // Clear wfifo
		ftw;
		wtw;
	delayed return;	
		nul;
		nul;
		nul;
	MTR_MUL3D3W2_REP(1);
	MTR_MUL3D3W2_REP(2);
	MTR_MUL3D3W2_REP(3);
	MTR_MUL3D3W2_REP(4);
	MTR_MUL3D3W2_REP(5);
	MTR_MUL3D3W2_REP(6);
	MTR_MUL3D3W2_REP(7);
	MTR_MUL3D3W2_REP(8);
	MTR_MUL3D3W2_REP(9);
	MTR_MUL3D3W2_REP(10);
	MTR_MUL3D3W2_REP(11);
	MTR_MUL3D3W2_REP(12);
	MTR_MUL3D3W2_REP(13);
	MTR_MUL3D3W2_REP(14);
	MTR_MUL3D3W2_REP(15);
	MTR_MUL3D3W2_REP(16);
	MTR_MUL3D3W2_REP(17);
	MTR_MUL3D3W2_REP(18);
	MTR_MUL3D3W2_REP(19);
	MTR_MUL3D3W2_REP(20);
	MTR_MUL3D3W2_REP(21);
	MTR_MUL3D3W2_REP(22);
	MTR_MUL3D3W2_REP(23);
	MTR_MUL3D3W2_REP(24);
	MTR_MUL3D3W2_REP(25);
	MTR_MUL3D3W2_REP(26);
	MTR_MUL3D3W2_REP(27);
	MTR_MUL3D3W2_REP(28);
	MTR_MUL3D3W2_REP(29);
	MTR_MUL3D3W2_REP(30);
	MTR_MUL3D3W2_REP(31);
.wait;


end ".text_nmvcore";
