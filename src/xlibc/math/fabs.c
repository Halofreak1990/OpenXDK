// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : fabs.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

#ifdef _MSC_VER

double fabs(double f) {
	__asm {
		fld f
		fabs
	}
}

float fabsf(float f) {
	__asm {
		fld f
		fabs
	}
}

#else

double fabs(double f) {
	return f>=0.0f ? f : -f;
}

float fabsf(float f) {
	return f>=0.0f ? f : -f;
}

#endif //__GNUC__
