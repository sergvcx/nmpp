//------------------------------------------------------------------------
//
//  $Workfile:: FilterWxH.cp $
//
//  Библиотека обработки изображений
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:38 $
//
//! \if file_doc
//!
//! \file   Convert16_WxH.cpp
//! \author S. Mushkaev
//! \brief  Функции векторного ядра.
//! 
//! \endif
//!
//------------------------------------------------------------------------

#include "nmpp/nmpls.h"
#include "nmpp/nmpli.h"

extern "C"{
	
void nmppiFilter_8s32s( nm8s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel)
{
	//SIG_Filter(pSrcImg, pDstImg, nWidth*nHeight, pKernel);
	nmppsFIR_8s32s(pSrcImg, pDstImg, nWidth*nHeight, pKernel);
	
}

};
