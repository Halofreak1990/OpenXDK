// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : fmod.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

#ifndef __GNUC__


float fmodf(float f, float g)
{
	float temp1,temp2;
	__asm
	{
		fld g
		fld f
		fprem
		fstp temp2
		fstp temp1
	}
	return temp2;
}

double fmod(double f, double g)
{
	double temp1,temp2;
	__asm
	{
		fld g
		fld f
		fprem
		fstp temp2
		fstp temp1
	}
	return temp2;
}

#endif //__GNUC__
