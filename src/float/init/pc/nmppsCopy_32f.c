//------------------------------------------------------------------------
//
//  $Workfile:: Copy.cp $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! if file_doc
//!
//! file   Copy.cpp
//! author S.Mushkaev
//! brief  Функции инициализации и копирования для векторов.
//!
//! endif
//!
//------------------------------------------------------------------------
//#include "Vector.h"
#include "nmpp.h"
#include "memory.h"


void nmppsCopyOddToOdd_32f(const float* pSrcVec, float* pDstVec, int size)
{
	memcpy(pDstVec,pSrcVec,size*4);
}

void nmppsCopyEvenToOdd_32f(const float* pSrcVec, float* pDstVec, int size)
{
	memcpy(pDstVec,pSrcVec,size*4);
}

void nmppsCopyOddToEven_32f(const float* pSrcVec, float* pDstVec, int size)
{
	memcpy(pDstVec,pSrcVec,size*4);
}

void nmppsCopyEvenToEven_32f(const float* pSrcVec, float* pDstVec, int size)
{
	memcpy(pDstVec,pSrcVec,size*4);
}

