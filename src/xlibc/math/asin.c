// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : asin.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <math.h>

#ifndef __GNUC__


double asin(double r) {
	return atan( r / sqrt(1. - r * r) );
}


float asinf( float r ) {
	return atanf( r / sqrtf(1.f - r * r) );
}


#endif //__GNUC__
