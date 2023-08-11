//------------------------------------------------------------------------
//
//  $Workfile:: GetMax.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:11 $
//
//! \if file_doc
//!
//! \file   GetMax.asm
//! \author S.Mushkaev
//! \brief  Статистические функции.
//!
//! \endif
//!
//------------------------------------------------------------------------

//#include "vMinMax.h"
import from macros.mlb;
extern	_nmppsTmpBuffer64_G_: long;
extern	_nmppsTmpBuffer16_G_: long;
extern core_MinVal:label;

macro FAST_MIN(r0,r1,rMin)
	with r0=r0-r1;		
	with rMin=r0 A>>31;
	with r0=r0 and rMin;
	with rMin=r0+r1;
end FAST_MIN;



begin ".text.nmpp"


/////////////////////////////////////////////////////////////////////////////////////////


//! \fn void nmppsMin_32s31b(nm32s *pSrcVec, int nSize, int &nMinValue) 
//!
//! \perfinclude _nmppsMin_32s31b.html

global _nmppsMin_32s31b:label;
<_nmppsMin_32s31b>
.branch;
	ar5=ar7 - 2;
	push ar0,gr0;
	push ar4,gr4;
	push ar5,gr5;
	push ar6,gr6;

	ar0 = [--ar5];									// pSrcVec
	gr5 = [--ar5];									// nSize of pSrcVec
	gr6 = [--ar5];									// Pointer to Minimum
	
	gr0 = 2;
	gr4 = 80000000h with gr5 >>=1;					// nSize in 64-bit longs
	nb1 = gr4;
	f1cr= gr4;
	wtw;
	
	ar4= _nmppsTmpBuffer64_G_;
	delayed call core_MinVal;
		ar6=_nmppsTmpBuffer16_G_;								// 2xMinimum

	gr0=[ar6++];
	gr4=[ar6++];
	FAST_MIN(gr0,gr4,gr7);
	[gr6]=gr7;
	pop ar6,gr6;
	pop ar5,gr5;
	pop ar4,gr4;
	pop ar0,gr0;
	
return;
.wait;






	

end ".text.nmpp";
