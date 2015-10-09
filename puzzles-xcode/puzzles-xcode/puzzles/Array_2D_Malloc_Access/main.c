/*
 ============================================================================
 Name        : BitTwiddling_ExtractBits.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define X   5
#define Y   3

// global arr pointer
int *arr;

int access_2d_array(int a, int b)
{
    return *(arr + (Y * a) + b);
}

void fill_2d_array(int a, int b, int x)
{
    printf("arr[%d][%d] = %d\n", a, b, x);
    *(arr + (Y * a) + b) = x;
}

void init_2d_array()
{
    arr = (int*)malloc(sizeof(int)* X * Y);
}


int main(void)
{
    init_2d_array();
    
    for(int i = 0; i<X; i++)
    {
        for(int j = 0; j<Y; j++)
        {
            fill_2d_array(i, j , (i+j));
        }
    }
    
    for(int i = 0; i<X; i++)
    {
        for(int j = 0; j<Y; j++)
        {
            printf("arr[%d][%d] = %d\n", i, j, access_2d_array(i, j));
        }
    }
    
    
    return EXIT_SUCCESS;
}
