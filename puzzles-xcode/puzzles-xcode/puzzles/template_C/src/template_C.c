/*
 ============================================================================
 Name        : template_C.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CREATE_STRUCT(TYPE, DEPTH) \
	struct Record_##TYPE##DEPTH			\
	{						\
		TYPE number[DEPTH];		\
	}


int main(void)
{
	CREATE_STRUCT(int, 10) a;
	CREATE_STRUCT(float, 5) b;

	a.number[0] = -2;
	b.number[0] = 3.14;

	printf("\n%d %f",a.number[0], b.number[0]); /* prints  */
	printf("\n%lu %lu",sizeof(a), sizeof(b)); /* prints  */
	return EXIT_SUCCESS;
}
