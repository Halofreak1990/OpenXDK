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
int memcmp( const void *buff1, const void *buff2, size_t count )
{
	char	*pBuff1 = (char*) buff1;
	char	*pBuff2 = (char*) buff2;

	while( count-- > 0 ){
		char	a,b;
		a = *pBuff1++;
		b = *pBuff2++;
		if( a<b ){
			return -1;
		}if( a>b ){
			return 1;
		}
	}
	return 0;
}


