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

//#include "nmpp/nmpls.h"
//#include "nmpp/nmpli.h"
#include "nmtype.h"
#include "nmpp/iFilter.h"
#include "nmpp/sfir.h"
void nmppiFilter_8s16s( nm8s * pSrcImg, nm16s* pDstImg, int nWidth, int nHeight, NmppiFilterState* pKernel)
{
	nmppsFIR_8s16s(pSrcImg, pDstImg, nWidth*nHeight, (NmppsFIRState*)pKernel);
}



