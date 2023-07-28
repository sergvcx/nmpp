//------------------------------------------------------------------------
//
//  $Workfile:: CompareMin.asm     $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:05 $
//
//! \if file_doc
//!
//! \file   Math_CompareMin.asm
//! \author S. Mushkaev
//! \brief  Функции векторного ядра.
//!
//! \endif
//!
//------------------------------------------------------------------------

begin ".text_nmvcore"



    //------------------------------------------------------------------------
    //! \fn void core_CompareMinNV(nmreg nb1, nmreg f1cr, nmreg ar0, nmreg gr0, nmreg ar1, nmreg gr1, nmreg ar3, nmreg gr3, nmreg gr4, nmreg gr5, nmreg ar6, nmreg gr6);
    //!
    //------------------------------------------------------------------------
	// ar0 - список массивов
	// gr0 - число массивов 
	// gr1 - шаг чтения 
	// gr5 - длина массивов
	// ar6 - выходной массив 
	// gr6 - шаг записи
	
	// изменяет *:
	//  ar0, gr0*
	//  ar1, gr1 
	//  ar2, gr2 
	//  ar3, gr3 
	//  ar4, gr4 
	//  ar5, gr5 
	//  ar6* gr6
	
global core_CompareMinNV :label;
<core_CompareMinNV>
.wait;
	push ar0,gr0 with gr0--;
	push ar1,gr1 with gr0--;
	push ar2,gr2 with gr2 = false; 	// смещение , кол-во уже прочитанных 32-р слов.
	push ar3,gr3 with gr3 = gr1;	// const
	push ar4,gr4 with gr4 = false; 
	push ar5,gr5 with gr4++; 		//with gr2=gr5<<27 ;	 // reserved
	with gr4=gr1<<5;				// смещение из 32 шагов
	with gr5>>=5;
	
	<next_CompareMin_rep32>
		push ar0,gr0;			// сохраняем указатель на таблицу указателей и счетчик  массивов
		ar2=[ar0++];			// читаем указатель на первый массив
		ar1=ar2+gr2;
		rep 32 ram=[ar1++gr1];	// читаем первый массив
		
		<nextArray>
			ar2 = [ar0++];			// берем следующий указатель
			ar1 = ar2+gr2;
			ar3 = ar1 with gr0--; 	// уменьшаем счетчик массивов
			rep 32 data=[ar1++gr1]	with ram-data;
			rep 32					with activate afifo;
		if <>0 delayed goto nextArray;		
			rep 32 data=[ar3++gr3]	with mask afifo,ram,data;			
			rep 32 [ar6],ram= afifo;
		
		ar2 = [ar0++];
		ar1 = ar2+gr2 with gr2 += gr4;
		ar3 = ar1 with gr5--;
		rep 32 data=[ar1++gr1]	with ram-data;
		rep 32					with activate afifo;
		pop ar0,gr0;			// восстанвливаем указатель на таблицу указателей и счетчик  массивов
	if <>0 delayed  goto next_CompareMin_rep32;
		rep 32 data=[ar3++gr3]	with mask afifo,ram,data;			
		rep 32 [ar6++gr6]= afifo;

	pop ar5,gr5;
	pop ar4,gr4;
	pop ar3,gr3;
	pop ar2,gr2;
	pop ar1,gr1;
	pop ar0,gr0;
	
return;	
.wait;




end ".text_nmvcore";
