/*
 ============================================================================
 Name        : HeapSort.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *data, int x, int y)
{
	int temp = data[x];
	data[x] = data[y];
	data[y] = temp;
}

void moveDown(int *data, int first, int last)
{
	int largest = 2*first + 1;

	while(largest <= last)
	{
		// first contains 2 children
		if(largest < last && data[largest+1] > data[largest])
			largest++;

		if(data[first] < data[largest])
		{
			swap(data, first, largest);
			first = largest;
			largest = 2*first + 1;
		}
		else
		{
			// heap property is not violated now, exit
			largest = last+1;
		}
	}
}

void heapSort(int *data, int n)
{
	int i = 0;

	for(i=(n/2 -1); i>=0; i--)
		moveDown(data, i, n-1);	//create a heap

	for(i = n-1; i>=1; i--)
	{
		swap(data, 0, i);		//move largest item to data[i]
		moveDown(data, 0, i-1);	//restore heap property
	}
}


int main(void) {
	int a[10] = {5,4,1,7,2,8,6,9,3,0}, i=0;
	heapSort(a, 10);

	for(i=0; i<10; i++)
		printf("%d ",a[i]); /* prints  */

	return EXIT_SUCCESS;
}
