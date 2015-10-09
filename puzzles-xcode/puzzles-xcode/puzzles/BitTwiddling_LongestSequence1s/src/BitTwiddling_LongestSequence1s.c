/*
 ============================================================================
 Name        : BitTwiddling_LongestSequence1s.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void longestSequence(char* arr, int size, int* rpos, int* rcount)
{
	int i;
	int pos = 0, tpos = 0, count = 0, tcount = 0;

	for(i = 0; i<size; i++)
	{
		if(arr[i] == 0)
			continue;
		else
		{
			tpos = i;
			tcount = 0;
			while(i<size && arr[i]!=0)
			{
				i++;
				tcount++;
			}
			if(tcount > count)
			{
				count = tcount;
				pos = tpos;
			}
		}
	}
	*rpos = pos;
	*rcount = count;
}

int main(void)
{
	char arr[] = {0,1,1,1,0,1,1,0,1,1,0};
	int pos;
	int count;
	longestSequence(arr, sizeof(arr)/sizeof(arr[0]), &pos, &count);
	printf("\nPosition = %d, Count = %d",pos, count);
	return EXIT_SUCCESS;
}
