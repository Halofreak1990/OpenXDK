

#include <xlibc\stdio.h>   // FILE structure, fwrite(..)
#include <malloc.h>        // malloc(..)
#include <string.h>        // strlen(..)
#include <stdarg.h>



//extern int vsprintf (char *str, const char *format, va_list args); // snprintf.c
extern int xxvsnprintf( char *buffer, unsigned int count, const char *format, va_list ap ); // sprintf.c

int fprintf(FILE *f,const char *fmt,...) 
{

	char * pszbuffer = (char*)malloc(0x1000); // Max Buffer Size
	int n, len;

	va_list args;
	va_start(args,fmt);
	//vsprintf( pszbuffer,(char*)fmt, args ); 
	xxvsnprintf( pszbuffer, 0x1000, (char*)fmt, args ); 
	va_end(args);

	len = strlen(pszbuffer);
	n   = fwrite(pszbuffer, 1, len, f);
	
	free(pszbuffer);
	pszbuffer=0;

	return n;
}// End fprintf(..)


