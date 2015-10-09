// unsigned_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define ARR_SIZE 3

int SumArray(unsigned int *arr, unsigned int size)
{
	int i;
	int sum = 0;

	for(i=0; i<ARR_SIZE; i++)
	{
		printf("Arg = %u\n", arr[i]);
		sum+= arr[i];
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[ARR_SIZE] = {0,-50, 49};
	printf("Sum = %d", SumArray(a, ARR_SIZE));
	getchar();
	return 0;
}

