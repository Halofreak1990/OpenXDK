#include "../xboxkrnl/xboxkrnl.h"
#include <ansidecl.h>
#include <malloc.h>

//dummy malloc
//not sure if we should use this kernel function
void *malloc(size_t size)
{
	return (void *)ExAllocatePool(size);
}


void free(void *mem)
{
	ExFreePool(mem);
}