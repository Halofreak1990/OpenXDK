// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : tan.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

#ifndef __GNUC__


// **************************************************************************
//
//	Name:		ftol
//	Function:	replacement for _ftol, much faster
//				*** THIS IS XBOX ONLY DUE TO RING 0 STUFF ***
//
//	In:		float = float to convert to int
//	Out:	int
//
// **************************************************************************
#ifdef	_MSC_VER
/*
//
 // Depending on the service pack available in MSDEV, we can use this even faster one.
//
// Standard VC++ _ftol is horribly slow because it changes rounding modes twice.
// This replacement comes courtesy of Intel.
// Just linking it in will replace the VC++ standard one.
// Using the /QIfist compiler option (Suppress _ftol) is a faster solution, but 
// this is a good compromise fallback if compatibility is important.
__declspec(naked) long _ftol(float arg)
{
  __asm
  {
	sub			esp, 4					// RING 0 - MUST do
	fstp		dword ptr [esp]
	movss		xmm0, dword ptr [esp]
	cvttss2si	eax, xmm0
	add			esp, 4					// RING 0 - MUST do
	ret
  }
}
*/

__declspec(naked) long ftol(float arg)
{
	_asm{
		  // store as a quadword int and reload
		sub		esp, 8					// RING 0 - MUST do
		fld     st(0)					// X X
		fistp   QWORD PTR [esp]			// X
		fild    QWORD PTR [esp]			// X [X]
		mov     edx,DWORD PTR [esp+4]
		mov     eax,DWORD PTR [esp]
		test    eax,eax
		je      maybe_zero

		// number isn't zero, so get X - [X]
not_zero:
		fsubp   st(1),st				// X - [X]
		test    edx,edx
		jns     positive

		// number < 0 - inc eax if X - [X] is >0
		fstp    DWORD PTR [esp]
		mov     ecx,DWORD PTR [esp]		// get IEEE rep
		xor     ecx,80000000h			// now <0 if diff >0
		add     ecx,7FFFFFFFh			// carry if it was 00000001 to 7FFFFFFF
		adc     eax,0					// add carry in
		add		esp, 8
		ret

positive:
		// number > 0 - dec eax if X - [X] is <0
		fstp    DWORD PTR [esp]
		mov     ecx,DWORD PTR [esp]		// get IEEE rep
		add     ecx,7FFFFFFFh			// carry if it was 80000001 to FFFFFFFF
		sbb     eax,0					// sub carry
		add		esp, 8
		ret

maybe_zero:
		test    edx,7FFFFFFFh
		jnz     not_zero

		// number is zero - clear the stack
		fstp    st(0)
		fstp    st(0)
		add		esp, 8
		ret
	}
}
#endif // _MSC_VER

#else

OPENXDK_UNIMPLEMENTEDC(ftol)

#endif //__GNUC__
