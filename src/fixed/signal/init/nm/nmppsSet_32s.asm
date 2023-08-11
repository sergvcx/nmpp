//------------------------------------------------------------------------
//
//  $Workfile:: Init.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:08 $
//
//! \if file_doc
//!
//! \file   Init.asm
//! \author S.Mushkaev
//! \brief  Функции инициализации и копирования для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vMinMax.h"

extern core_ram:label;

extern _nmppsTmpBuffer16_G_:long;

begin ".text.nmpp"

   //--------------------------------------------------------------------
    //! \fn void nmppsSet_32s( int32b nVal, nm32s *pVec,int nSize) 
    //--------------------------------------------------------------------

global _nmppsSet_32s:label;
<_nmppsSet_32s>
.branch;
    ar5 = ar7 - 2	with gr7=false;
    push ar0,gr0	with gr7++;
	push ar5,gr5	with gr7++;
	push ar6,gr6	with gr6=gr7;

	gr0 = [--ar5];			// Init value
    ar6 = [--ar5];			// Buffer
    gr5 = [--ar5];			// nSize
	ar0 = _nmppsTmpBuffer16_G_+2;
	delayed call core_ram with gr5 >>=1;
		[--ar0] = gr0;
		[--ar0] = gr0;

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
	return;
.wait;
	



end ".text.nmpp";