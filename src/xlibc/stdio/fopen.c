
#include <stdio.h>                          // FILE structure, _open(..) _O_BINARY _O_CREAT ..
#include <malloc.h>                         // malloc(..)
#include <string.h>                         // memset(..)

unsigned int __stdio_parse_mode(const char * mode);

// Still has some bugs to work out - I used 'CreateFile(..)' instead of _open
// as I needed to use the flag "OPEN_ALWAYS" for when you use 'a' or 'a+' etc
// as the mode.
FILE *fopen(char *szFile, const char *mode) 
{
	unsigned int f=0;	/* O_RDONLY, O_WRONLY or O_RDWR */
	int fd;
	FILE *tmp;

	f = __stdio_parse_mode(mode);

	//if((fd = _open( szFile, f, 0 ))<0)
	//	return 0;

	fd = (int)CreateFile(	szFile,
							//GENERIC_READ|GENERIC_WRITE, 
							f,
							0,
							NULL,
							OPEN_ALWAYS,
							FILE_FLAG_RANDOM_ACCESS,
							NULL
						);

	if( fd < 0 ) return 0;

	// Always start at the end of the file
	_lseek(fd , 0, SEEK_END);

	tmp = (FILE*)malloc(sizeof(FILE));
	memset(tmp, 0x0, sizeof(FILE));

	tmp->fd = fd;
  
	return tmp;
}// End fopen(..)


unsigned int __stdio_parse_mode(const char * mode)
{
	unsigned int f = 0;

	/*
	"r"  - Open a file for reading. 
	"w"  - Create an empty file for writing. 
	"a"  - Append to a file.
	"r+" - Open a file for reading and writing. 
	"w+" - Create an empty file for reading and writing.
	"a+" - Open a file for reading and appending
	"t"  - text mode
	"b"  - binary mode
	*/

	if( mode[0] == 'r' )
		f |= GENERIC_READ;

	if( mode[0] == 'w' )
		f |= GENERIC_WRITE;

	if( mode[0] == 'a' )
		f |= GENERIC_READ|GENERIC_WRITE;


	// We can add further checkign later on to check the second
	// character.
	if( mode[1] == '+' )
		f |= GENERIC_READ|GENERIC_WRITE;

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




