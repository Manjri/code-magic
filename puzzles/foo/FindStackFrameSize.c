#include <stdio.h>

int stackframe_size(int run)
{
    int i;

    if(!run)
    {
        return ((int)(&i) - stackframe_size(++run));
        
    }
    return (int)(&i);

}

int FindStackFrameSize()
{
    return stackframe_size(0);
}


int main()
{
    printf("\nSize of stackframe_size() is: %d bytes", FindStackFrameSize()) ;
    return 0;
}