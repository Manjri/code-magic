/*
 ============================================================================
 Name        : atoi_check.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char s[] = "   +0 123";
	printf("%d", atoi(s));
	return EXIT_SUCCESS;
}
