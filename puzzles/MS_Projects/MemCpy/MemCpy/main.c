#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int a[5] = {0,1,2,3,4};
    int* b = NULL;
    b = (int*)malloc(20);
    memcpy(b,a,20);
    return 0;
}