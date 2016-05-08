//
//  removeDups.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/7/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "removeDups.h"

int comprFunc(const void *p1, const void *p2){
    
    return *(int*)p1 - *(int*)p2;
    
}

void printArr(int *arr, int n){
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int removeDupsFromArray(int *arr, int n){
    
    // first sort the array ascending
    qsort(arr, n, sizeof(int), comprFunc);
    int count=1;
    
    // loop till n elements - keep 2 pointers
    int *p1=&arr[0], *p2=&arr[0];
    
    for(int i=0; i<n; i++, p1++){
        if(*p1 == *p2)
            continue;
        else{
            *(++p2) = *p1;
            count++;
        }
    }
    return count;
}


int removeDupsFromArrayWOSort(int *array, int length)
{
    int *current , *end = array + length - 1;
    int count =length ;
    for ( current = array + 1; array < end; array++, current = array + 1 )
    {
        while ( current <= end )
        {
            if ( *current == *array )
            {
                *current = *end--;
                count--;
            }
            else
            {
                current++;
            }
        }
    }
    return count;
}


void testDups(){
    
    int arr[] = {1,1,1,1,2,2,2,3,4};
    printf("Before: \n");
    printArr(arr, sizeof(arr)/sizeof(arr[0]));
    int count = removeDupsFromArrayWOSort(arr, sizeof(arr)/sizeof(arr[0]));
    printf("After: \n");
    printArr(arr, count);
#if 0
    int count = removeDupsFromArray(arr, sizeof(arr)/sizeof(arr[0]));
    printf("After: \n");
    printArr(arr, count);
#endif
    
}
