
#include <stdio.h>                          // FILE structure, _open(..) _O_BINARY _O_CREAT ..
#include <stdlib.h>                         // malloc(..)

#include <string.h>                         // memset(..)

unsigned int __stdio_parse_mode(const char * mode);

FILE *fopen(char *szFile, const char *mode) 
{
	unsigned int f=0;	/* O_RDONLY, O_WRONLY or O_RDWR */
	int fd;
	FILE *tmp;

	f = __stdio_parse_mode(mode);
	//f = _O_RDWR|_O_BINARY|_O_CREAT|_O_TRUNC;
	  
	if((fd = _open( szFile, f, 0 ))<0)
		return 0;

	tmp = (FILE*)malloc(sizeof(FILE));
	memset(tmp, 0x0, sizeof(FILE));

	tmp->fd = fd;
  
	return tmp;
}// End fopen(..)


unsigned int __stdio_parse_mode(const char * mode)
{
	unsigned int f = 0;

	if( mode[0] == 'r' )
		f |= _O_RDONLY;

	if( mode[0] == 'w' )
		f |= _O_WRONLY | _O_CREAT;

	if( mode[0] == 'a' )
		f |= _O_APPEND | _O_RDWR | _O_CREAT;


	if( mode[1] == '+' )
		f |= _O_RDWR;

	return f;

}// End __stdio_parse_mode(..)


/*
#define _O_RDONLY					(0x00000001)
#define _O_WRONLY					(0x00000002)
#define _O_RDWR						(0x00000003)
#define _O_NBLOCK					(0x00000010)
#define _O_APPEND					(0x00000100)
#define _O_CREAT					(0x00000200)
#define _O_TRUNC					(0x00000400)
#define	_O_EXCL						(0x00000800)
#define	_O_TEMPORARY				(0x00001000)
#define	_O_TEXT						(0x00004000)
#define _O_BINARY					(0x00008000)
*/




