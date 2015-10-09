#include <iostream>
using namespace std;

template <class T>
void swap(T data[], T first, T second)
{
    T temp;
    temp = data[first];
    data[first] = data[second];
    data[second] = temp;
}


void insertion_sort(int* data, int len)
{
    for(int i = 1; i < len; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(data[j] < data[j-1])
                swap(data, j-1, j);
            else
                break;
        }
    }
}

void selection_sort(int* data, int len)
{
    int x,y,temp,index_of_min;
    
    for(x=0; x<len; x++)
    {
        index_of_min = x;

        for(y=x; y<len; y++)
        {
            if(data[index_of_min] > data[y])
                index_of_min = y;
        }

        temp = data[x];
        data[x] = data[index_of_min];
        data[index_of_min] = temp;
    }   
}

template <class T>
void moveDown(T data[], int first, int last)
{
    int largest = 2*first + 1;
    while(largest <= last)
    {
        if(largest < last && data[largest] < data[largest+1])
            largest++;

        if(data[first] < data[largest])
        {
            swap(data, first, largest);
            first = largest;
            largest = 2*first + 1;
        }
        else
            largest = last + 1; // to exit the loop
    }

}

template <class T>
void printArray(T arr, int size)
{
    cout << "\nArray Is... " << endl;
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
}

template <class T>
void heapSort(T arr[], int n)
{
    // generate the heap
    for(int i=n/2 -1; i>=0; --i)
    {
        moveDown(arr, i, n-1);
    }
    for(int i=n-1; i>=1; --i)
    {
        swap(arr, 0, i); 
        moveDown(arr, 0, i-1);
    }
    
}


template<class T>
void quicksort(T data[], int first, int last)
{
    int lower = first+1, upper = last;
    
    // find the bound and push stash to the first position
    swap(data, first, (first+last)/2);

    T bound = data[first];

    while(lower <= upper)
    {
        // find the first instance where data[lower] exceeds the bound
        while(bound > data[lower])
            lower++;

        // find the first instance where data[upper] is below the bound
        while(bound < data[upper])
            upper--;

        // interchange it so that these two elements are in their proper sub-arrays
        if(lower < upper)
            swap(data, lower++, upper--);
        else
            lower++; //to break out of the loop
        
    }
    // put the bound back into its position
    swap(data, first, upper);

    // now recurse through the sub-arrays
    if(first < upper-1)
        quicksort(data, first, upper-1);
    if(last > upper+1)
        quicksort(data, upper+1, last);
}

template<class T>
void quicksort(T data[], int n)
{
    int i, max;
    
    if(n<2)
        return;

    // find the largest element
    for(i=1, max=0; i<n; i++)
        if(data[i] > data[max])
            max = i;

    // put the largest element at the end of the data[]
    swap(data, max, n-1);

    // largest element is now in its proper position
    quicksort(data, 0, n-2);

}

template<class T>
void merge(T data[], int left, int right, T temp[])
{
    int mid = (left+right)/2;
    int l = left, r= mid+1, t=0;

    while(l <= mid && r <= right)
    {
        if(data[l] < data[r])
            temp[t++] = data[l++];
        else
            temp[t++] = data[r++];
       
    }

    while(l <= mid)
        temp[t++] = data[l++];

    while(r <= right)
        temp[t++] = data[r++];

    cout << "\n left: " << left << " Right: " << right << " \n";
    //copy it back
    for(int i=left, k=0; i<=right; i++, k++)
    {
        data[i] = temp[k];
        cout << " " << i << " ";  
    }
    cout << "\n";
}

template<class T>
void merge_helper(T data[], int first, int last, T temp[])
{
    if(first < last)
    {
        int mid = (first+last)/2;
        merge_helper(data, first, mid, temp);
        merge_helper(data, mid+1, last, temp);
        merge(data, first, last, temp);
        
    }
    
}


// merge sort

template<class T>
void mergesort(T data[], int size)
{
    T *temp = (T*)malloc(sizeof(T)*size);
    merge_helper(data, 0, size-1, temp);
}


int main()
{
    int arr[9] = {2,8,6,1,10,15,3,12,11};
    int n = 9;
    
    printArray(arr, 9);
    
    // now sort
    cout << "\n Sorted Array is: ";
    heapSort(arr, n);
    

    printArray(arr, n);
    //quicksort(arr, 9);
    //mergesort(arr, 9);
    //insertion_sort(arr, arr_size);
    //selection_sort(arr, arr_size);
    return 0;
}
