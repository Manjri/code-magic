/*
 ============================================================================
 Name        : BitTwiddling_Endianess.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char isLittleEndian()
{
	int num = 0x1;
	char* cPtr = (char*)&num;

	return *cPtr;
}

int convertEndian(int num)
{
	unsigned int size = sizeof(int);
	int i = 0, j=0;
	char* cNum = (char*)&num;

	for(i=0, j=(size-1); i<size/2; j--,i++)
	{
		char temp = cNum[i];
		cNum[i] = cNum[j];
		cNum[j] = temp;
	}
	return num;
}


int convertEndian1(int num)
{
	// assuming int is 4 bytes
	int byte0, byte1, byte2, byte3;

	byte0 = ((num & 0x000000FF) >> 0);
	byte1 = ((num & 0x0000FF00) >> 8);
	byte2 = ((num & 0x00FF0000) >> 16);
	byte3 = ((num & 0xFF000000) >> 24);

	return (int)((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));

}

int main(void) {

	int num  = 0x12345678;

	if(isLittleEndian())
		printf("Little Endian");
	else
		printf("Big Endian");


	//printf("\nOriginal: %x Converted: %x",num, convertEndian(num));

	printf("\nOriginal: %x Converted: %x",num, convertEndian1(num));
	return EXIT_SUCCESS;
}
