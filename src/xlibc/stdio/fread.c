

#include <stdio.h>

size_t fread( void *ptr, size_t size, size_t nmemb, FILE *stream) 
{

	return _read(stream->fd,ptr, size * nmemb);

	// Returns the number of bytes read if all went okay.
}// End fread(..)
