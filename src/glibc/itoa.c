
/* 
 * Rewritten 12/13/2000 by Manuel Novoa III.
 * Fixed insufficient buffer allocation.
 * Fixed problem handling INT_MIN.
 */

#include <limits.h>

#if INT_MAX > 2147483647
#error need to increase size of buffer
#endif

/* 10 digits + 1 sign + 1 trailing nul */
static char buf[12];

//char *_itoa( int value, char *string, int radix );
char *itoa(int i, char* string, int radix)
{
	char *pos = buf;
	unsigned int u;
	int negative = 0;

	if (i < 0) {
		negative = 1;
		u = ((unsigned int)(-(1+i))) + 1;
	} else {
		u = i;
	}

	do {
		*pos++ = '0' + (u % radix);
		u /= radix;
	} while (u);

	if (negative) {
		*++pos = '-';
	}

	u=0;
	while((&buf[0])<=pos){
		string[u++]=*--pos;
	}
	return pos;
}
