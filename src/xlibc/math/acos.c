// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : acos.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

double acos(double r)
{
	return 3.14159265358979323846 / 2 - asin(r);
}


float acosf(float r)
{
	return 3.14159265358979323846f / 2 - asinf(r);
}

