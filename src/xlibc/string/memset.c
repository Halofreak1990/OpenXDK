// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : memset.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************
#include	<ansidecl.h>

//
// Ccompare 2 blocks of memory
//
void* memset( void *Dest, int fill, size_t length )
{
	char	*pDest = (char*) Dest;

	while( length-- > 0 ){
		*pDest++ = fill;
	}
	return Dest;
}

/*
void* memset( void *Dest, int fill, size_t length )
{
	__asm
	{
		mov eax,fill
		mov edi,dest
		mov ecx,length
		rep stosb
	}
}


*/