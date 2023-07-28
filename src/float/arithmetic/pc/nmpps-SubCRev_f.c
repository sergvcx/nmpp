//------------------------------------------------------------------------
//
//  $Workfile:: SubC.cpp  $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! \if file_doc
//!
//! \file   SubC_f.cpp
//! \author Иван Жиленков
//! \brief  Арифметические функции 
//!
//! \endif
//!
//------------------------------------------------------------------------


#include "nmtype.h"


void nmppsSubCRev_32f(const nm32f* pSrcVec, nm32f* pDstVec, float C, int nSize){
	int i;
	for(i=0;i<nSize;i++){
		pDstVec[i] = C - pSrcVec[i];
	}	
}
