// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : ltoa.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include	<ansidecl.h>

extern	char	conv[];			// get this from ltoa() function

char* itoa( int value, char *string, int radix )
{
	char	TempBuffer[16];
	int		index=0;
	int		rem,neg=0;

	if( radix==10 ){
		if(value<0){
			neg=1;
			value = -value;
		}
	}
	while(true)
	{
		rem	  = value%radix;
		value = value/radix;
		TempBuffer[index++]=conv[rem];
		if( value==0) break;
	}

	rem=0;
	if( neg==1){
		TempBuffer[index++]='-';
	}
	while(index>0){
		string[rem++]=TempBuffer[--index];
	}
	string[rem++]=0;
	return string;
}

