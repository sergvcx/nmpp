//------------------------------------------------------------------------
//
//  $Workfile:: Init.cp $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! \if file_doc
//!
//! \file   Init.cpp
//! \author S.Mushkaev
//! \brief  Функции инициализации и копирования для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmpp.h"
////////////////////////////////////////////////////////////////////////////
//  Setting all 64-bit elements of Buffer to const value given by InitValue
void nmppsSet_64sp(nm64s*	Buffer,		// Destination array					:long Global [SizeInt64]
		nm64s*		InitValue,	// Init value
		int			SizeInt64	// nSize of Source array in 64-bit ints; :SizeInt32= [0,1,2,...]
		)
{
	int i;
	for(i=0;i<SizeInt64;i++)
		Buffer[i]=(*InitValue);
}

//void nmppsSet_(
//		nm64s*		Buffer,		// Destination array					:long Global [SizeInt64]
//		nm64s		InitValue,	// Init value
//		int			SizeInt64	// nSize of Source array in 64-bit ints; :SizeInt32= [0,1,2,...]
//		)
//{
//	int i;
//	for(i=0;i<SizeInt64;i++)
//		Buffer[i]=InitValue;
//}


////////////////////////////////////////////////////////////////////////////
//  Setting all 32-bit elements of Buffer to const value given by InitValue
void nmppsSet_32s(int		InitValue,	// Init value 
		nm32s*	Buffer,		// Destination array					:long Global [SizeInt32/2]
		int		SizeInt32	// nSize of Source array in 32-bit ints; :SizeInt32= [0,2,4...]
		)
{
	int i;
	for(i=0;i<SizeInt32;i++)
		Buffer[i]=InitValue;
}

////////////////////////////////////////////////////////////////////////////
//  Setting all 16-bit elements of Buffer to const value given by InitValue
void nmppsSet_16s(int		InitValue,	// Init value 
		nm16s*	Buffer,		// Destination array					:long Global [SizeInt16/4]
		int		SizeInt16	// nSize of Source array in 16-bit shorts:SizeInt16= [0,4,8,...]
		)
{
	int i;
	for(i=0;i<SizeInt16;i++)
		Buffer[i]=InitValue;
}


////////////////////////////////////////////////////////////////////////////
//  Setting all 8-bit elements of Buffer to const number given by InitValue
void nmppsSet_8s(int		InitValue,	// Init value
		nm8s*	Buffer,		// Destination array					:long Global [SizeInt8/8]		
		int		SizeInt8	// nSize of Source array in 8-bit chars; :SizeInt8=  [0,8,16....]
		)
{
	int i;
	for(i=0;i<SizeInt8;i++)
		Buffer[i]=InitValue;
}


