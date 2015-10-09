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

// extract the 2nd nibble (bits 4-7)

int extract_bits(int num, int start, int num_bits)
{
unsigned mask = ((1 << num_bits) - 1) << start;
//printf("Mask = %x\n", mask);
return (num & mask) >> start;
}

int set_bits(int num, int start, int num_bits)
{
return ((((1 << num_bits) - 1) << start) | num);
}

int clear_bits(int num, int start, int num_bits)
{
return (~(((1 << num_bits) - 1) << start) & num);
}



int main(void) {
int num = 0xFFA3;
printf("%x\n", num);
printf("%x\n", extract_bits(num, 4, 4));
printf("%x\n", set_bits(num, 4, 4));
printf("%x\n", clear_bits(num, 4, 4));
return EXIT_SUCCESS;
}
