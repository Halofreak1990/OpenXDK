// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : floor.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

#ifdef _MSC_VER

extern int     _RoundDown;

double floor(double f)
{
	int temp;
	__asm
	{
		fstcw temp
		fldcw _RoundDown
		fld f
		frndint
		fldcw temp
	}
}

float floorf(float f)
{
	int temp;
	__asm
	{
		fstcw temp
		fldcw _RoundDown
		fld f
		frndint
		fldcw temp
	}
}

#else

OPENXDK_UNIMPLEMENTEDC(floor)

#endif 
