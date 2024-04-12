//------------------------------------------------------------------------
//
//
//  <Название библиотеки>
//
//  Copyright (c) RC Module
//
//
//! \if file_doc
//!
//! \author S. Mushkaev
//!
//! \endif
//!
//------------------------------------------------------------------------


#include "nmpp/nmc.hs"


//#define TAIL_REP(N) tail_rep N
.macro tail_rep N
	rep \N ram = [ar5] ;
	rep \N data = [ar0++gr0] with ram xor data ;
	delayed return;
		rep \N  with vsum ,afifo, vr;
		rep \N [ar6++gr6]=afifo;
		vnul;
	vnul;
	vnul;
.endm tail_rep;

.section .text.nmpp.core

    //------------------------------------------------------------------------
    //! \fn void core_xor_vsum_data_vr(nmreg ar5 (xor), nmreg nmreg nb1, nmreg sb, nmreg woper, nmreg vr, nmreg ar0, nmreg gr0, nmreg gr5, nmreg ar6, nmreg gr6)
    //!
    //------------------------------------------------------------------------

.global core_xor_vsum_data_vr
core_xor_vsum_data_vr:
BRANCH
	push ar2,gr2 with gr2=gr5<<27;
	push ar5,gr5 with gr5>>=5;
	
	if =0 delayed goto block_repN with gr2>>=24; //x8
		ar2 = block_rep0 with gr5--;
	
	rep 32 ram=[ar5];
	next_Block_rep32:
		rep 32 data = [ar0++gr0] with ram xor data ;
		rep 32  with vsum ,afifo, vr;
	if > delayed goto next_Block_rep32 with gr5--;
		rep 32 [ar6++gr6]=afifo;
		vnul;

	block_repN:
	ar2+= gr2;
	delayed goto ar2; 
		pop ar5,gr5;
		pop ar2,gr2;
	block_rep0:
	delayed return;
		nul;
		nul;
		nul;
	tail_rep 1
	tail_rep 2
	tail_rep 3
	tail_rep 4
	tail_rep 5
	tail_rep 6
	tail_rep 7
	tail_rep 8
	tail_rep 9
	tail_rep 10
	tail_rep 11
	tail_rep 12
	tail_rep 13
	tail_rep 14
	tail_rep 15
	tail_rep 16
	tail_rep 17
	tail_rep 18
	tail_rep 19
	tail_rep 20
	tail_rep 21
	tail_rep 22
	tail_rep 23
	tail_rep 24
	tail_rep 25
	tail_rep 26
	tail_rep 27
	tail_rep 28
	tail_rep 29
	tail_rep 30
	tail_rep 31
return;


WAIT
