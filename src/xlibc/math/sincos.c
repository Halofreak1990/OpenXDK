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

#ifdef _MSC_VER

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
#else

OPENXDK_UNIMPLEMENTEDC(sin/cos)

#endif
