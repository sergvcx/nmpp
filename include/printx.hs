
// Any arguments except gr5 are possible in PRINT_MATRIX_XXX



.macro PRINT_MATRIX_32X text, matrix, height, width
.extern _printMatrix_32x
	skip skip_text\@;
title\@: 
	.ascii \text
skip_text\@:
	push ar5,gr5;
	ar5 = sp;
    sp += 4;
	
	gr5 = \width;
    [ ar5++ ] = gr5;	// width
	
	gr5 = \height; 
	[ ar5++ ] = gr5;	// height
	
	gr5 = \matrix;
	[ ar5++ ] = gr5;	// matrix
	
	gr5 = title\@;
	[ ar5++ ] = gr5;	// text
	gr5 = gr7;
	call _printMatrix_32x;
	sp -=4;
	gr7 = gr5;
	pop ar5,gr5;
.endm 


//.macro PRINT_MATRIX_32S text, matrix, height, width
//	extern _printMatrix_32s:label;
//	own skiptext:label;
//	goto skiptext;
//	own _text		: word[16]=text;	
//	<skiptext>
//	push ar5,gr5;
//	ar5 = sp;
//    sp += 4;
//	
//	gr5 = width;
//    [ ar5++ ] = gr5;	// width
//	
//	gr5 = height; 
//	[ ar5++ ] = gr5;	// height
//	
//	gr5 = matrix;
//	[ ar5++ ] = gr5;	// matrix
//	
//	gr5 = _text;
//	[ ar5++ ] = gr5;	// text
//	
//	gr5 = gr7;
//	call _printMatrix_32s;
//	
//	sp -=4;
//	gr7 = gr5;
//	pop ar5,gr5;
//end PRINT_MATRIX_32S;
//
//
//macro PRINT_MATRIX_16X(text, matrix, height, width)
//	extern _printMatrix_16x:label;
//	own skiptext:label;
//	goto skiptext;
//	own _text		: word[16]=text;	
//	<skiptext>
//	push ar5,gr5;
//	ar5 = sp;
//    sp += 4;
//	
//	gr5 = width;
//    [ ar5++ ] = gr5;	// width
//	
//	gr5 = height; 
//	[ ar5++ ] = gr5;	// height
//	
//	gr5 = matrix;
//	[ ar5++ ] = gr5;	// matrix
//	
//	gr5 = _text;
//	[ ar5++ ] = gr5;	// text
//	
//	gr5 = gr7;
//	call _printMatrix_16x;
//	
//	sp -=4;
//	gr7 = gr5;
//	pop ar5,gr5;
//end PRINT_MATRIX_16X;
//
//
//macro PRINT_MATRIX_16S(text, matrix, height, width)
//	extern _printMatrix_16s:label;
//	own skiptext:label;
//	goto skiptext;
//	own _text		: word[16]=text;	
//	<skiptext>
//	push ar5,gr5;
//	ar5 = sp;
//    sp += 4;
//	
//	gr5 = width;
//    [ ar5++ ] = gr5;	// width
//	
//	gr5 = height; 
//	[ ar5++ ] = gr5;	// height
//	
//	gr5 = matrix;
//	[ ar5++ ] = gr5;	// matrix
//	
//	gr5 = _text;
//	[ ar5++ ] = gr5;	// text
//	
//	gr5 = gr7;
//	call _printMatrix_16s;
//	
//	sp -=4;
//	gr7 = gr5;
//	pop ar5,gr5;
//end PRINT_MATRIX_16S;


#define PRINTF(Format) PRINTF_MACRO Format
#define PRINTF1(Format, Arg) PRINTF1_MACRO Format,Arg
#define PRINTF2(Format, Arg1,Arg2) PRINTF2_MACRO Format,Arg1,Arg2

.macro PRINTF_MACRO format
	push ar5,gr5;
	skip skip_text\@;
format_msg\@:
    .ascii "\format\0"

skip_text\@:
	ar5 = ar7;
    ar7 += 2 with gr5 = false;
	[ ar5++ ] = gr5;	// align stack
	gr5 = format_msg\@;
	[ ar5++ ] = gr5;	
	call _printf with gr5=gr7;
	ar7 -=2 with gr7 = gr5;
	pop ar5,gr5;
.endm


.macro PRINTF1_MACRO format,arg
	push ar5,gr5;
	push ar4,gr4;
	gr4 = \arg;
	skip skip_text\@;
format_msg\@:
    .ascii "\format\0"
	
skip_text\@:
	ar5 = ar7;
    ar7 += 2;
	[ ar5++ ] = gr4;	
	gr5 = format_msg\@;
	[ ar5++ ] = gr5;	
	call _printf with gr5 = gr7;
	ar7 -=2 with gr7 = gr5;
	pop ar4,gr4;
	pop ar5,gr5;
.endm

.macro PRINTF2_MACRO format,arg1,arg2
	push ar5,gr5;
	push ar4,gr4;
	ar4 = \arg1;
	gr4 = \arg2;
	skip skip_text\@;
format_msg\@:
    .ascii "\format\0"
	
skip_text\@:
	ar5 = ar7;
    ar7 += 4;
	gr5 = false;
	[ ar5++ ] = gr5;	
	[ ar5++ ] = gr4;	
	[ ar5++ ] = ar4;	
	gr5 = format_msg\@;
	[ ar5++ ] = gr5;	
	call _printf with gr5 = gr7;
	ar7 -=4 with gr7 = gr5;
	pop ar4,gr4;
	pop ar5,gr5;
.endm
