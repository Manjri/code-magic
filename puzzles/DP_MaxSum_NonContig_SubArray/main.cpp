#include<stdio.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

/*Function to return max sum such that no two elements
 are adjacent */
int FindMaxSum(int arr[], int n)
{
    int incl = arr[0];
    int excl = 0;
    
    for (int i = 1; i < n; i++)
    {
        int temp = incl;
        incl = MAX(excl + arr[i], incl);
        excl = temp;
    }
    
    return incl;
}

/* Driver program to test above function */
int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    printf("%d \n", FindMaxSum(arr, 6));
    getchar();
    return 0;
}
