#include <stdio.h>
#include <stdlib.h>

#define X_SIZE 100
#define Y_SIZE 100

int** My2DAlloc(int rows, int cols) 
{
	int header = rows * sizeof(int*); 
	int data = rows * cols * sizeof(int);
	int** rowptr = (int**)malloc(header + data);
	int* buf = (int*)(rowptr + rows);
	int k;
	for (k = 0; k < rows; ++k) 
	{
		rowptr[k] = buf + k*cols;
	}
	return rowptr;
}

int main()
{
#if 0
	int var1[100][100];
	int ** var2 = NULL;
	int i, j;

	var2 = (int**)malloc(sizeof(int*)*X_SIZE);

	
	// fill the array
	printf("\n Enter the contents....\n");

	for( i = 0; i< X_SIZE; i++)
	{
		var2[i] = (int*) malloc(sizeof(int) * Y_SIZE);

		for(j = 0; j<Y_SIZE; j++)
		{
			var2[i][j] = i + j;
			//scanf("%d", &var2[i][j] ); 
		}
	}
	
	// print the contents with the addresses...
	for( i = 0; i < X_SIZE; i++)
	{
		for(j = 0; j < Y_SIZE; j++)
		{
			printf("[%u]:var2[%d][%d] -> %d (%u)\n",(&var2+i+j), i, j, var2[i][j], &var2[i][j]);
		}
	}
#endif
	My2DAlloc(2,2);

	return 0;
}

