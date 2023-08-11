//------------------------------------------------------------------------
//
//  $Workfile:: Access.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:11 $
//
//! \if file_doc
//!
//! \file   Access.asm
//! \author S.Mushkaev
//! \brief  Функции доступа для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vClip.h"



begin ".text.nmpp"

  
    //--------------------------------------------------------------------
    //! \fn nm32s * nmppsAddr_32s(nm32s *pVec, int nIndex) 
	//!
	//! \perfinclude _nmppsAddr_32s.html
    //--------------------------------------------------------------------

    
global _nmppsAddr_32s:label;
<_nmppsAddr_32s>
.branch;
	ar5 = ar7 - 2 with gr7=gr5;	
delayed return;
	ar5,gr5 = [--ar5];
	nul;
	ar5+=gr5 with gr5=gr7;
return;
.wait;


end ".text.nmpp";

