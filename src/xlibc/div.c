// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : div.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include	<stdlib.h>


// return the quotient AND the remainder
div_t	div( int number, int divisor )
{
	div_t answer;

	if( divisor == 0 ) abort(); //maybe show "div by 0" on screen?

	answer.quot	= number/divisor;
	answer.rem	= number%divisor;
	if( (number >= 0) && (answer.rem < 0) ){
		++answer.quot;
		answer.rem -= divisor;
	}

	return answer;
}
