//------------------------------------------------------------------------
//
//  $Workfile:: 32Clc.cp $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:16 $
//
//! \if file_doc
//!
//! \file   32Clc.cpp
//! \author S.Mushkaev
//! \brief  Функции подсчета циклического кода для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------
extern unsigned int CRC32_Table[];
//#include "vcrc.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned nmppsCrcAcc_32f(
    const float * pSrcVec, // Input Vector			:long Any[Size/2]
	int numBitsToClear,
    int nSize,             // Vector size        	:[0,1,2...]
    unsigned int* crcAccumulator     // Init/Output crc
    )
       
{
	unsigned* pTable=CRC32_Table; 
    unsigned a,b;
	int i;

    
	unsigned rounder=1<<numBitsToClear;
	unsigned mask=~(rounder-1);
	unsigned *p=(unsigned*)pSrcVec;
	for( i = 0; i < nSize; i++ )
    {
		unsigned v=p[i];
		//unsigned mantissa=v&0x7FFFFF;
		//unsigned nearzero=(mantissa+rounder)&0x80000000;
		//mask=mask&(~nearzero);
		a = (v+rounder)&mask;
		
        b = a & 0x000000FF;
        *crcAccumulator = ( *crcAccumulator >> 8 ) ^ pTable[( b ^ ( *crcAccumulator & 0x000000FF ) )];
        b = ( a >> 8 ) & 0x000000FF;
        *crcAccumulator = ( *crcAccumulator >> 8 ) ^ pTable[( b ^ ( *crcAccumulator & 0x000000FF ) )];
        b = ( a >> 16 ) & 0x000000FF;
        *crcAccumulator = ( *crcAccumulator >> 8 ) ^ pTable[( b ^ ( *crcAccumulator & 0x000000FF ) )];
        b = ( a >> 24 ) & 0x000000FF;
        *crcAccumulator = ( *crcAccumulator >> 8 ) ^ pTable[( b ^ ( *crcAccumulator & 0x000000FF ) )];
    }
    *crcAccumulator = ~ *crcAccumulator;
	return *crcAccumulator;
}


