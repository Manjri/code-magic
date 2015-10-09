#include <iostream>
using namespace std;

int main()
{
    int a = -1;
    unsigned res;
    int const mask = a >> sizeof(int)*CHAR_BIT-1;
    res = (a+mask) ^ mask;
    return 0;
}
