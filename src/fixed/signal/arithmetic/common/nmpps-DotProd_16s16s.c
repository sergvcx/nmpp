//------------------------------------------------------------------------
//
//  $Workfile:: Mul_VxxVxx.cp $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! \if file_doc
//!
//! \file   Mul_VxxVxx.cpp
//! \author S.Mushkaev
//! \brief  Функции умножения для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmpp/nmplv.h"
#include "nmpp/malloc32.h"

int nmppsDotProd_16s16sm(
	const nm16s*		srcVec0,	//Input0 buffer		:long Local [Size].
	const nm16s*		srcVec1,	//Input1 buffer		:long Global[Size].
	int			size,		//Size of input vec
	nm64s*		dst,		//Output product
	nm64s*		tmp			//temporary buffer nm64s[size]
	)
{
	int alloc=0;
	if (tmp==0){
		tmp = nmppsMalloc_64s(size);
		if (tmp==0) return -1;
		alloc=1;
	}
	
	nmppsConvert_16s64s(srcVec1,tmp,size);
	nmppsDotProd_16s64s(srcVec0,tmp,size,dst);
	
	if (alloc)	
		nmppsFree(tmp);
	return 0;
}