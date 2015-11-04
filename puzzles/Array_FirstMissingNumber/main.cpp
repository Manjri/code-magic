/**
 Given a sorted array of m integers where each integer is in the range from 0 to m-1
 Find the smallest number that is missing from the array.
 
 */

#include<stdio.h>

int findFirstMissing(int array[], int start , int end){
    
    if(end<=start+1){
        return start+1;
    }
    else{
        
        int mid = start + (end-start)/2;
        
        if((array[mid] - array[start]) != (mid-start))
            return findFirstMissing(array, start, mid);
        else
            return findFirstMissing(array, mid+1, end);
        
    }
}


// driver program to test above function
int main()
{
    //int arr[] = {0,1,2,3,4,5,6};
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf(" First missing element is %d\n",
           findFirstMissing(arr, 0, n-1));
    return 0;
}
