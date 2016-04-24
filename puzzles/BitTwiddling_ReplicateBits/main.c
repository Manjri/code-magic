#include <stdio.h>
#include <limits.h>

#define BIT(n)                  (1<<n)
#define BITS(n)                 (BIT(n)-1)
#define BIT_MASK(num, start)    (BITS(num)<<(start))

// replicate bits from (and inclusive) ith to jth
// from y into x
void replicateBits(unsigned char x, unsigned char y,
                   unsigned char i, unsigned char j){

    printf("x: %x\ny: %x\n",x, y);
    unsigned char mask = y & BIT_MASK((i-j+1), j);
    printf("Mask: %x\n", mask);
    unsigned char high = x & BIT_MASK((CHAR_BIT-1-i+1), (i+1));
    printf("High: %x\n", high);
    unsigned char low = x & BIT_MASK(j,0);
    printf("Low: %x\n", low);
    x = (high | mask | low);
    printf("x: %x\n",x);
}

void testReplicateBits(){
    unsigned char x = 0b11001110;    //0xce->0xbe
    //unsigned char y = 0b11111111;    //0xff
    unsigned char y = 0b00111111;    //0xff
    replicateBits(x, y, 6, 4);
}

int main(int argc, const char * argv[]) {
    testReplicateBits(); 
    return 0;
}
