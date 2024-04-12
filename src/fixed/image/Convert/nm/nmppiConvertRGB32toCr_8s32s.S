#include "nmpp/nmc.hs"
.section ".data.nmpp"
rgbMatrCr: .quad \
	0x000000008000,0x00000000ffff8bba,0x00000000fffff446, 0x0, \
    0x800000000000,0xffff8bba00000000,0xfffff44600000000, 0x0

.section ".text.nmpp"

.global _nmppiRGB32ToCr_8s32s
_nmppiRGB32ToCr_8s32s:
	ar5=ar7 - 2 	with gr7=true;
	push ar0,gr0 	with gr7<<=31;

	SET sb,0x2020202  	// 8x8  on X port
	SET nb1,gr7		    // 2x32 on Y port
	ar0 = rgbMatrCr;
	rep 8 wfifo=[ar0++],ftw,wtw;
	SET vr,0
	//SET vrh,0
	
	push ar5,gr5;
	push ar6,gr6;
	ar0=[--ar5] with gr0 = gr7>>30;	// SRC: bytes b,g,r,0	gr0=2
	ar6=[--ar5] with gr6 = gr0;		// Dst					gr6=2

	delayed call core_vsum_data_vr;
		gr5=[--ar5];				// nSize
		gr5>>=1;
	pop ar6,gr6;
	pop ar5,gr5; 
	pop ar0,gr0;
  return;
