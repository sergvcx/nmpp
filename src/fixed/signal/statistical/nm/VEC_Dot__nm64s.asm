//***************************************************************************/
//*                     RC Module, Moscow, Russia                      */
//*                     NeuroMatrix(r) NM6403 Software                      */
//*                                                                         */
//*   Vector Processing  Library                                            */
//*   (C-callable functions)                                                */
//*                                                                         */
//*   $Workfile:: Prod64.asm                                               $*/
//*                                                                         */
//*   Contents:        Shift routines                                       */
//*                                                                         */
//*   Software design: Lukashevich Pavel                                    */
//*                                                                         */
//*   Version          1.0                                                  */
//*   Start date:      17.0.2002                                            */
//*   Release  $Date: 2004/11/22 13:50:11 $*/
//*                                                                         */
//*                                                                         */
//***************************************************************************/
//#include "vProd.h"

import from "nmpp/macros.mlb";

begin ".text.nmpp"
.branch;

//! \fn void nmppsDotProd_64s64s (nm64s *pSrcVec1, nm64s *pSrcVec2, int nSize, int64b *pnRes) 
//!
//! \perfinclude nmppsDotProd_64s64s.html
			 
global _nmppsDotProd_64s64s:label;
<_nmppsDotProd_64s64s>
	ar5 = ar7 - 2;

	
	PUSH_REGS();

	ar0 = [--ar5];	// Input0 buffer
	ar4 = [--ar5];	// Input1 buffer
	gr6 = [--ar5];	// V0,V1 vectors Size
	ar6 = [--ar5];	// Output buffer 

	sb	= 00000000h;
	gr7 = 00000000h;
	nb1 = gr7;


	rep 1 wfifo=[ar4++],ftw,wtw;
	with gr6--;
	rep 1 with vfalse;
	.branch;

<NextMul64>
	if > delayed goto NextMul64 with gr6--;
		rep 1 data=[ar0++] with vsum, data,afifo;
		rep 1 wfifo=[ar4++],ftw,wtw;
	
		
	rep 1 [ar6] = afifo;

	POP_REGS();

return;
.wait;
end ".text.nmpp"; 
