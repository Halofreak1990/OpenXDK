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

size_t strlen( const char *string )
{
	char*	pString = (char*) string;
	int		Length=0;
	char	a;

	while(true){
		if( *pString++ == 0x00 ){
			return Length;
		}
		Length++;
	}
	return NULL;
}
