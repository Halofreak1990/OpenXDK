// snprintf.c









#include <stdarg.h>
#include <stdlib.h>
#include <string.h>



//
// BIGBOY
// Adding basic "sprintf" float support
//
void Float2String( float f, char *pString );
	char	__SPRINTF_FLOAT[256];


enum format_flags {
    minus_flag     =  1,
    plus_flag      =  2,
    space_flag     =  4,
    alternate_flag =  8,
    zero_flag      = 16
};

//
// Common state
//

struct state {
  unsigned char *str;
  unsigned char *s;
  unsigned char *theend;
  size_t sz;
  size_t max_sz;
  int (*append_char)(struct state *, unsigned char);
  int (*reserve)(struct state *, size_t);
  // XXX - methods 
};

#ifndef isdigit
int isdigit( int c)
{
    return ( c >= '0' && c <='9');
}
#endif

#ifndef HAVE_VSNPRINTF
static int
sn_reserve (struct state *state, size_t n)
{
  return state->s + n > state->theend;
}



static int
sn_append_char (struct state *state, unsigned char c)
{
  if (sn_reserve (state, 1)) {
    return 1;
  } else {
    *state->s++ = c;
    return 0;
  }
}
#endif


int str_len( char* s )
{
	int i=0;
	while(*s++!=0x00){
		i++;
	}
	return i;
}

static int
append_number(struct state *state,
	      unsigned long num, unsigned base, char *rep,
	      int width, int prec, int flags, int minusp)
{
  int len = 0;
  int i;

  // given precision, ignore zero flag
  if(prec != -1)
    flags &= ~zero_flag;
  else
    prec = 1;
  // zero value with zero precision -> "" 
  if(prec == 0 && num == 0)
    return 0;
  do{
    if((*state->append_char)(state, rep[num % base]))
      return 1;
    len++;
    num /= base;
  }while(num);
  prec -= len;
  // pad with prec zeros 
  while(prec-- > 0){
    if((*state->append_char)(state, '0'))
      return 1;
    len++;
  }
  // add length of alternate prefix (added later) to len 
  if(flags & alternate_flag && (base == 16 || base == 8))
    len += base / 8;
  // pad with zeros 
  if(flags & zero_flag){
    width -= len;
    if(minusp || (flags & space_flag) || (flags & plus_flag))
      width--;
    while(width-- > 0){
      if((*state->append_char)(state, '0'))
	return 1;
      len++;
    }
  }
  // add alternate prefix 
  if(flags & alternate_flag && (base == 16 || base == 8)){
    if(base == 16)
      if((*state->append_char)(state, (unsigned char)(rep[10] + 23))) // XXX  
	return 1;
    if((*state->append_char)(state, '0'))
      return 1;
  }
  // add sign  
  if(minusp){
    if((*state->append_char)(state, '-'))
      return 1;
    len++;
  } else if(flags & plus_flag) {
    if((*state->append_char)(state, '+'))
      return 1;
    len++;
  } else if(flags & space_flag) {
    if((*state->append_char)(state, ' '))
      return 1;
    len++;
  }
  if(flags & minus_flag)
    // swap before padding with spaces  
    for(i = 0; i < len / 2; i++){
      char c = state->s[-i-1];
      state->s[-i-1] = state->s[-len+i];
      state->s[-len+i] = c;
    }
  width -= len;
  while(width-- > 0){
    if((*state->append_char)(state,  ' '))
      return 1;
    len++;
  }
  if(!(flags & minus_flag))
    // swap after padding with spaces  
    for(i = 0; i < len / 2; i++){
      char c = state->s[-i-1];
      state->s[-i-1] = state->s[-len+i];
      state->s[-len+i] = c;
    }
    
  return 0;
}

static int
append_string (struct state *state,
	       unsigned char *arg,
	       int width,
	       int prec,
	       int flags)
{
  if(prec != -1)
    width -= prec;
  else
    width -= str_len((char *)arg);
  if(!(flags & minus_flag))
    while(width-- > 0)
      if((*state->append_char) (state, ' '))
	return 1;
  if (prec != -1) {
    while (*arg && prec--)
      if ((*state->append_char) (state, *arg++))
	return 1;
  } else {
    while (*arg)
      if ((*state->append_char) (state, *arg++))
	return 1;
  }
  if(flags & minus_flag)
    while(width-- > 0)
      if((*state->append_char) (state, ' '))
	return 1;
  return 0;
}

static int
append_char(struct state *state,
	    unsigned char arg,
	    int width,
	    int flags)
{
  while(!(flags & minus_flag) && --width > 0)
    if((*state->append_char) (state, ' '))
      return 1;
    
  if((*state->append_char) (state, arg))
    return 1;
  while((flags & minus_flag) && --width > 0)
    if((*state->append_char) (state, ' '))
      return 1;
    
  return 0;
}

//
 * This can't be made into a function...
  

#define PARSE_INT_FORMAT(res, arg, unsig) \
if (long_flag) \
     res = (unsig long)va_arg(arg, unsig long); \
else if (short_flag) \
     res = (unsig short)va_arg(arg, unsig int); \
else \
     res = (unsig int)va_arg(arg, unsig int)

//
 * zyxprintf - return 0 or -1
  

static int
xyzprintf (struct state *state, const char *char_format, va_list ap)
{
  const unsigned char *format = (const unsigned char *)char_format;
  unsigned char c;

  while((c = *format++)) {
    if (c == '%') {
      int flags      = 0;
      int width      = 0;
      int prec       = -1;
      int long_flag  = 0;
      int short_flag = 0;

      // flags  
      while((c = *format++)){
	if(c == '-')
	  flags |= minus_flag;
	else if(c == '+')
	  flags |= plus_flag;
	else if(c == ' ')
	  flags |= space_flag;
	else if(c == '#')
	  flags |= alternate_flag;
	else if(c == '0')
	  flags |= zero_flag;
	else
	  break;
      }
      

      if((flags & space_flag) && (flags & plus_flag))
	flags ^= space_flag;

      if((flags & minus_flag) && (flags & zero_flag))
	flags ^= zero_flag;

      // width  
      if (isdigit(c))
	do {
	  width = width * 10 + c - '0';
	  c = *format++;
	} while(isdigit(c));
      else if(c == '*') {
	width = va_arg(ap, int);
	c = *format++;
      }

      // precision  
      if (c == '.') {
	prec = 0;
	c = *format++;
	if (isdigit(c))
	  do {
	    prec = prec * 10 + c - '0';
	    c = *format++;
	  } while(isdigit(c));
	else if (c == '*') {
	  prec = va_arg(ap, int);
	  c = *format++;
	}
      }

      // size  

      if (c == 'h') {
	short_flag = 1;
	c = *format++;
      } else if (c == 'l') {
	long_flag = 1;
	c = *format++;
      }

      switch (c) {

	  case 'f':{
				char *pStr = &__SPRINTF_FLOAT[0];
				double f = (float )va_arg(ap, double);
				
				Float2String( (float)f, pStr );
				while(*pStr!=0x00)
				  if ((*state->append_char) (state, *pStr++))
				return 1;
				
				break;
	}

      case 'c' :
	if(append_char(state, (unsigned char)va_arg(ap, int), width, flags))
	  return -1;
	break;
      case 's' :
	if (append_string(state,
			  va_arg(ap, unsigned char*),
			  width,
			  prec, 
			  flags))
	  return -1;
	break;
      case 'd' :
      case 'i' : {
	long arg;
	unsigned long num;
	int minusp = 0;

	PARSE_INT_FORMAT(arg, ap, signed);

	if (arg < 0) {
	  minusp = 1;
	  num = -arg;
	} else
	  num = arg;

	if (append_number (state, num, 10, "0123456789",
			   width, prec, flags, minusp))
	  return -1;
	break;
      }
      case 'u' : {
	unsigned long arg;

	PARSE_INT_FORMAT(arg, ap, unsigned);

	if (append_number (state, arg, 10, "0123456789",
			   width, prec, flags, 0))
	  return -1;
	break;
      }
      case 'o' : {
	unsigned long arg;

	PARSE_INT_FORMAT(arg, ap, unsigned);

	if (append_number (state, arg, 010, "01234567",
			   width, prec, flags, 0))
	  return -1;
	break;
      }
      case 'x' : {
	unsigned long arg;

	PARSE_INT_FORMAT(arg, ap, unsigned);

	if (append_number (state, arg, 0x10, "0123456789abcdef",
			   width, prec, flags, 0))
	  return -1;
	break;
      }
      case 'X' :{
	unsigned long arg;

	PARSE_INT_FORMAT(arg, ap, unsigned);

	if (append_number (state, arg, 0x10, "0123456789ABCDEF",
			   width, prec, flags, 0))
	  return -1;
	break;
      }
	case 'p' : 
		{
				unsigned long arg = (unsigned long)va_arg(ap, void*);

				if (append_number (state, arg, 0x10, "0123456789ABCDEF",
						width, prec, flags, 0))
				return -1;
				break;
		}
	case 'n' : 
		{
			int *arg = va_arg(ap, int*);
			*arg = state->s - state->str;
			break;
		}
	case '\0' :
	  --format;
	  // FALLTHROUGH  
      case '%' :
	if ((*state->append_char)(state, c))
	  return -1;
	break;
      default :
	if (   (*state->append_char)(state, '%')
	    || (*state->append_char)(state, c))
	  return -1;
	break;
      }
    } else
      if ((*state->append_char) (state, c))
	return -1;
  }
  return 0;
}

#ifndef HAVE_VSNPRINTF
int
vsnprintf (char *str, size_t sz, const char *format, va_list args)
{
  struct state state;
  int ret;
  unsigned char *ustr = (unsigned char *)str;

  state.max_sz = 0;
  state.sz     = sz;
  state.str    = ustr;
  state.s      = ustr;
  state.theend = ustr + sz - 1;
  state.append_char = sn_append_char;
  state.reserve     = sn_reserve;

  ret = xyzprintf (&state, format, args);
  *state.s = '\0';
  if (ret)
    return sz;
  else
    return state.s - state.str;
}
#endif


#ifndef HAVE_SNPRINTF
int
snprintf (char *str, size_t sz, const char *format, ...)
{
  va_list args;
  int ret;

  va_start(args, format);
  ret = vsnprintf (str, sz, format, args);

  va_end(args);
  return ret;
}
#endif


int
vsprintf (char *str, const char *format, va_list args)
{
  return vsnprintf( str, 0x10000, format, args);
}

int
sprintf (char *str, const char *format, ...)
{
  va_list args;
  int ret;

  va_start(args, format);
  ret = vsprintf (str, format, args);

  va_end(args);
  return ret;
}





// ************************************************************
// see MIPS R4000 user manual by Joe Heinrich, PTR Prentice Hall 
// for information on MIPS floating point numbers and their 
// structure.  Routine written by Adam Fowler 
//
// floating point and double defines
// *************************************************************
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

void Float2String( float f, char *pString )
{
	int		i,frac;

	if (floatConversion( f, 3, &i, &frac )==0)
	{
		*pString=0x00;
		if( f<0 ) {
			*pString++ = '-';
			*pString=0x00;
		}
		itoa( i, pString, 10);
		pString+=(str_len(pString));
		*pString++='.';
		itoa( frac, pString, 10);
	}
	else
	{
		pString[0]='I';
		pString[1]='N';
		pString[2]='F';
		pString[3]=0x0;
	}

}




