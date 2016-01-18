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

int arr[] = {3,4,5,2,1};

void swap1(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void qSort1(int A[], int l, int u)
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
        
        swap1(A, i, j);
    }
    swap1(A, j, l);
    qSort1(A, l, (j-1));
    qSort1(A, (j+1), u);
}

void swap(int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quicksort(int l, int u){
    int i, m;
    if(l >= u) return;
    m = l;
    for(i = l+1; i<= u; i++)
        if(arr[i] < arr[l])
            swap(++m, i);

    swap(l, m);

    quicksort(l, m-1);
    quicksort(m+1, u);

}

int main(void) {
    //quicksort(0,4);	
    qSort1(arr, 0, 4);	
    int i;
    for(i=0;i<5; i++)	
        printf("%d", arr[i]);
    printf("\n");
	return EXIT_SUCCESS;
}
