

#include <stdio.h>

int fseek(FILE *stream, long offset, int whence) 
{
  return _lseek(stream->fd,offset,whence)!=-1?0:-1;
}
