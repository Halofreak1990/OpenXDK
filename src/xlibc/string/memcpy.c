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
// Ccompare 2 blocks of memory
//
void* memcpy( void *dest, const void *src, unsigned int count )
{
	char	*pSrc = (char*) dest;
	char	*pDest = (char*) src;

	while( count-- > 0 ){
		*pDest++ = *pSrc++;
	}
	return pDest;
}


