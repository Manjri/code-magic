/*
 * wordsReversal.c
 *
 *  Created on: Feb 10, 2015
 *      Author: nikhil
 */

// function to reverse the words and return the string
// example: How are you --> you are How

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * 1. reverse all the characters in the string
 * so that they are backward
 * eg: how are you -> uoy era woh
 *
 * 2. Now scan the string and start reversing tokens seperated by ' ' delimiter
 *
 * you are how
 *
 * 3. Add the Null Character
 */

void reverseString(char* input, int begin, int end)
{
#if 0
	// get the length
	//int len = strlen(input);
	char* output = malloc((sizeof(char) * len) +1);

	int i = 0;
	int j = len-1;

	strncpy(output, input, sizeof(input));
#endif


	while(begin < end)
	{
		char temp = input[begin];
		input[begin] = input[end];
		input[end] = temp;
		begin++;
		end--;
	}

}


void reverseWords(char* input)
{

	// get the length
	int len = strlen(input);

	reverseString(input, 0, len-1);

	char isWhite = ' ';

	int i = 0;
	int j = 0;

	while(i <= len-1)
	{
		j = 0;
		for(;i<=len-1 && input[i]!=isWhite; i++)
		{
			j++;
		}

		i--; //get back to the end of the word
		reverseString(input, (i-(j-1)), i);  //j-1 cause its 0 indexing
        i++; //back to the space position for i

		i++; //move forward

	}


}


int main()
{
	char str[] = "    how are you    ";

	reverseWords(str);

	printf("%s", str);

	return 0;
}
