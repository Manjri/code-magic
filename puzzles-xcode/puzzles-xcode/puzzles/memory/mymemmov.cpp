#include <iostream>

// similar to malloc but checks for overlap
void mymemmov(void* dst, void* src, unsigned int size)
{
    char* chDst = (char*) dst;
    char* chSrc = (char*) src;

    // source is above dest and there is overlap region
    if((chDst > chSrc) && ((char*)chSrc+size-1 > chDst))
    {
        char* chSrcEnd = chSrc+size-1;
        char* chDstEnd = chDst+size-1;
        // start copying from the end
        while( chSrcEnd >= chSrc)
        {
            *chDstEnd-- = *chSrcEnd--;
        }
    }
    else if((chSrc > chDst) && (chDst+size-1 > chSrc))
    {
        char* chSrcBeg = chSrc;
        char* chDstBeg = chDst;
        // start copying from the beginning
        while( chSrcBeg <= chSrcBeg + size -1)
        {
            (*chDstBeg)++ = (*chSrcBeg)++;
        }
    }
}

int main()
{

    return 0;
}