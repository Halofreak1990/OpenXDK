// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : conio.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

//
//
#ifndef	__GNUC__	// ********************* MSDEV VERSIONS ************************



// **************************************************************************
// output a byte
// **************************************************************************
void _outb( unsigned short port, unsigned char data )
{
	__asm{
		mov	dx,port
		mov	al,data
		out	dx,al
	}
}

// **************************************************************************
// output a word
// **************************************************************************
void _outw( unsigned short port, unsigned short data )
{
	__asm{
		mov	dx,port
		mov	ax,data
		out	dx,ax
	}
}

// **************************************************************************
// output a dword
// **************************************************************************
void _outd( unsigned short port, unsigned int data )
{
	__asm{
		mov	dx,port
		mov	eax,data
		out	dx,ax
	}
}

// **************************************************************************
// input a byte
// **************************************************************************
unsigned char _inb( unsigned short port )
{
	unsigned char data;
	__asm{
		mov	dx,port
		in	al,dx
		mov	data,al
	}
	return data;
}

// **************************************************************************
// input a word
// **************************************************************************
unsigned short _inw( unsigned short port )
{
	unsigned short  data;
	__asm{
		mov	dx,port
		in	ax,dx
		mov	data,ax
	}
	return data;
}
// **************************************************************************
// input a dword
// **************************************************************************
unsigned int _ind( unsigned short port )
{
	unsigned int data;
	__asm{
		mov	dx,port
		in	eax,dx
		mov	data,eax
	}
	return data;
}

#else				// ********************* GNU VERSIONS ************************


// **************************************************************************
// output a byte
// **************************************************************************
void _outb( unsigned short port, unsigned char data )
{
}

// **************************************************************************
// output a word
// **************************************************************************
void _outw( unsigned short port, unsigned short data )
{
}

// **************************************************************************
// output a dword
// **************************************************************************
void _outd( unsigned short port, unsigned int data )
{
}

// **************************************************************************
// input a byte
// **************************************************************************
unsigned char _inb( unsigned short port )
{
	unsigned char data=0;
	return data;
}

// **************************************************************************
// input a word
// **************************************************************************
unsigned short _inw( unsigned short port )
{
	unsigned short  data=0;
	return data;
}
// **************************************************************************
// input a dword
// **************************************************************************
unsigned int _ind( unsigned short port )
{
	unsigned int data = 0;
	return data;
}

#endif	//__GNUC__





