#include <stdio.h>
#include <stdlib.h>

void makeZeroMatrix(int** matrix, int m, int n)
{
}

// fill the matrix

void fill(int** m, int x, int y)
{

    int i,j;

    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            m[i][j] = i+j;
        }
    }
}

void display(int** m, int x, int y)
{

    int i,j;

    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    int m=4, n=3;
    int i;

    // allocate space for a 2D matrix
    int **matrix;
    int *temp;

    matrix = (int**)malloc(sizeof(int*)*m);

    temp = (int*)malloc(m*n*sizeof(int));

    for(i = 0; i<m; i++)
    {
        matrix[i] = temp + (i*n);
    }

    fill(matrix, m,n);
    display(matrix, m, n);
    return 0;
}