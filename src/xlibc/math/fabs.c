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

#ifndef __GNUC__


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


#endif //__GNUC__
