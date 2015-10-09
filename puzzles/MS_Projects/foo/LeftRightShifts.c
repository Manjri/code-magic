/* myprog.c */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    int i1, n;
    int i2;
    int i3;

    i1 = 1;
    i2 = 0x80000000;
    
    n=1;

    i3 = i2 >> n;

    printf("\n %d left shifted by %d", i1, i1<<n);


    printf("\n %d right shifted by %d", i2, i3);

    return 0;
}