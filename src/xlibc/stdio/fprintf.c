


#include <stdio.h>   // FILE structure, fwrite(..)
#include <stdlib.h>  // malloc(..)
#include <string.h>  // strlen(..)


//extern int vsprintf (char *str, const char *format, va_list args); // snprintf.c


int fprintf(FILE *f,const char *format,...) 
{

	char * pszbuffer = (char*)malloc(0x1000); // Max Buffer Size
	int n, len;
	
	va_list arg_ptr;
	va_start(arg_ptr,format);
	vsprintf( pszbuffer,(char*)format, arg_ptr ); 
	va_end(arg_ptr);

	len = strlen(pszbuffer)-1;
	n   = fwrite(pszbuffer, len, 1, f);
	
	free(pszbuffer);
	pszbuffer=0;

	return n;
}
