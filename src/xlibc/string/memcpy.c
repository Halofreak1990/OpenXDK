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
// copy a block of memory
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



//to be further optimized: 4-byte align first
//test properly too before using :)
/*
void* memcpy( void *dest, const void *src, unsigned int count )
{
	__asm
	{
		cmp count,0
		je bail
		mov edi,dest
		mov esi,src
		mov ebx,count
		mov ecx,count
		shr ecx,2
		jz finishup
		rep movsd
	finishup:
		and ebx,3
		jz bail
		mov ecx,ebx
		rep movsb
	bail:
	}
}
*/