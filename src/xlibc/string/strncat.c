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
// Return the length of a string
//

char* strncpy( char *dest, const char *src, unsigned int count )
{
	char*	pDest	= (char*) dest;
	char*	pSrc	= (char*) src;
	char	a;

	// Append source
	while(count!=0 ){
		a = *pSrc++;
		if( a == 0x00 ) break;
		*pDest++=a;
		count--;
	}

	if( count!=0){
		*pDest++ = 0x00;
		count--;
	}

	return dest;
}
