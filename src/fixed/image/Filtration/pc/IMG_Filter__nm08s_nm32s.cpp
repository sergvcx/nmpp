//------------------------------------------------------------------------
//
//  $Workfile:: nmppiFilter_8s8s.cpp             $
//
//  <Название библиотеки>
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:40 $
//
//! \if file_doc
//!
//! \file   nmppiFilter_8s8s.cpp
//! \author S. Mushkaev
//! \brief  <Краткое описание>
//!
//! \endif
//!
//------------------------------------------------------------------------

#include "nmpp/nmpli.h"
#include "nmpp/nmtl.h"


void nmppiFilter_8s32s( nm8s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel)
{
	S_nmppiFilterKernel* psKernel=(S_nmppiFilterKernel*) pKernel;
	int nKerWidth =psKernel->nKerWidth;
	int nKerHeight=psKernel->nKerHeight;
	
	//int nKerWidth =((nm32s*)pKernel)[0];
	//int nKerHeight=((nm32s*)pKernel)[1];

	mtr<nm32s> mDst(pDstImg,nHeight,nWidth,nWidth);
	mtr<nm32s> mKer(nKerHeight,nKerWidth);
	mtr<nm32s> mDstWxH(nKerHeight,nKerWidth);

	for(int i=0;i <nKerHeight*nKerWidth; i++)
		//mKer.m_data[i]=((nm32s*)pKernel)[2+i];
		mKer.m_data[i]=psKernel->pWeightMatrix[i];

	for(int y=0; y<nHeight; y++){
        for(int x=0; x<nWidth; x++){
			mtr<nm8s> mSrcWxH(pSrcImg+(y-(nKerHeight>>1))*nWidth+x-(nKerWidth>>1),nKerHeight,nKerWidth,nWidth);
			DotMul(mSrcWxH,mKer,mDstWxH);
			nm32s Sum;
			GetSum(mDstWxH,Sum);
			mDst[y][x]=Sum;
        }
	}
}

