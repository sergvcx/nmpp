//------------------------------------------------------------------------
//
//  $Workfile:: mtrInit.cp $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:05:15 $
//
//! \if file_doc
//!
//! \file   mtrInit.cpp
//! \author S.Mushkaev
//! \brief  Функции инициализации и копирования для матриц.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmtype.h"

void MTR_Fill(nm8s* pMtr,  char nVal, int nMtrStride, int nMtrHeight, int nMtrWidth)
{
	for(int r=0;r<nMtrHeight; r++)
		for(int c=0;c<nMtrWidth;c++)
			pMtr[r*nMtrStride+c]=nVal;
}



