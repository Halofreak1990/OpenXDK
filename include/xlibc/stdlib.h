// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : stdlib.h
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#ifndef		__OPENXDK_STDLIB__
#define		__OPENXDK_STDLIB__

#ifdef	__cplusplus
extern "C" {
#endif

#include <ansidecl.h>

// *****************************************************************************
// 
//	Structures
//
// *****************************************************************************


typedef struct Sdiv_t{		// div structure
	int quot; 
	int	rem;
} div_t;


typedef struct Sldiv_t{		// ldiv  structure
	long int quot; 
	long int rem;
} ldiv_t;



// *****************************************************************************
// 
//	Functions
//
// *****************************************************************************
int		abs( int i );
void	abort( void );
div_t	div( int number, int divisor );
ldiv_t	ldiv( long int number, long int divisor );


int rand( void );
void srand( unsigned int );
// we could just as well use any other randmax 2^x-1
//but this seems to be the standard
#define RAND_MAX 32767


#ifdef	__cplusplus
};
#endif

#endif		//__OPENXDK_STDLIB__




