//------------------------------------------------------------------------
//
//  $Workfile:: GetMax.cp $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.2 $      $Date: 2005/07/13 14:19:56 $
//
//! \if file_doc
//!
//! \file   GetMax.cpp
//! \author S.Mushkaev
//! \brief  Статистические функции.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "rpc/rpc-host.h"
#include "nmpp/nmplv.h"


/////////////////////////////////////////////////////////////////////////////////////////
// Search of maximum value in 8-bit buffer
void nmppsMax_8s7b(
		const	nm8s7b*		pSrcVec,	// input buffer					:long Local [Size/8]
				int			nSize,		// buffer size in 8-bit words	:nSize=[512,768,1024.....]
				int8b*		pMaxValue)	// Maximum
{
	RPC_HOST_PIR("nmppsMax_8s7b",pSrcVec,nSize,pMaxValue,1);
}
/////////////////////////////////////////////////////////////////////////////////////////
// Search of maximum value in 16-bit buffer
void nmppsMax_16s15b(
		const	nm16s15b*		pSrcVec,	// input buffer					:long Local [Size/4]
				int			nSize,		// buffer size in 16-bit words	:nSize=[256,384,512...]
				int16b*		pMaxValue)	// Maximum
{
	RPC_HOST_PIR("nmppsMax_16s15b",pSrcVec,nSize,pMaxValue,2);
}
/////////////////////////////////////////////////////////////////////////////////////////
// Search of maximum value in 32-bit buffer
void nmppsMax_32s31b(
		const	nm32s31b*		pSrcVec,	// input buffer					:long Local [Size/2]
				int			nSize,		// buffer size in 32-bit words	:nSize=[128,192,256..]
				int*		pMaxValue)	// Maximum
{
	RPC_HOST_PIR("nmppsMax_32s31b",pSrcVec,nSize,pMaxValue,4);
}
/////////////////////////////////////////////////////////////////////////////////////////
// Search of maximum value in 64-bit buffer
void nmppsMax_64s63b(
		const	nm64s63b*	pSrcVec,	// input buffer					:long Local [Size/2]
				int			nSize,		// buffer size in 32-bit words	:nSize=[128,192,256..]
				int64b*		pMaxValue)	// Maximum
{
	RPC_HOST_PIR64("nmppsMax_64s63b",pSrcVec,nSize,pMaxValue,8);
}

