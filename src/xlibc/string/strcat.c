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

#define	ALTERNATE
char* strcat( char *dest, const char *src )

{
	char*	pDest	= (char*) dest;
	char*	pSrc	= (char*) src;
	char	a;


	// Move to end of Dest string
	while(true){
		if( *pDest++ == 0x00 ) break;
	}

	// Append source
	while(true){
		a = *pSrc++;
		*pDest++=a;
		if( a == 0x00 ) return dest;
	}

}
