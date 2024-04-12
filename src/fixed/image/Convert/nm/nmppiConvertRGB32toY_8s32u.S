#include "nmpp/nmc.hs"
.section ".data.nmpp"
//  0.299=4c8b,    0.587=9646,    0.114=1d2f
rgbMatrY: .quad	\
    0x1d2f,        0x9646,        0x4c8b,        0x0, \
    0x1d2f00000000,0x964600000000,0x4c8b00000000,0x0

.section ".text.nmpp"

.global _nmppiRGB32ToY_8s32u
_nmppiRGB32ToY_8s32u:
	ar5=ar7 - 2 	with gr7=true;
	push ar0,gr0 	with gr7<<=31;

	SET sb,0x2020202  	// 8x8  on X port
	SET nb1,gr7		    // 2x32 on Y port
	ar0 = rgbMatrY;
	rep 8 wfifo=[ar0++],ftw,wtw;
	SET vrl,0x00800000
	SET vrh,0x00800000
	
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
