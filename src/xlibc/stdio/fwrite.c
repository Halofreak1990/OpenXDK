

#include <stdio.h>

size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream) 
{
	return _write(stream->fd,  ptr,  size * nmemb);

	// Returns the number of bytes written if all went okay.
}// End fwrite(..)
