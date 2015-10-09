#include <stdio.h>

int countOnes(int number)
{
    int count = 0;
    unsigned unsignedNum = (unsigned)number;

    while(unsignedNum)
    {
        if(unsignedNum & 1)
            count++;

        unsignedNum = unsignedNum >> 1;
    }

    return count;
}

int main()
{
    int onesCount = countOnes(-1);

    return 0;
}