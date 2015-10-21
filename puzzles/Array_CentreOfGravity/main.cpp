/**
 
 Array = [ 1   2   9   4   -1 ]
 
 1. Calculate Partial/Running sum: PS[i] = PS[i-1]+A[i] ... PS[-1] = 0
 2. Calculate SumLeft: SumLeft[i] = PS[i-1]  ... PS[-1] = 0
 3. Calculate SumRight: SumRight[i] = PS[n-1] - PS[i]
 
 Original_Array  1   2   9   4   -1
 Partial Sum     1   3   12  16  15
 SumLeft         0   1   3   12  16
 SumRight        14  12  3   -1  0
 
 
 */

#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

int CentreOfGravity(int arr[], int n){
    
    int result = -1;
    
    int PS[n];
    int SumLeft[n];
    int SumRight[n];
    
    for(int i = 0; i<n; i++){
        if(i==0){
            PS[i] = arr[i];
            continue;
        }
        PS[i] = PS[i-1] + arr[i];
    }
    
    printArray(PS, n);
    
    for(int i = 0; i<n; i++){
        
        if(i==0){
            SumLeft[i] = 0;
            continue;
        }
        SumLeft[i] = PS[i-1];
    }
    
    printArray(SumLeft, n);
    
    for(int i = 0; i<n; i++){
        SumRight[i] = PS[n-1] - PS[i];
    }
    
    printArray(SumRight, n);
    
    for(int i = 0; i<n; i++){
        
        if(SumRight[i] == SumLeft[i])
            return i;
    }
    
    return result;
}


// Driver program to test above function
int main()
{
    int arr[] =  {1,2,9,4,-1};
    
    cout << CentreOfGravity(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    
    return 0;
}