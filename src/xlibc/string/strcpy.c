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
#include	<String.h>
//
// Return the length of a string
//

char* strcpy( char *dest, const char *src )
{
	char*	pString = (char*) src;
	char	*pDest = (char*) dest;
	char	a;

	while(true){
		a = *pString++;
		*pDest++=a;
		if( a == 0x00 ){
			return dest;
		}
	}
}
