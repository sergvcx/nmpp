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
    //! \fn nm8s * nmppsAddr_8s(nm8s *pVec, int nIndex) 
	//!
	//! \perfinclude _nmppsAddr_8s.html
    //--------------------------------------------------------------------
	   
global nmppsAddr_8s :label;
<nmppsAddr_8s>
.branch;
	ar5 = ar7 -4 with gr7=gr5;	
	gr5 = [ar5++];
	ar5 = [ar5++] with gr5 A>>=2;
delayed return;
	nul;
	ar5+=gr5   with gr5 = gr7;
	nul;
.wait;

  

end ".text.nmpp";

