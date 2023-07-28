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

#include "rpc/rpc-nmc.h"
#include "nmpp.h"

void rpc_nmppsDotProd_8s32sm(void *in, void *out) 
{ 
	aura_buffer buf_src0 = aura_get_buf(); 
	aura_buffer buf_src1 = aura_get_buf(); 
	int *src0  = aura_buffer_to_ptr(buf_src0); 
	int *src1  = aura_buffer_to_ptr(buf_src1); 
	unsigned size = aura_get_u32(); 
	long long dst;
	int err = nmppsDotProd_8s32sm ((const nm8s*) src0,(const nm32s*) src1, size, &dst,0);
	aura_put_u64(dst);
	aura_put_u32(err);
}