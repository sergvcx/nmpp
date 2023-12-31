//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640x Software, 2018                */
//*                                                                         */
//*   Software design:  A.Brodyazhenko                                      */
//*                                                                         */
//*   File:             core_nmppsConvert_32f32s_truncate.asm               */
//*   Contents:         Convert a data array from nm32f to nm32s            */
//*						truncate(nm32f) -> nm32s							*/
//*	  This function has a register interface.								*/
//*	  Prototype: void core_nmppsConvert_32f32s_truncate(ar0, ar1, gr0);	    */
//*   ar0 - address of input  array nm32f	                                */
//*   ar1 - address of output array nm32s	                                */
//*   gr0 - input and output arrays size	                                */
//*   ar2 - input  scale factor - power of two                              */
//***************************************************************************/
.data 

.align 8
	half_one: .float 0.5, 0.5
	half_4999: .int  0x3effffff, 0x3effffff
	zeros: .float 0.0, 0.0

//nobits "data2"
	scale_factor: .float 0,0 
	// word[2];
//end "data2";

.global core_nmppsConvert_32f32s_truncate

.text
core_nmppsConvert_32f32s_truncate:

// ATTENTION : 
//set fp_round_to_nearest; //(RND_00) – установка режима округления к ближайшему;
set fp_round_down; //(RND_01) – установка режима округления к меньшему;
//set fp_round_up; //(RND_10) – установка режима округления к большему;
//set fp_round_to_zero; //(RND_11) – установка режима округления к меньшему по модулю;


	ar2 = ar2 + 127;
	gr2 = ar2;
	gr2 <<= 23;
	ar2 = scale_factor;
	[ar2++] = gr2;
	[ar2++] = gr2;
	ar2 = ar2 - 2;
	fpu 0 rep 1 vreg3 = [ar2];

	ar2 = zeros;

	fpu 0 rep 1 vreg1 = [ar2];

	ar2 = half_one;

	fpu 0 rep 32 vreg0 = [ar2];

	ar2 = half_4999;

	fpu 0 rep 32 vreg5 = [ar2];


	gr1 = gr0 >> 6;
	if =0 goto Packing_32f32s_less64_truncate;




Packing_32f32s_truncate:
	//fpu 0 .float vreg0 = /vreg0/; 	// load 0.5
	fpu 0 .float vreg4 = vreg0;				
	fpu 0 rep 32 vreg2 = [ar0++];	// load src vec
	fpu 0 .float vreg2 - .retrive(vreg1), set mask if <;	//src[i] - 0  , get sign of src[i]
	//fpu 0 .float vreg0 = mask ? -vreg0 : vreg0;				// form  ( 0.5 | -0.5) vector
	//fpu 0 .float vreg2 = vreg2 * .retrive(vreg3) - vreg0;

	//  код для исправления аппаратной ошибки №5 процессора 6407
	// 	#define ALL_FPU_ANTI_MASK       
	#if NMC_CORE_VERSION > NM6407
	#else
	fp0_lmask = fp0_lmask;  
	#endif

	
	fpu 0 .float vreg4 = mask ? - vreg5 : vreg4;				// form  ( 0.5 | -0.5) vector
	fpu 0 .float vreg2 = vreg2 * .retrive(vreg3) - vreg4;
	gr1--;
	if > delayed goto Packing_32f32s_truncate;
		fpu 0 .packer = vreg2 with .fixed_32 <= .float;
		fpu rep 32 [ar1++] = .packer;

	gr0 = gr0 << 26;				 	// computing a remainder
	gr0 = gr0 >> 26;					// computing a remainder
	if =0 goto exit_Conv32f32s_truncate;

Packing_32f32s_less64_truncate:			    // N < 64
	gr0 = gr0 >> 1;
	gr0--;
	vlen = gr0;
	ar2 = half_4999;
	fpu 0 rep vlen vreg5 = [ar2];
	ar2 = half_one;
	fpu 0 rep vlen vreg0 = [ar2];
	fpu 0 .float vreg4 = vreg0;
	fpu 0 rep vlen vreg2 = [ar0++];
	fpu 0 .float vreg2 - .retrive(vreg1), set mask if <;

	//  код для исправления аппаратной ошибки №5 процессора 6407
	// 	#define ALL_FPU_ANTI_MASK       
	#if NMC_CORE_VERSION > NM6407
	#else
	fp0_lmask = fp0_lmask;  
	#endif

	fpu 0 .float vreg4 = mask ? -vreg5 : vreg4;
	fpu 0 .float vreg2 = vreg2 * .retrive(vreg3) - vreg4;
	fpu 0 .packer = vreg2 with .fixed_32 <= .float;
	fpu rep vlen [ar1++] = .packer;

exit_Conv32f32s_truncate:
	delayed return;
		set fp_round_to_nearest; //(RND_00) – установка режима округления к ближайшему;
		nul;
		nul;
//end ".text_nmplv";
