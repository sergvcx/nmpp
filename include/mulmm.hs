//------------------------------------------------------------------------
//
//  $Workfile:: mtrMul_MxxV64.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module
//
//
//! \if file_doc
//!
//! \author ������ �������
//! \brief  ��������� ������� �� ������.
//!
//! \endif
//!
//------------------------------------------------------------------------

// Warining: nSize of this macros must be equal to 16!
// xx=64 bit => Nwfifo=1
// xx=32 bit => Nwfifo=2
// xx=16 bit => Nwfifo=4
// xx=08 bit => Nwfifo=8
// Ndata = height of block of matrix = [1,2,3...31]
 	
#define MUL_MxxV64_REP(Ndata,Nwfifo) MUL_MxxV64_REP_ Ndata Nwfifo
.macro MUL_MxxV64_REP_ Ndata,Nwfifo

	if =0 delayed goto End_Mul_MxxV64_repN\@ with gr7--;
		rep \Nwfifo wfifo = [ar4++gr4];
		rep \Ndata  data  = [ar0++gr0],ftw with vsum ,data,0;
	
	Next_Mul_MxxV64_repN\@:
	if <>0 delayed skip gr5 with gr7--;	
		rep \Nwfifo wfifo = [ar4++gr4],wtw;
		ar0 = ar1+gr1 with gr1 = gr1+gr2 noflags;
		rep \Ndata   data = [ar0++gr0],ftw with vsum ,data,afifo;

	End_Mul_MxxV64_repN\@:
	delayed return;
		rep \Ndata [ar6++gr6] = afifo,wtw;
		gr5 = ar5;	// pop ar5,gr5
		nul;
	nul;
	nul;
	nul;
	nul;
.endm


// Nwfifo - number of rows 
#define REP_N_MUL_MxxV64(Nwfifo) REP_N_MUL_MxxV64_ Nwfifo
.macro REP_N_MUL_MxxV64_ Nwfifo
	//own Mul_MxxV64_repN			:label;
	//own Next_Mul_MxxV64_rep32	:label;
	//own End_Mul_MxxV64_rep32	:label;
	//own Next_Mul_MxxV64			:label;

	ar3=ar4	with gr1 = gr5>>5;	// gr5-SrcMatrix height
	rep \Nwfifo wfifo = [ar4++gr4],ftw;	// preload first Nwfifo rows
	if =0 delayed goto Mul_MxxV64_repN\@;	// jump to onetime mul with custom rep  
		gr2=2;
	
	/////////////////////////////////////////////////////////////////////////////////////
	//  Multiplication 8,16,32,64-bit matrix with 32*nVal rows by 64-bit vector using rep32 instruction
	//  matrix height always is equal to 32
	//  (nHeight always assumed to be equal to 32)
	//
	//  INPUT REGISTERS: (ar0,gr0, ar4,gr4, ar6,gr6, gr2 )
	//	ar0-SrcMatrix
	//	gr0-SrcMatrix width in 32-bit words =[2,4,6.....]
	//  gr5-SrcMatrix height				=[0,1,2,....]
	//
	//	ar4-pSrcVec+gr4 (Two first longs of pSrcVec must be preloaded in shadow matrix and wfifo must be empty)
	//	gr4-pSrcVec reading step							in 32-bit words (mush be even)
	//	ar6-DstVecror
	//	gr6-pDstVec writing step							in 32-bit words (mush be even)
	//	
	//	gr2=2;
	//	sb
	//

	push ar5,gr5	with gr5 >>=5;
					with gr7 = gr0>>1;
	Next_Mul_MxxV64\@:
				  with gr1 = gr2 ;
		ar1 = ar0 with gr7--;
		rep \Nwfifo wfifo = [ar4++gr4],wtw;
		if =0 delayed goto End_Mul_MxxV64_rep32\@ with gr7--;
			rep 32 data = [ar0++gr0],ftw with vsum ,data,0;
			gr3 = ar0;
		Next_Mul_MxxV64_rep32\@:
			rep \Nwfifo wfifo = [ar4++gr4];
			ar0 = ar1+gr1 with gr1= gr1 + gr2 noflags;
		if <>0 delayed goto Next_Mul_MxxV64_rep32\@ with gr7--;
			wtw;
			rep 32 data = [ar0++gr0],ftw with vsum ,data,afifo;

		End_Mul_MxxV64_rep32\@:
		ar0 = gr3;
		ar4 = ar3 with gr5--;
	if <>0 delayed goto Next_Mul_MxxV64\@ with gr7=gr0>>1;
		rep \Nwfifo wfifo =[ar4++gr4],ftw;
		rep 32 [ar6++gr6] = afifo;

	pop ar5,gr5;
 
	/////////////////////////////////////////////////////////////////////////////////////
	//  Multiplication 8,16,32,64-bit matrix with nVal<32 rows by 64-bit vector using rep32 instruction
	//
	//  INPUT REGISTERS: (ar0,gr0, ar4,gr4, ar6,gr6, gr2 )
	//	ar0-SrcMatrix
	//	gr0-SrcMatrix width in 32-bit words =[2,4,6.....]
	//  gr5-SrcMatrix height				=[0,1,2,....]
	//	ar4-pSrcVec+gr4 (Two first longs of pSrcVec must be preloaded in shadow matrix and wfifo must be empty)
	//	gr4-pSrcVec reading step							in 32-bit words (mush be even)
	//	ar6-DstVecror
	//	gr6-pDstVec writing step							in 32-bit words (mush be even)
	//	
	//	gr2=2;
	//	sb
	//
	Mul_MxxV64_repN\@:
	ar1 = ar0	with gr7 = gr5<<27;	// gr5-SrcMatrix height
	ar5 = gr5	with gr7 >>=27; 	// push ar5,gr5 (pop in macro)
	
	
	gr1 = 2-16;
	if =0 delayed return with gr7<<=4;
		gr1+=gr7;
		wtw;	
		nul;
		
	 
	
	delayed skip gr1 with gr7=gr0>>1;	
		gr1 = gr2  with gr7--;
		gr5 = -2; // jump to itself in next skip instruction
	
	MUL_MxxV64_REP(1,\Nwfifo)
	MUL_MxxV64_REP(2,\Nwfifo)
	MUL_MxxV64_REP(3,\Nwfifo)
	MUL_MxxV64_REP(4,\Nwfifo)
	MUL_MxxV64_REP(5,\Nwfifo)
	MUL_MxxV64_REP(6,\Nwfifo)
	MUL_MxxV64_REP(7,\Nwfifo)
	MUL_MxxV64_REP(8,\Nwfifo)
	MUL_MxxV64_REP(9,\Nwfifo)
	MUL_MxxV64_REP(10,\Nwfifo)
	MUL_MxxV64_REP(11,\Nwfifo)
	MUL_MxxV64_REP(12,\Nwfifo)
	MUL_MxxV64_REP(13,\Nwfifo)
	MUL_MxxV64_REP(14,\Nwfifo)
	MUL_MxxV64_REP(15,\Nwfifo)
	MUL_MxxV64_REP(16,\Nwfifo)
	MUL_MxxV64_REP(17,\Nwfifo)
	MUL_MxxV64_REP(18,\Nwfifo)
	MUL_MxxV64_REP(19,\Nwfifo)
	MUL_MxxV64_REP(20,\Nwfifo)
	MUL_MxxV64_REP(21,\Nwfifo)
	MUL_MxxV64_REP(22,\Nwfifo)
	MUL_MxxV64_REP(23,\Nwfifo)
	MUL_MxxV64_REP(24,\Nwfifo)
	MUL_MxxV64_REP(25,\Nwfifo)
	MUL_MxxV64_REP(26,\Nwfifo)
	MUL_MxxV64_REP(27,\Nwfifo)
	MUL_MxxV64_REP(28,\Nwfifo)
	MUL_MxxV64_REP(29,\Nwfifo)
	MUL_MxxV64_REP(30,\Nwfifo)
	MUL_MxxV64_REP(31,\Nwfifo)
.endm


