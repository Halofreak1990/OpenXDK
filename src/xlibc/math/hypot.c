// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : hypot.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

#ifndef __GNUC__


float hypotf(float f, float g)
{
	return sqrt(f*f+g*g);
}
double hypot(double f, double g)
{
	return sqrt(f*f+g*g);
}


#endif //__GNUC__
