/*
 ============================================================================
 Name        : Array_QuickSort.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void qSort(int A[], int l, int u)
{

	int t = A[l];
	int i = l, j = u+1;

	if(l>=u)
		return;

	while(1)
	{
		do{
			i++;
		}while(i<=u && A[i]<t);

		do{
			j--;
		}while(A[j]>t);

		if(i>j)
			break;

		swap(A, i, j);
	}
	swap(A, j, l);
	qSort(A, l, (j-1));
	qSort(A, (j+1), u);
}


int main(void) {
	int A[5] = {5,4,2,3,1}, i=0;
	qSort(A, 0, 4);
	for(;i<5; i++)	printf("%d", A[i]);
	return EXIT_SUCCESS;
}
