// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : ceil.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

#ifndef __GNUC__

extern int     _RoundUp;

double ceil(double f)
{
	int temp;
	__asm
	{
		fstcw temp
		fldcw _RoundUp
		fld f
		frndint
		fldcw temp
	}
}

float ceilf(float f)
{
	int temp;
	__asm
	{
		fstcw temp
		fldcw _RoundUp
		fld f
		frndint
		fldcw temp
	}
}


#endif //__GNUC__
