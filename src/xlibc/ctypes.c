#include	<ansidecl.h>


int
isascii(int c)	
{ 
	if((c>=0)&&(c<=177)) return 1;
	return 0;
}


