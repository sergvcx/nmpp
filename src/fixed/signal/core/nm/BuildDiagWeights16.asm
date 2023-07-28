//------------------------------------------------------------------------
//
//  $Workfile:: BuildDiagWeights16.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:05 $
//
//! \if file_doc
//!
//! \file   BuildDiagWeights16.asm
//! \author Сергей Ландышев
//! \brief  Функции векторного ядра.
//!
//! \endif
//!
//------------------------------------------------------------------------
begin ".text_nmvcore"
    //--------------------------------------------------------------------
    // Вход:
    //      ar1 - Буфер весов.
    //      gr1 - значение (16 бит).
    // Изменяет регистры: ar1.
    //--------------------------------------------------------------------
global nmppsBuildDiagWeights16_: label;
<nmppsBuildDiagWeights16_>
    push ar0, gr0 with gr0 = false;
    ar0 = gr0 with gr1 <<= 16;
    gr0 = gr1 >> 16;
    [ar1++] = gr0 with gr1 = gr0;
    [ar1++] = ar0 with gr0 <<= 16;
    [ar1++] = gr0;
    [ar1++] = ar0 with gr0 >>= 16;
    [ar1++] = ar0, gr0 with gr0 <<= 16;
    [ar1++] = ar0, gr0;
    pop ar0, gr0;
    return;
    //--------------------------------------------------------------------
end ".text_nmvcore";