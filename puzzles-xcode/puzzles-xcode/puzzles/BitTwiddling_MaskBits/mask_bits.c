#include <stdio.h>

// clear nth bit
#define clear_n_bit(x, n) \
        (x & ~((unsigned int)1<<n))

// set nth bit
#define set_n_bit(x, n) \
        (x | ((unsigned int)1<<n))

// toggle nth bit
#define toggle_n_bit(x, n) \
        (x ^ ((unsigned int)1<<n))

// test nth bit
#define test_n_bit(x ,n) \
        ((x & (unsigned int)1<<n) >> n)


int main()
{
    int x = (0x80);
    
    printf("\n x = %x",x);
    
    printf("\n Toggling 8th bit of x = %x", toggle_n_bit(x,8));


#if 0
    printf("\n After setting 8th bit, x = %x", set_n_bit(x,8));
    //printf("\n After clearing 8th bit, x = %x",clear_n_bit(x,8));


    printf("\n 8th bit set? %d", test_n_bit_set(x,8));
    
    printf("\n 8th bit clear? %d", test_n_bit_clear(x,8));
#endif 
    return 0;
}