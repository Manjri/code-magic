/*
 * phoneBook_C.c
 *
 *  Created on: Feb 11, 2015
 *      Author: nikhil
 */

#include <stdio.h>

int len = 10;

char getChar(int x, int y)
{
	char key[10][4]= {{'0'},{'1'},{'a','b','c'},{'d', 'e', 'f'},{'g','h','i'},
				{'j','k','l'},{'m','n','o'},{'p','q','r','s'},
				{'t','u','v'},{'w','x','y','z'}};

	return (char)key[x][y];
}

void phoneBook(int* input, char* output, int pos)
{
	int j;
	if(pos == len)
	{
		printf("%s\n", output);
	}
	else
	{
		int num = input[pos];

		if(num == 0 || num == 1)
		{
			for(j=0; j<1; j++)
			{
				output[pos] = getChar(input[pos],j);
				phoneBook(input, output, pos+1);
			}
		}
		else if(num == 7 || num == 9)
		{
			for(j=0; j<4; j++)
			{
				output[pos] = getChar(input[pos],j);
				phoneBook(input, output, pos+1);
			}
		}
		else
		{
			for(j=0; j< 3; j++)
			{
				output[pos] = getChar(input[pos],j);
				phoneBook(input, output, pos+1);
			}
		}
	}
}

void getCombinations(int* digits)
{
	char output[11];
	output[10] = '\0';
	phoneBook(digits, (char*)&output, 0);
}


int main()
{
	int num[] = {8,5,8,6,6,8,6,7,4,8};
	getCombinations(num);
	return 0;
}


