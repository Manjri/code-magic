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

int form_mask(int start_bit, int num_bits)
{
	return (((1<<num_bits)-1) << start_bit);
}

int extract_bits(int num, int start_bit, int num_bits)
{
	return ((num & form_mask(start_bit, num_bits)) >> start_bit);
}


int main(void) {
	int num = 0xFFFC;
	printf("%x\n", num);
	printf("%x\n", extract_bits(num, 1, 3));
	return EXIT_SUCCESS;
}
