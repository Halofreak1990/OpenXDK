// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : sincos.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

#ifndef __GNUC__

double sin(double f) {
	__asm {
		fld f
		fsin
	}
}
double cos(double f) {
	__asm {
		fld f
		fcos
	}
}

float sinf(float f) {
	__asm {
		fld f
		fsin
	}
}
float cosf(float f)	{
	__asm {
		fld f
		fcos
	}
}

#endif
