//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640x Software                      */
//*                                                                         */
//*   Software design:  A.Brodyazhenko                                     	*/
//*                                                                         */
//*   File:             nmpps-Mul_32f.asm                          	 	    */
//*   Contents:         The function computes y = x1 * x2   				*/
//***************************************************************************/

global _nmppsMul_32f: label;
//void nmppsMul_32f(const nm32f* pSrcVec1, const nm32f* pSrcVec2, nm32f* pDstVec, int nSize);

// x1 - pSrcVec1
// x2 - pSrcVec2
// y  - pDstVec[i] = pSrcVec1[i] * pSrcVec2[i]

begin ".text.nmpp"
<_nmppsMul_32f>
	ar5 = ar7 - 2;
	push ar2, gr2;
	push ar1, gr1;
	push ar0, gr0;

	ar0 = [--ar5]; // input nm32f* pSrcVec1
	ar1 = [--ar5]; // input nm32f* pSrcVec2
	ar2 = [--ar5]; // output nm32s* pDstVec
	gr0 = [--ar5]; // size N

	gr1 = gr0 >> 6;
	if =0 goto Mul_32f_less64;

<Mul_32f>
	fpu 0 rep 32 vreg0 = [ar0++];
	fpu 0 rep 32 vreg1 = [ar1++];
	gr1--;
	if > delayed goto Mul_32f;
		fpu 0 .float vreg2 = vreg0 * vreg1;
		fpu 0 rep 32 [ar2++] = vreg2;

	gr0 = gr0 << 26;				// computing a remainder
	gr0 = gr0 >> 26;				// computing a remainder

<Mul_32f_less64>			        // N < 64
	gr0 = gr0 >> 1;
	if =0 delayed goto exit_Mul_32f;
		gr0--;
		vlen = gr0;
	fpu 0 rep vlen vreg0 = [ar0++];
	fpu 0 rep vlen vreg1 = [ar1++];
	fpu 0 .float vreg2 = vreg0 * vreg1;
	fpu 0 rep vlen [ar2++] = vreg2;

<exit_Mul_32f>
	pop ar0, gr0;
	pop ar1, gr1;
	pop ar2, gr2;
	return;
end ".text.nmpp";
