#include <stdio.h>

/**
Consider what happens at the bit level when
you subtract 1 from a number. Subtracting 1 produces a value that has all the same bits as the original
integer except that all the low bits up to and including the lowest 1 are flipped. For example, subtracting
1 from the value 01110000 results in the value 01101111.
If you apply the AND operation to the integer and the result of the subtraction, the result is a new number
that is the same as the original integer except that the rightmost 1 is now a 0. For example, 01110000
AND (01110000 – 1) = 01110000 AND 01101111 = 01100000.
*/

int powerOf2(int number)
{

    int check = (number > 0) && ((number & (number-1)) == 0);
    return check;
}

int main()
{
    int ans = powerOf2(4);
    return 0;
}