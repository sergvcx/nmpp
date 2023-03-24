///////////
// nmblas (neuro matrix Basic Linear Algebra Subroutines)
//  Copyright (c) RC Module Inc.

// Author : Alexandr Bolotnikov 
// Originaly developed at reserch center "Module" Moscow 
// Year 2017 
///////////

//the purpose of this function see in nmblas_idamax.s file
 .global _fpu_idamax

.section .data
  init_index : 	.double 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31
	//,double(1),double(2),double(3),double(4),double(5),double(6),double(7),double(8),double(9),double(10),double(11),
    //double(12),double(13),double(14),double(15),double(16),double(17),double(18),double(19),double(20),double(21),double(22),double(23),double(24),
    //double(25),double(26),double(27),double(28),double(29),double(30),double(31));
  const32  :		.double 32
  min_infinity : 	.quad   0xfff0000000000000
  //min_infinity : long = double(-999999);

.section .bss
  buff :
  .rept 32
  .quad 0
  .endr


.text

// REG-API:
// ar0 - input 
// gr0 - double to double step
// gr5 - size
_fpu_idamax:
	gr5;				// size in 64-bit  words
	if <= delayed return;
	////init of mask   
		gr7 = false;
		sir = gr7;
	fp1_lmask = sir;
	fp1_hmask = sir;
	//////  
	//gr0 = gr0 << 1;
	//gr7 = gr5 >> 1; // ???
	//if =0 delayed goto CASE_AMMOUNT_EQS_1;
	gr7 = gr5 << 27;
	gr7 = gr7 >> 27;	// gr7=остаток от деления на 32
	gr5 = gr5 >> 5;		// gr5=частное от деления на 32

	// загружаем индексы
	ar5 = init_index;
	fpu 0 rep 32  vreg1 = [ar5++];		// fpu0 vreg0[32] = 0,1,2,3....31 load initial value of indexes
	fpu 0 .double vreg0 = vreg1-vreg1;	// vreg1[32] = 0,0,0,0,0 ... fpu// fpu0 vreg1[32] = 0,1,2,3....31 - тут собираем позиции 
	ar5 = const32;
	//if =0  delayed goto CASE_WITHOUT_QUTIENT;
	
	fpu 0 rep 1 vreg7 = [ar5];		// fpu 0 vreg7[1] = const 32 (load 32 as increment for further indexing )
//		nul;

///init

	fpu 1 rep 32  vreg0 = [ar5];		// fpu 1 vreg0[32]= -inf, -inf... - тут собираем максимумы
	//fpu 1 rep 32  vreg0 = [ar0++gr0];	// fpu 1 vreg0[32]= src...
	//fpu 1 .double vreg0 = /vreg0/;		// fpu 1 vreg0[32]= |src|...
	with gr5;
	if =0 goto REMAINDER;
	
	LOOP:
		fpu 1 rep 32  vreg1 = [ar0++gr0];				// fpu1 vreg1[32] = src ...
		fpu 1 .double vreg1 = /vreg1/; 					// fpu1 vreg1[32] = |src|...
		//fpu 0 .double vreg1 = vreg1 + .retrive(vreg7);	// fpu0 vreg1[32] = 33,34,45... index inceremnt on +32
		fpu 1 .double vreg1-vreg0,set mask if >;		// fpu1 <->?
		/////hardware bug in 6407 the last element of mask does not work propraetry
		fp1_lmask = fp1_lmask;
		/////  
		fpu 1 .double vreg0 = mask ? vreg1:vreg0; 		// fpu1 vreg0[32]= max ... . Сборка максимумов
		fp0_lmask = fp1_lmask;
		gr5--;
		fp0_hmask = fp1_hmask;
	if <>0 delayed goto LOOP;
		fpu 0 .double vreg0 = mask ? vreg1:vreg0;		// fpu0 vreg0[32]= maxindex... . Сборка позиций максмумов
		fpu 0 .double vreg1 = vreg1 + .retrive(vreg7);	// fpu0 vreg1[32] = 33,34,45... index inceremnt on +32

	REMAINDER:
	gr7;
	if =0 delayed goto PYRAMID32_MAX;
		gr7--;
		vlen = gr7;
  
	ar5 = min_infinity;
	fpu 1 rep 32 vreg7 = [ar5];						//	fpu1 vreg7[32]=-infinity...
	ar5 = buff;				

	fpu 0 rep vlen vreg6 = [ar0++gr0];				//	fpu0 vreg6[vl]=src...
	fpu 0 .double vreg6 = /vreg6/;					//	fpu0 vreg6[vl]=|src|...
	
	fpu 1 rep 32 [ar5++] = vreg7;					//	buff[32]=-infinity...
	ar5 = buff;				
	fpu 0 rep vlen [ar5++] = vreg6;					//	buff[32]=|src0|,|src1|...,-inf,-inf...


	ar5 = buff;				
	fpu 1 rep 32 vreg1 = [ar5++];					//	fpu1 vreg1[32]=|src0|,|src1|...-inf,-inf...

	//fpu 0 .double vreg1 = vreg1 + .retrive(vreg7);	// 	fpu0 vreg1[32]=32,33,34....
	fpu 1 .double vreg1-vreg0,set mask if >;		//	mask = [src]-

	/////hardware bug in 6407 the last element of mask does not work propraetry
	fp1_lmask = fp1_lmask;
	/////  
	fpu 1 .double vreg0 = mask ? vreg1:vreg0; 		// fpu1 vreg0[32]= max ...

	fp0_lmask = fp1_lmask;
	fp0_hmask = fp1_hmask;
	fpu 0 .double vreg0 = mask ? vreg1:vreg0;		// fpu0 vreg0[32]= maxindex...

	PYRAMID32_MAX:

	/////16
	fpu 1 .packer = vreg0 with .double <= .double;
	fpu 1 rep 16 vreg1 = .packer;
	fpu 1 rep 16 vreg2 = .packer;
	fpu 0 .packer = vreg0 with .double <= .double;
	fpu 0 rep 16 vreg1 = .packer;
	fpu 0 rep 16 vreg2 = .packer;

	fpu 1 .double vreg2-vreg1,set mask if >;
	/////hardware bug in 6407 the last element of mask does not work propraetry
	fp1_lmask = fp1_lmask;
	/////  
	fpu 1 .double vreg1 = mask ? vreg2:vreg1;
	fp0_lmask = fp1_lmask;
	fp0_hmask = fp1_hmask;
	fpu 0 .double vreg1 = mask ? vreg2:vreg1;

	/////8
	fpu 1 .packer = vreg1 with .double <= .double;
	fpu 1 rep 8 vreg1 = .packer;
	fpu 1 rep 8 vreg2 = .packer;
	fpu 0 .packer = vreg1 with .double <= .double;
	fpu 0 rep 8 vreg1 = .packer;
	fpu 0 rep 8 vreg2 = .packer;

	fpu 1 .double vreg2-vreg1,set mask if >;
	/////hardware bug in 6407 the last element of mask does not work propraetry
	fp1_lmask = fp1_lmask;
	/////  
	fpu 1 .double vreg1 = mask ? vreg2:vreg1;
	fp0_lmask = fp1_lmask;
	fp0_hmask = fp1_hmask;
	fpu 0 .double vreg1 = mask ? vreg2:vreg1;
	/////4  
	fpu 1 .packer = vreg1 with .double <= .double;
	fpu 1 rep 4 vreg1 = .packer;
	fpu 1 rep 4 vreg2 = .packer;
	fpu 0 .packer = vreg1 with .double <= .double;
	fpu 0 rep 4 vreg1 = .packer;
	fpu 0 rep 4 vreg2 = .packer;

	fpu 1 .double vreg2-vreg1,set mask if >;
	/////hardware bug in 6407 the last element of mask does not work propraetry
	fp1_lmask = fp1_lmask;
	/////  
	fpu 1 .double vreg1 = mask ? vreg2:vreg1;
	fp0_lmask = fp1_lmask;
	fp0_hmask = fp1_hmask;
	fpu 0 .double vreg1 = mask ? vreg2:vreg1;
	/////2
	fpu 1 .packer = vreg1 with .double <= .double;
	fpu 1 rep 2 vreg1 = .packer;
	fpu 1 rep 2 vreg2 = .packer;
	fpu 0 .packer = vreg1 with .double <= .double;
	fpu 0 rep 2 vreg1 = .packer;
	fpu 0 rep 2 vreg2 = .packer;
	fpu 1 .double vreg2-vreg1,set mask if >;
	/////hardware bug in 6407 the last element of mask does not work propraetry
	fp1_lmask = fp1_lmask;
	/////  
	fpu 1 .double vreg1 = mask ? vreg2:vreg1;
	fp0_lmask = fp1_lmask;
	fp0_hmask = fp1_hmask;
	fpu 0 .double vreg1 = mask ? vreg2:vreg1; 
	/////1
	fpu 1 .packer = vreg1 with .double <= .double;
	fpu 1 rep 1 vreg1 = .packer;
	fpu 1 rep 1 vreg2 = .packer;
	fpu 0 .packer = vreg1 with .double <= .double;
	fpu 0 rep 1 vreg1 = .packer;
	fpu 0 rep 1 vreg2 = .packer;

	fpu 1 .double vreg2-vreg1,set mask if >;
	/////hardware bug in 6407 the last element of mask does not work propraetry
	fp1_lmask = fp1_lmask;
	/////  
	fpu 1 .double vreg1 = mask ? vreg2:vreg1;
	fp0_lmask = fp1_lmask;
	fp0_hmask = fp1_hmask;
	fpu 0 .double vreg1 = mask ? vreg2:vreg1;

	fpu 0 .packer = vreg1 with .fixed_32 .in_low <= .double;
	ar5 = buff;
	fpu rep 1 [ar5] = .packer;
	gr7 = [ar5];
	
//	END:
	return;

//	CASE_WITHOUT_QUTIENT:
//	goto CASE_WITHOUT_QUTIENT;
//	gr7;
//	if =0 delayed goto END;
//		gr7--;
//		vlen = gr7;
//	//ar5 = min_infinity;
//	//fpu 1 rep 32 	vreg7 = [ar5];					// fpu1 verg7[32] =infinity...
//	//fpu 1 rep 32 	vreg7 = [ar0];					// fpu1 verg7[32] =infinity...
//	//fpu 1 .double   vreg0 = vreg7;					// fpu1 verg0[32] =infinity...
//	//return; 
//	//ar5 = buff;
//	////aligting
//	fpu 1 rep vlen vreg7 = [ar0++gr0];				// fpu0 verg7[vl] =src...
//	fpu 1 .double vreg7 = /vreg7/;					// fpu0 verg7[vl] =|src|...
//	
//	//fpu 1 rep 32 [ar5++] = vreg7;					// buff[32] =infinity...
//	//fpu 
//	ar5 = buff;
//	ar0 = ar5;
//	fpu 1 rep vlen [ar5++] = vreg7;					// buff[32] =|src|...,infinity...
//	gr0 = 30;
//	gr0 = gr0-gr7;
//	vlen = gr0;
//	fpu 1 rep vlen vreg6 = [ar0];
//	fpu 1 rep vlen [ar5++] = vreg6;					// buff[32]=|src0|,[src1],|src2|,...,|src0|,|src0|,|src0|
//	
//  
//	ar5 = buff;
//	
//	
//	fpu 1 rep 32 vreg0 = [ar5++];					// fpu1 vreg1[32] =|src|...,infinity...
//	goto PYRAMID32_MAX;
////	
////	fpu 0 .double vreg2 = vreg0;					// fpu0 vreg2[32] = 0,1,2,3...
////	fpu 1 .double vreg1-vreg0,set mask if >;		// fpu1 mask[32] = |src|- (-inf)
/////////hardware bug in 6407 the last element of mask does not work propraetry
////	fp1_lmask = fp1_lmask;
////////
////	fpu 1 .double vreg0 = mask ? vreg1:vreg0; 		// fpu1 vreg0[32] = max
////	fp0_lmask = fp1_lmask;
////	delayed goto PYRAMID32_MAX;
////		fp0_hmask = fp1_hmask;
////		fpu 0 .double vreg0 = mask ? vreg2:vreg0;	// fpu0 vreg0[32] = maxindex...
//
//	CASE_AMMOUNT_EQS_1:
//	delayed return;
//		gr7 = false;
//		nul;  
//		nul;
