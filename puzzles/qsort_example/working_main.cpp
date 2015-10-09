// qsort example

#include <stdio.h>
#include <stdlib.h>

int arr[] = {10,33,23,99, -11, 45};

int compare(const void* a, const void* b)
{
    
    return ((*(int*)a) - (*(int*)b));
}

int main()
{

    printf("Original::\n");
    
    for(int i=0; i<6; i++)
        printf("%d ", arr[i]);
    
    printf("\n");

    qsort(arr, 6, sizeof(int), compare);
    
    printf("Sorted::\n");
    
    for(int i=0; i<6; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    
    return 0;
}