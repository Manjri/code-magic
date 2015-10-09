#include <stdio.h>

#define OFFSETOF(st, m) ((size_t)&((st*)0)->m)

typedef struct mystruct{
    
    int     a;
    char    b;
    double  c;
    
}mystruct;


int main()
{
    
    printf("Offset of double is: %lu\n", OFFSETOF(mystruct, c));
    
    return 0;
}