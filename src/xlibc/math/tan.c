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


double tan(double f) {
	float temp;
	__asm {
		fld f
		fptan
		fstp temp //get rid of the 1 pushed on the stack
	}
}

float tanf(float f)	{
	float temp;
	__asm {
		fld f
		fptan
		fstp temp //get rid of the 1 pushed on the stack
	}
}

#endif //__GNUC__
