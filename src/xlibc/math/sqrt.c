// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : sqrt.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

#ifndef __GNUC__


double sqrt(double f) {
	__asm {
		fld f
		fsqrt
	}
}

float sqrtf(float f) {
	__asm {
		fld f
		fsqrt
	}
}

#else

OPENXDK_UNIMPLEMENTEDC(sqrt)

#endif //__GNUC__
