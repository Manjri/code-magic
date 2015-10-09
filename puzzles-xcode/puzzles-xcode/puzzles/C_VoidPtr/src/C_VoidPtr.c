/*
 ============================================================================
 Name        : C_VoidPtr.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	//char c = 'A';
	int a  = 10;
	void *cp = &a;
	printf("\n%p",cp); /* prints  */
	cp = cp + 2;
	printf("\n%p",cp); /* prints  */

	return EXIT_SUCCESS;
}
