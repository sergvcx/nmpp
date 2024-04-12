#include "nmpp/nmc.hs"
.section ".data.nmpp"
rgbMatrCb: .quad \
	0x00000000ffffe2aa,0x00000000ffff9d56,0x000000008000, 0x0, \
    0xffffe2aa00000000,0xffff9d5600000000,0x800000000000, 0x0
RamL: .quad 0x8080808080808080

.section ".text.nmpp"

.global _nmppiRGB32ToY_8u32s
_nmppiRGB32ToY_8u32s:
	ar5=ar7 - 2 	with gr7=true;
	push ar0,gr0 	with gr7<<=31;

	SET sb,0x2020202  	// 8x8  on X port
	SET nb1,gr7		    // 2x32 on Y port
	ar0 = rgbMatrCb;
	rep 8 wfifo=[ar0++],ftw,wtw;
	SET vr,0
	//SET vrh,0
	
	push ar5,gr5;
	push ar6,gr6;
	ar0=[--ar5] with gr0 = gr7>>30;	// SRC: bytes b,g,r,0	gr0=2
	ar6=[--ar5] with gr6 = gr0;		// Dst					gr6=2
	gr5=[--ar5];					// nSize
	

	delayed call core_xor_vsum_data_vr with gr5>>=1;
		ar5=RamL;
	pop ar6,gr6;
	pop ar5,gr5; 
	pop ar0,gr0;
  return;
