#include <stdio.h>
#include <stdint.h>

// Turn on the nth bit
#define BIT(n)									( 1<<(n) )

// create a bitmask of length 'len'
#define BIT_MASK(len)						( BIT(len)-1 )	

// create a bitfield mask of length 'len' starting at bit 'start'
#define BF_MASK(start, len)			( BIT_MASK(len)<<(start) )

// prepare a bitmask for insertion or combining
#define BF_PREP(x, start, len)	( ((x)&BIT_MASK(len))	<< (start) )

// extract a bitfiled of length 'len' starting at bit 'start' from y
#define BF_GET(y, start, len)		( ((y)>>(start)) & BIT_MASK(len) )

// insert a new bitfield value 'x' into 'y'
#define BF_SET(y, x, start, len)	\
			( y= ((y) & ~BF_MASK(start, len)) | BF_PREP(x, start, len) )

#define BITS_SET(x, start, stop)	\
			( x= (x) | BF_MASK(start, stop) )

#define BITS_CLEAR(x, start, stop)		\
			(x = (x) & ~BF_MASK(start, stop) )


int main()
{
	uint32_t value = 0x1;
	printf("Original: %u\n",value);
	BITS_SET(value, 1, 2);
	printf("Modified: %u\n",value);
	BITS_CLEAR(value, 1, 2);
	printf("Modified: %u\n",value);
	return 0;
}
