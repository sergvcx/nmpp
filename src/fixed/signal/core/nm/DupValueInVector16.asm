//------------------------------------------------------------------------
//
//  $Workfile:: DupValueInVector16.as $
//
//  Neuro Matrix Performance Primitives
//
//  Copyright (c) RC Module
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:05 $
//
//! \if file_doc
//!
//! \file   DupValueInVector16.asm
//! \author Сергей Ландышев
//! \brief  Функции векторного ядра.
//!
//! \endif
//!
//------------------------------------------------------------------------
begin ".text_nmvcore"
    //--------------------------------------------------------------------
    // Вход:
    //      ar1 - Вектор.
    //      gr1 - значение (16 бит).
    // Изменяет регистры: ar1.
    //--------------------------------------------------------------------
global nmppsDupValueInVector16_: label;
<nmppsDupValueInVector16_>
    push ar0, gr0 with gr0 = gr1 << 16;
    gr1 = gr0 >> 16;
    pop ar0, gr0 with gr1 = gr0 or gr1;
    delayed return;
        [ar1++] = gr1;
        [ar1++] = gr1 with gr1 >>= 16;
    //--------------------------------------------------------------------
end ".text_nmvcore";