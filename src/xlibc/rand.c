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

#include	<stdlib.h>

// NEEDS WORK
// - ector^XL

int state = 0xbaadf00d;

int rand()
{
// this is just some stupidity I came up with..
// seems to give reasonable numbers... but I haven't
// done any kind of real testing, i've just printed a few
// hundred numbers. they did look random but you never know.
	int temp = state & 0xE3724521;
	temp*=102253;
	state = (state<<18) ^ (state>>7) + temp;
	return state & RAND_MAX;
}


void srand(unsigned int seed)
{
	state = seed;
}