


#include <stdio.h>

long ftell(FILE *stream) 
{
  return _lseek(stream->fd,0,SEEK_CUR);
}// End ftell(..)
