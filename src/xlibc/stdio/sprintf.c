// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : sprintf.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


char	HexTable1[]="0123456789abcdef";
char	HexTable2[]="0123456789ABCDEF";


#define FLOAT_BIAS 127
#define E_MAX 127
#define E_MIN -126

#define FRACTION_MASK 0x7fffff

// floating point structure
typedef struct{
    unsigned int fraction : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
} floatstruct;
#define	Card32		int






// ********************************************************
//
// Name:		AddHex
// Function:   	Add upper or lowercase HEX to the string
//
// ********************************************************
int AddHex( char* pDest, int index, int count, int value, char* pTable )
{
	int				shiftcount=28;
	int				i;
	int				leading0=0;

	while( shiftcount>=0)
	{
		if( index==count) return index;

		i = (value>>shiftcount)&0xf;
		if( i!=0 ){
			leading0=1;
		}
		if( shiftcount==0 ){
			leading0=1;
		}
		if( leading0!=0){
			pDest[index++] = pTable[i];
		}

		shiftcount-=4;
	}
	return index;
}


// ********************************************************
//
// Name:		AddInt
// Function:   	Add a number to a string
//
// ********************************************************
int AddInt( char* pDest, int index, int count, int value, int zerolimit )
{
	int		modulo = 1000000000;
	int		n,d;
	int				leading0=0;

	if( value<0 ){
		pDest[index++] = '-';
		value = -value;
	}
	while( modulo!=0)
	{
		n = value/modulo;
		value = value%modulo;
		modulo /=10;

	
		if( n!=0 ){
			leading0=1;
		}
		if( modulo==zerolimit ){
			leading0=1;
		}
		if( leading0!=0){
			pDest[index++] = '0'+n;
		}
	}
	return index;
}


// ********************************************************
//
// Name:		floatConversion
// Function:   	Convert a float to a string
//
// ********************************************************
int  floatConversion(float numberf, int detail, int *pInteger, int *pFraction)
{

    int		f,E,i;
    Card32 fraction;

    E=((floatstruct *)&numberf)->exponent;
    E-=FLOAT_BIAS;							// add bias onto exponent
    f=((floatstruct *)&numberf)->fraction;
    *pFraction=0;							// initialise fraction to zero    

	// there are 5 different cases for the calculation of a floating point number

    if(E==E_MAX+1)
    { 
		if(f==0) return 1;
    }
    else if(E==E_MIN-1)
    {
		E=E_MIN;
		if(f==0)
		    fraction=0;
		else
			fraction=(f>>(-E));
		*pInteger=0;
    }
    else
    {  
		*pInteger=(f+(1<<23))>>(23-E);

	// destroy anything that is not fraction. Then multiply by 100 to find the
	// first two places after the point add a half so that the fixed point is 
	// rounded up if the fraction is greater than 0.5 and shift down 23 places
	if(E>0)
	    fraction=(f<<E);
	else
	    fraction=((f+(1<<23))>>(-E));
    }

    i=0;
    for(i=0; i<detail; i++)
    {
		fraction&=FRACTION_MASK;
		fraction*=10;
		*pFraction*=10;
		*pFraction+=((fraction>>23)%10);
    }
    return 0;
}


// ************************************************************
// returns if a floating point number is finite
// ************************************************************
int finite(float numberf)
{
    int	f,E;

    E=((floatstruct *)&numberf)->exponent;

    E-=FLOAT_BIAS;							// add bias onto exponent
    f=((floatstruct *)&numberf)->fraction;
    if(E == E_MAX+1 && f == 0) return 1;
    
	return 0;
}


// ************************************************************
// get an INT into a string
// ************************************************************
int AddFloat( char* pString, int index, int count, float f )
{
	int		i,frac,i2=0;

	if( f<0 ) {
		i2=1;
		f = -f;
	}
	if (floatConversion( f, 3, &i, &frac )==0)
	{
		if( i2!=0) i=-i;
		index = AddInt( pString, index, count, i, 0 );
		pString[index++]='.';
		index = AddInt( pString, index, count, frac, 10 );
	}
	else
	{
		pString[index++]='I';
		pString[index++]='N';
		pString[index++]='F';
		pString[index++]=0x0;
	}

	return index;
}


// ********************************************************
//
// Name:		AddHex
// Function:   	Add upper or lowercase HEX to the string
//
// ********************************************************
int AddString( char* pDest, int index, int count, char* pSrc )
{
	char	a;

	while(true)
	{
		if( index==count) return index;

		a = *pSrc++;
		if( a==0x00 ) return index;
		pDest[index++]=a;
	}
}

// ********************************************************
//
// Name:		vsnprintf
// Function:   	Write formated output to string... 
//				standard call fro sprintf, printf etc.
//
// ********************************************************
int vsnprintf( char *buffer, unsigned int count, char *format, va_list ap )
{
	int		index=0;
	char*	pDest = buffer;
	char*	pSrc = format;
	char	c;
	float	f;

	while(true)
	{
		c = *pSrc++;
		
		if( c== 0x00 ) break;
		if( index == count ) break;

		switch(c)
		{
			case '\\':	c = *pSrc++;
						switch( c ){
							case 'n':		pDest[index++]=0x0d;	break;		// add newline 
							case 't':		pDest[index++]=0x09;	break;		// add newline 
							default:		pDest[index++]=c;
						};
						break;

			case '%':	c = *pSrc++;
						switch( c ){
							case 's':	index = AddString( pDest, index, count, va_arg(ap, char*) );
										break;
							case 'd':	index = AddInt( pDest, index, count, va_arg(ap, int), 0 );
										break;
							case 'x':	index = AddHex( pDest, index, count, va_arg(ap, int), &HexTable1[0] );
										break;
							case 'X':	index = AddHex( pDest, index, count, va_arg(ap, int), &HexTable2[0] );
										break;
							case 'f':	//f = (float)va_arg(ap, double );
										//index = AddHex( pDest, index, count, *((int*)(&f)), &HexTable1[0] );
										index = AddFloat( pDest, index, count, (float)va_arg(ap, double ) );
										break;

						}
						break;
			default:	pDest[index++]=c;
		}
	}
	pDest[index++]=0x00;

	return index;
}




// ********************************************************
//
// Name:		sprintf 
// Function:   	Write formated output to string
//
// ********************************************************
int	sprintf (char *str, const char *format, ...)
{
  va_list	Params;
  int		ret;

  va_start(Params, format);
  ret = vsnprintf (str, 0x10000, (char*) format, Params);

  va_end(Params);
  return ret;
}


