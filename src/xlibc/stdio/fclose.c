


#include <stdio.h>                          // FILE structure
#include <stdlib.h>                         // free(..)

int fclose(FILE *stream) 
{
	_close( stream->fd );
	free(stream);
	stream = NULL;

	return 0;
}// End fclose(..)
