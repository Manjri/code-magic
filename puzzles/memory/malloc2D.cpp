#include <iostream>
using namespace std;

int** My2DAlloc(int i, int j);
void My2DDealloc(int** arr);

int** My2DAlloc(int nrows, int ncols)
{
    int** rowptr = (int**)malloc(sizeof(int*) * nrows);

    for(int i=0; i<nrows; i++)
    {
        rowptr[i] = (int*)malloc(sizeof(int)*ncols);
    }

    return rowptr;
}

void My2DDealloc(int** arr, int nrows)
{
    for(int i=0; i<nrows; i++)
    {
        free(arr[i]);
    }

    free(arr);
}


int** MyEfficient2DAlloc(int rows, int cols)
{
    int header = rows * sizeof(int*);
    int data = rows*cols*sizeof(int);

    int** rowptr = (int**)malloc(header+data);

    int* buffer = (int*)(rowptr + rows);

    for(int i=0; i<rows; i++)
    {
        rowptr[i] = buffer + i*cols;
    }

    return rowptr;

}


int main()
{
    return 0;
}