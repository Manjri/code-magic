#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InsertionSortArray(int a[], int len)
{
    int i, j;
    int x;

    if(len<=1)
        return;

    for (i = 1; i <len; i++)
    {
        x = a[i];
        j = i;

        while( j>0 &&  a[j-1] > x)
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = x;
    }


}


int main()
{
    int a[10] = {0};
    int i = 0;

    srand(time(NULL));

    for(i = 0; i<10; i++)
    {
        a[i] = (rand()%100) + 1;
        printf(" %d" ,a[i]);
    }

    printf("\nAfter Sorting.. \n");

    InsertionSortArray(a, 10);

    for(i = 0; i<10; i++)
    {
        printf(" %d" ,a[i]);
    }


    return 0;
}
