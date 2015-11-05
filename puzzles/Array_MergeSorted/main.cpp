//============================================================================
// Name        : Array_MergeSorted.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    // assume A has enough space to hold values m+n
    // A and B are both sorted arrays
    void merge(int A[], int m, int B[], int n)
    {
        // trick is to start from back and insert elements in the proper position
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        
        while(k>=0){
            if((j<0) || (i>=0 && A[i]>B[j]))    // either B is empty or A[last_pos] > B[last_pos]
                A[k--] = A[i--];
            else                                // A is empty or A[last_pos] < B[last_pos] & B is non-empty
                A[k--] = B[j--];
        }
    }
};



int main() {
    Solution s;
    int A[6] = {0,1,2,8};
    int B[2] = {3,7};
    s.merge(A, 4, B, 2);
    for(int i = 0; i<6; i++)
    {
        cout << A[i] << endl;
    }
    cout << "" << endl; // prints 
    return 0;
}
