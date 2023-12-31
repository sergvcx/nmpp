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
    //! \fn nm16s * nmppsAddr_16s(nm16s *pVec, int nIndex) 
	//!
	//! \perfinclude _nmppsAddr_16s.html
    //--------------------------------------------------------------------
    

global _nmppsAddr_16s:label;
<_nmppsAddr_16s>
.branch;
	ar5 = ar7 -4 with gr7=gr5;	
	gr5 = [ar5++];
	ar5 = [ar5++] with gr5 A>>=1;
delayed return;
	nul;
	ar5+=gr5   with gr5 = gr7;
	nul;
return;
.wait;

 


end ".text.nmpp";

