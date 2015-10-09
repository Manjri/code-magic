/*
 ============================================================================
 Name        : Arrays_Add_2_Large_Numbers.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a) > (b) ? (a):(b)

char* add2Nums(char* s1, char* s2)
{
	int max, i;
	int *res = NULL;
	int *num1, *num2;
	char* resStr;

	//find lengths
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int carry = 0;

	max = MAX(len1, len2);

	num1 = calloc(max,sizeof(int));
	num2 = calloc(max,sizeof(int));

	// max + 1 for a possible carry
	res = malloc(sizeof(int)*(max+1));

	// add num1 and num 2 to arrays
	for(i=0;i<len1;i++)
	{
		// store lsb at 0th position, hence backward in string
		num1[i] = s1[len1-1-i] - 48;	// -48 to convert from ASCII
	}

	for(i = 0; i<len2; i++)
	{
		num2[i] = s2[len2-1-i] - 48;
	}

	for(i=0; i<max; i++)
	{
		int sum = num1[i]+num2[i]+carry;
		res[i] = sum%10;
		carry = sum/10;
	}
	// possible carry over
	res[max] = carry;

	resStr = malloc(sizeof(char)*(max+2));

	for(i = 0; i<=max; i++)
	{
		// store it backwards in string for readability
		resStr[i] = res[max - i] + 48;	// +48 to convert to ASCII
	}

	return resStr;
}


int main(void)
{
	char s1[] = "123456";
	char s2[] = "789";

	printf("%s + %s = %s\n",s1, s2, add2Nums(s1,s2));

	return EXIT_SUCCESS;
}
