#include <stdio.h>

unsigned long long measureStackFrame(int seed)
{
    
    if(seed == 0)
    {
        // recur
        return (unsigned long long)((unsigned long long)&seed - measureStackFrame(++seed));
    }
    else
    {
        return (unsigned long long)&seed;
    }
    
    
}


int main()
{
    printf("Measured stack frame: %llu\n", measureStackFrame(0));
    return 0;
}