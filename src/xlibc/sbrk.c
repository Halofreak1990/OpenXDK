#include <ansidecl.h>
#include <openxdk.h>

extern	void Print( int x, int y, char* pText );
extern	char	s[64];
extern	void Flip(void );

#ifndef	_XBOX
	char	MemoryHeap[1024*1024*32];
	int		index=0;
#endif


void* sbrk( long	size )
{
#ifdef	_XBOX
	void* p;

//   	sprintf(&s[0],"Size %x" , size );
//	Print(40,140,&s[0]);
//	Flip();

	if( size >0 ){	
		p = ExAllocatePool(size);
	return	p;
	}
	return	NULL;
#else
	void*	pointer;
	pointer = (void*) &MemoryHeap[index];
	index+=size;
	return	pointer;

#endif
}
