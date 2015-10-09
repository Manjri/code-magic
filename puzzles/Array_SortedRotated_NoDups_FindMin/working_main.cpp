#include <iostream>

using namespace std;


int findMin(int arr[], int l, int h)
{
    
    while((l < h) && (arr[l] >= arr[h]))
    {
        int m = (l+h)/2;
        
        if(arr[m] > arr[h])
        {
            // pivot point lies after mid-pt
            l = m+1;
        }
        else
        {
            // pivot point lies before mid-pt
            h = m;
        }
    }
    
    return arr[l];
}


int findMinSortedRotated(int arr[], int n)
{
    return findMin(arr, 0, n-1);
}

int main()
{
    int arr[] = {5,6,7,1,2,3,4};
    cout << findMinSortedRotated(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    return 0;
}
