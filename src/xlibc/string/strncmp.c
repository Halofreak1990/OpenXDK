// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : _memccpy.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include	<ansidecl.h>

//
// Compare 2 blocks of memory
//
int strncmp( const void *buff1, const void *buff2 )
{
	char	*pBuff1 = (char*) buff1;
	char	*pBuff2 = (char*) buff2;

	while( true ){
		char	a,b;
		a = tolower(*pBuff1++);
		b = tolower(*pBuff2++);

		if( (a|b) == 0 ) return 0;			// both end at the same time, so equal

		if( a<b ){
			return -1;
		}if( a>b ){
			return 1;
		}
	}
}


