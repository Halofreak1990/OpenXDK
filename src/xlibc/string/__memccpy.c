// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : __memccpy.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include	<ansidecl.h>

//
// Copy an array of characters till "C" is hit
//

void* _memccpy( void *dest, const void *src, int c, unsigned int count )
{
	char	*pSrc = (char*) src;
	char	*pDest= (char*) dest;
	char	ch = (unsigned char) c;

	while( count-- > 0 ){
		char	a;
		a = *pSrc++;
		*pDest++ = a;
		if( a==ch ) return (void*) pDest;
	}
	return NULL;
}
