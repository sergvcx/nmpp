//------------------------------------------------------------------------
//
//  $Workfile:: pcCompare.cp $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! \if file_doc
//!
//! \file   pcCompare.cpp
//! \author Иван Жиленков
//! \brief  Функции сравнения.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmpp/nmplv.h"


///////////////////////////////////////////////////////////////////////////////
//	Performs logic activation of 64-bit elements by setting 
//	positive numbers to "-1" and negative numbers to "0"
void nmppsCmpGt0_64s(
	const nm64s*	pSrcVec,		// Input Buffer
	nm64s*	pDstVec,		// Output Buffer
	int			nSize		// size of input buffer in 64 bit elements. nSize={1,2,..,n}
	)
{
	int i;
	for (i=0; i<nSize; i++)
		pDstVec[i]= (pSrcVec[i] > 0) ? -1: 0;

}
///////////////////////////////////////////////////////////////////////////////
//	Performs logic activation of 32-bit elements by setting 
//	positive numbers to "-1" and negative numbers to "0"
void nmppsCmpGt0_32s(
	const nm32s*		pSrcVec,		// Input Buffer
	nm32s*		pDstVec,		// Output Buffer
	int			nSize		// size of input buffer in 32 bit elements. nSize={2,4,..,n*2}
	)
{
	int i;
	for (i=0; i<nSize; i++)
		pDstVec[i]= (pSrcVec[i] > 0) ? -1: 0;
}
///////////////////////////////////////////////////////////////////////////////
//	Performs logic activation of 16-bit elements by setting 
//	positive numbers to "-1" and negative numbers to "0"
void nmppsCmpGt0_16s(
	const nm16s*		pSrcVec,		// Input Buffer
	nm16s*		pDstVec,		// Output Buffer
	int			nSize		// size of input buffer in 16 bit elements. nSize={4,8,..,n*4}
	)
{
	int i;
	for (i=0; i<nSize; i++)
		pDstVec[i]= (pSrcVec[i] > 0) ? -1: 0;
}
///////////////////////////////////////////////////////////////////////////////
//	Performs logic activation of 8-bit elements by setting 
//	positive numbers to "-1" and negative numbers to "0"
void nmppsCmpGt0_8s(
	const nm8s*		pSrcVec,		// Input Buffer
	nm8s*		pDstVec,		// Output Buffer
	int			nSize		// size of input buffer in 8 bit elements. nSize={8,16,..,n*8}
	)
{
	int i;
	for (i=0; i<nSize; i++)
		pDstVec[i]= (pSrcVec[i] > 0) ? -1: 0;
}

