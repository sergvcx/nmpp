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


begin ".text.nmpp"

    //--------------------------------------------------------------------
    //! \fn void nmppsSet_64sp(int64b *nVal,nm64s *pVec, int nSize) 
    //--------------------------------------------------------------------

global _nmppsSet_64sp:label;
<_nmppsSet_64sp>
.branch;
    ar5 = ar7 - 2	with gr7=false;
    push ar0,gr0	with gr7++;
	push ar5,gr5	with gr7++;
	push ar6,gr6	with gr6=gr7;
	ar0 = [--ar5];				// *Init value(Hi|Lo)
	delayed call core_ram;
		ar6 = [--ar5];			// Buffer
		gr5 = [--ar5];			// nSize
		nul;

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar0,gr0;
	return;
.wait;



end ".text.nmpp";