// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : exp.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

// NEEDS WORK

#include <math.h>


//This is a fast approximation
//we need to replace this by something better
//though this could be useful to keep around anyway
//because of its immense speed

double exp(double f)
{
	static union
	{
		double d;
		struct{int j, i;} n;
	} eco;
	eco.n.i = (int)(1512775*(f) + (1072693248 - 60801));

	return eco.d / 0.9710069;  //fudge factor?
}

float expf(float f) {
	return exp((double)f);
}

