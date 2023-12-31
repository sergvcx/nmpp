
extern core_vsum_data_vr:label;
extern tbl_sb_nm32_EvenARSH:long;
begin ".text.nmpp"

// void nmppsRShiftC_MulC_AddC_2x32s(int32x2* dataSparseSrc,  int32x2* preshiftArg, int32x2* mulArg, int32x2* addArg, int32x2 *dataSparseDst,  int size, int stepSparseSrc, int stepSparseDst);
global "_nmppsRShiftC_MulC_AddC_2x32s" : label;
       <_nmppsRShiftC_MulC_AddC_2x32s>

.branch;
	ar5 = ar7-2;

	push ar0, gr0;
	push ar1, gr1;
	push ar5, gr5;
	push ar6, gr6;

	ar0 = [--ar5]; // [in] dataSparseSrc
	// ---------- parse preshiftArg and select sb ----
	ar6 = [--ar5]; // [in] preshiftArg 
	nb1 = 80000000h;
	ar1 = tbl_sb_nm32_EvenARSH;
	gr1 = [ar6++];
	sbl = [ar1+=gr1];
	
	ar1 = tbl_sb_nm32_EvenARSH;
	gr1 = [ar6++];
	sbh = [ar1+=gr1];
	// ---------- parse mulArg and load weights ----
	ar6 = [--ar5]; // [in] mulArg 
	
	ar1,gr1 = [ar6];// ar1=lo, gr1=hi
	ar6,gr6 = [ar6]	with gr1 = false ;
	ar6 = gr1;	
	[ar7++] = ar6,gr6 with gr6=false;
	[ar7++] = ar6,gr6; // 0,0
	[ar7++] = ar1,gr1;
	[ar7++] = ar6,gr6; // 0,0
	rep 4 wfifo=[--ar7] ,ftw,wtw;
	//------------ parse other params ---------------- 
	ar1 = [--ar5]; // [in] addArg 
	ar6 = [--ar5]; // [out] dataSparseDst 
	gr5 = [--ar5]; // [in] size (in long)
	gr0 = [--ar5]; // [in] stepSparseSrc  =1 
	delayed call core_vsum_data_vr;					
		gr6 = [--ar5]	with gr0<<=1; // [in] stepSparseDst =1
		vr=[ar1] 		with gr6<<=1;

	pop ar6, gr6;
	pop ar5, gr5;
	pop ar1, gr1;
	pop ar0, gr0;

	return;
.wait;

end ".text.nmpp";
