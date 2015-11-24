#include <stdio.h>
#include <stdlib.h>

// heap struct of size and array of elements

struct MaxHeap{
    int size;
    int *array;
};

// swap function
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapfy function - assumes everything under given root at index idx
// is already heapified
void maxHeapify(struct MaxHeap* maxHeap, int idx){

    int largest = idx; 
    int left = idx*2 + 1;
    int right = idx*2 + 2;

    // check if left child exists & is greater than root
    if(left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
    
    // check if right child exists & is greater than largest so far
    if(right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;

    // change the root if needed
    if(largest != idx){
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        //recurse down cause we changed the root
        maxHeapify(maxHeap, largest);
    }
}

// create a max heap of a given capacity
struct MaxHeap *createAndBuildHeap(int *array, int size){
    struct MaxHeap *maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;
    maxHeap->array = array;

    // start from bottommost and rightmost internal node and heapify all internal
    // nodes in a bottom up way
    for(int i = (maxHeap->size-2)/2; i>=0; i--)
        maxHeapify(maxHeap, i);

    return maxHeap;
}
// Heap Sort function!

void heapSort(int *array, int size){

    // build a heap from the input data
    struct MaxHeap *maxHeap = createAndBuildHeap(array, size);

    // repeat while heap size is greater than 1. the last element in max heap will
    // be the minimum element
    while(maxHeap->size > 1){
        // largest iteam is stored at the root..replace with the last item followed
        // by reducing the size of heap by 1
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size-1]);
        --maxHeap->size;    // reduce heap size

        // finally heapify the root of the tree
        maxHeapify(maxHeap, 0);
    }
}

// print an array of given size
void printArray(int *arr, int size){
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
}

// driver program to test
int main(){

    int arr[] = {12,11,13,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is: \n");
    printArray(arr, size);

    heapSort(arr, size);

    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}
