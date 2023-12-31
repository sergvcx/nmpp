///////////
// nmblas (neiro matrix Basic Linear Algebra Subroutines)
//  Copyright (c) RC Module

// Author : Alexandr Bolotnikov 
// Originaly developed at reserch center "Module" Moscow 
// Year 2017 
///////////
//The purpose of this function see in nmblas_dsdot.s file 


global _fpu_dsdot:label;

data "data"
  .align;
  zero_: long = double(0);
end "data";

nobits "nobits"
  .align;
  buff : long;
end "nobits";

begin "text"
<_fpu_dsdot>
  gr5;
  if <= delayed goto END;//return 0 in case wrong parametr was exsepted
  gr7=false;
  gr6=gr7;

  ar5 = zero_;
  gr7 = gr5<<26;
  gr7 = gr7>>26;
  gr5 = gr5>>6;
  //vreg 0,vreg1 coupled register for x 
  //vreg 2,vreg3 coupled register for y
  //vreg6 is a accomulator 
  
  if =0 delayed goto REMAINDER;
  fpu 0 rep 1 vreg6 = [ar5];
  //initialisation to apply mulltiply accomulate ferter
  gr5--;
  fpu rep 32 .packer = [ar0++] with .double <= .float;//load x
  fpu 0 rep 32 (vreg0,vreg1) = .packer;
  fpu rep 32 .packer = [ar1++] with .double <= .float;//load y  
  fpu 0 rep 32 (vreg2,vreg3) = .packer;
  
  if = 0 delayed goto UNROULING;
  fpu 0 .double vreg4 = vreg0*vreg2;
  fpu 0 .double vreg5 = vreg1*vreg3;

<LOOP>
  gr5--;
  fpu rep 32 .packer = [ar0++] with .double <= .float;//load x
  fpu 0 rep 32 (vreg0,vreg1) = .packer;
  fpu rep 32 .packer = [ar1++] with .double <= .float;//load y  
  fpu 0 rep 32 (vreg2,vreg3) = .packer;
  
  if <>0 delayed goto LOOP;
  fpu 0 .double vreg4 = vreg0*vreg2 + vreg4;
  fpu 0 .double vreg5 = vreg1*vreg3 + vreg5;

<UNROULING>
  fpu 0 .double  vreg6 = vreg4 + vreg5;

  fpu 0 .packer = vreg6 with .fixed_64 <= .fixed_64;
  fpu 0 rep 16 vreg0 = .packer;
  fpu 0 rep 16 vreg1 = .packer;
  fpu 0 .double vreg6 = vreg0 + vreg1;
  
  fpu 0 .packer = vreg6 with .fixed_64 <= .fixed_64;
  fpu 0 rep 8 vreg0 = .packer;
  fpu 0 rep 8 vreg1 = .packer;
  fpu 0 .double vreg6 = vreg0 + vreg1;

  fpu 0 .packer = vreg6 with .fixed_64 <= .fixed_64;
  fpu 0 rep 4 vreg0 = .packer;
  fpu 0 rep 4 vreg1 = .packer;
  fpu 0 .double vreg6 = vreg0 + vreg1;
  
  fpu 0 .packer = vreg6 with .fixed_64 <= .fixed_64;
  fpu 0 rep 2 vreg0 = .packer;
  fpu 0 rep 2 vreg1 = .packer;
  fpu 0 .double vreg6 = vreg0 + vreg1;
  
  fpu 0 .packer = vreg6 with .fixed_64 <= .fixed_64;
  fpu 0 rep 1 vreg0 = .packer;
  fpu 0 rep 1 vreg1 = .packer;
  fpu 0 .double vreg6 = vreg0 + vreg1;

<REMAINDER>  
  gr7;
  if =0 delayed goto CONVERTATION_AND_ADDITION_B;
  gr5 = gr7>>1;
  gr5-- noflags;
  if =0 delayed goto CASE_N_EQ_ONE; 
  vlen = gr5;
  nop;
  
  fpu rep vlen .packer = [ar0++] with .double <= .float;//load x
  fpu 0 rep vlen (vreg0,vreg1) = .packer;
  fpu rep vlen .packer = [ar1++] with .double <= .float;//load y  
  fpu 0 rep vlen (vreg2,vreg3) = .packer;

  fpu 0 .double vreg4 = vreg0*vreg2;
  fpu 0 .double vreg5 = vreg1*vreg3;
  fpu 0 .double vreg4 = vreg4 + vreg5;
  
  gr5;
<LOOP_REMINDER>
  if <>0 delayed goto LOOP_REMINDER;
  fpu 0 .double vreg6 = vreg6 + .retrive(vreg4); 
  gr5--;  

  gr5 = gr7<<31;

  if =0 delayed goto CONVERTATION_AND_ADDITION_B;
<CASE_N_EQ_ONE>  
  fpu  rep 1 .packer = [ar0++] with .double <= .float .in_low;
  fpu 0 rep 1 vreg0 = .packer;
  fpu  rep 1 .packer = [ar1++] with .double <= .float .in_low;
  fpu 0 rep 1 vreg2 = .packer;
  fpu 0 .double vreg6 = vreg0*vreg2 + vreg6;

<CONVERTATION_AND_ADDITION_B> 
  .align;
  ar5 = buff;
  fpu 0 rep 1 [ar5] = vreg6;
  //gr6 = 40590000h;
  //gr7 = false;
  gr7 = [ar5++];
  gr6 = [ar5];
<END> 
  return;

end "text";