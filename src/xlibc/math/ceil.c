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

#ifdef WINVER
#error
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
#else

OPENXDK_UNIMPLEMENTEDC(ceil)


#endif 
