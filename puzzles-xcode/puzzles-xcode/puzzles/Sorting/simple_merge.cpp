#include <iostream>
using namespace std;


void merge(int* arr, int* helper, int low, int mid, int high)
{
    int curr = low;
    int helperLow = low;
    int helperHigh = mid+1;

    // start copying
    for(int i=low; i<=high; i++)
    {
        helper[i] = arr[i];
    }

    // 
    while(helperLow <= mid && helperHigh <= high)
    {
        if(helper[helperLow] < helper[helperHigh])
        {
            arr[curr] = arr[helperLow];
            helperLow++;
            curr++;
        }
        else
        {
            arr[curr] = arr[helperHigh];
            helperHigh++;
            curr++;
        }
    }
     // copy remaining elements from left into array
    int remaining = mid - helperLow;
    for(int i=0; i<=remaining; i++)
    {
        arr[curr+i] = helper[helperLow+i];
    }

}

void mergesort(int* arr, int* helper, int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        mergesort(arr, helper, low, mid);
        mergesort(arr, helper, mid+1, high); 
        merge(arr, helper, low, mid, high);
    }
}

void mergesort(int* arr, int size)
{
    int* helper = (int*)malloc(sizeof(int) * size);
    mergesort(arr, helper, 0, size-1);
}




int main()
{
    int arr[4] = {3,4,2,1};
    mergesort(arr, 4);
    return 0;
}