/*
 ============================================================================
 Name        : QuickSort.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition(int a[], int first, int last)
{
	int pivotIndex = first;
	int pivot = a[pivotIndex];
	int centreIndex = first;
	int i = first;
	swap(a, pivotIndex, last);

	while(i<last)
	{
		if(a[i] < pivot)
		{
			swap(a, i, centreIndex);
			centreIndex++;
		}
		i++;
	}
	swap(a, centreIndex, last);
	return centreIndex;
}

int partition1(int a[], int first, int last)
{
	int pivotIndex = first;
	int pivot = a[pivotIndex];
	int i = first;
	int j = last;


	while(i<j)
	{
		while(i<last && a[i] <= pivot)
			i++;

		while(a[j]>pivot)
			j--;

		if(i<j)
			swap(a,i,j);
	}

	swap(a, j, pivotIndex);

	return j;
}

void QuickSort(int a[], int first, int last)
{
	if(first<last)
	{
		int p = partition1(a, first, last);
		QuickSort(a, first, p-1);
		QuickSort(a, p+1, last);
	}
}

void QSort(int a[], int n)
{
	if(n<2)
		return;

	QuickSort(a, 0, n-1);
}


int main(void) {

	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	int i;

	for(i = 0; i<10; i++)
	{
		printf("%d ", a[i]);
	}

	QSort(a, 10);
	printf("\n");

	for(i = 0; i<10; i++)
	{
		printf("%d ", a[i]);
	}

	return EXIT_SUCCESS;
}
