// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : pow.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

// NEEDS WORK

#include <math.h>


//really bad approximation due to expf, log being approximations already :D
double pow(double a, double b)
{
	return expf(b * logf(a));
}


float powf(float a, float b) {
	return expf(b*logf(a));
}
