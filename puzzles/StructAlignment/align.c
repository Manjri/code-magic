/*
 * align.c
 *
 *  Created on: Feb 8, 2015
 *      Author: nikhil
 */
//int i /*__attribute((packed))*/;

#include <stdio.h>

struct s
{
	short s1;
	short s2;
	short s3;
};

int main()
{
	struct s myStruct1;
	struct s myStruct2;

	myStruct1.s1 = 1;
	myStruct1.s2 = 2;
	myStruct1.s3 = 3;

	myStruct2.s1 = 4;
	myStruct2.s2 = 5;
	myStruct2.s3 = 6;

	int i = 0xFF;

	printf("Size of struct s: %d", sizeof(myStruct1));
	return 0;
}

