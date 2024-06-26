//------------------------------------------------------------------------
//
//  $Workfile:: GetMin.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2005/07/13 14:19:56 $
//
//! \if file_doc
//!
//! \file   
//! \author S.Mushkaev
//! \brief  Статистические функции.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vMinMin.h"
//import from "nmpp/macros.mlb";
extern	_nmppsTmpBuffer64_G_: long;
extern	_nmppsTmpBuffer16_G_: long;
extern core_MinVal:label;


begin ".text.nmpp"


/////////////////////////////////////////////////////////////////////////////////////////


//! \fn void nmppsMin_64s63b(nm64s63b *pSrcVec, int nSize, int64b &nMinValue) 
//!
//! \perfinclude _nmppsMin_64s63b.html

global _nmppsMin_64s63b:label;
<_nmppsMin_64s63b>
.branch;
	ar5=ar7 - 2;
	push ar0,gr0;
	push ar4,gr4;
	push ar5,gr5;
	push ar6,gr6;

	ar0 = [--ar5];									// pSrcVec
	gr5 = [--ar5];									// nSize of pSrcVec (nSize in 64-bit longs)
	ar6 = [--ar5];									// Pointer to Minimum
	
	gr0 = 2;
	gr4 = 0h;									
	nb1 = gr4;
	f1crh= 80000000h;
	f1crl= 00000000h;
	wtw;
	
	delayed call core_MinVal;
		ar4= _nmppsTmpBuffer64_G_;

	pop ar6,gr6;
	pop ar5,gr5;
	pop ar4,gr4;
	pop ar0,gr0;
	
return;
.wait;






	

end ".text.nmpp";
