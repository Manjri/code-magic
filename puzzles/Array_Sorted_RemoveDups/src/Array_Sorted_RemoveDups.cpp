//============================================================================
// Name        : RemoveDupsSortedArray.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n)
    {
    	int *arr, *unique;

    	arr = &A[0];
    	unique = &A[0];
    	int count = 0;

    	for(int i=0; i<n; i++)
    	{
    		if(i==0)
    		{
    			count++;
    		}
    		else
    		{
    			if(*arr != *unique)
    			{
    				*(++unique) = *arr;
    				count++;
    			}
    		}
    		arr++;
    	}
    	return count;
    }
};

int main() {
	Solution s;
	int A[10] = {1,1,1,1,1,1,1,1,1,5};
	cout << s.removeDuplicates(A, 10) << endl; // prints "Hello World!!"
	return 0;
}
