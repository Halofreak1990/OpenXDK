// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : log.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

// NEEDS WORK

#include <math.h>



double log(double x)
{
	return (double)logf((float)x);
}

double log10(double x)
{
	return 4.3429448190325181667e-1 * log(x);
}
//This is a fast approximation
//we need to replace this by something better
//though this could be useful to keep around anyway
//because of its immense speed
float logf(float x) 
{ 
	int * const  exp_ptr = (int *)(&x); 
	int          i = *exp_ptr; 
	const int    log_2 = ((i >> 23) & 255) - 128; 
	i &= ~(255 << 23); 
	i += 127 << 23; 
	*exp_ptr = i; 
	return (x + log_2) / 1.4427f; 
}

float log10f(float x)
{
	return 4.3429448190325181667e-1f * logf(x);
}

