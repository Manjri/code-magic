/*
 ============================================================================
 Name        : SwapNibbles.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char swapNibble(unsigned char input)
{
    unsigned char lower = input & 0x0F;
    unsigned char higher = input & 0xF0;
    unsigned char returnVal = (lower<<4) | (higher>>4);
    return returnVal;
}

int main(void) {
	unsigned char i = 0x13;
	printf("%x", swapNibble(i));
	//puts(""); /* prints  */
	return EXIT_SUCCESS;
}
