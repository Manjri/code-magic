//============================================================================
// Name        : RemoveElement.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Solution
{
public:

    int removeElement(int A[], int n, int elem)
    {
    	int i = 0, j = 0;

    	while(i < n)
    	{
    		if( A[i]!=elem )
    		{
    			A[j] = A[i];
    			j++;
    		}
    		i++;
    	}
    	return j;
    }
};

int main() {
	Solution s;
	int A[] = {1,3,4,6};
	cout << s.removeElement(A, 4, 3) << endl; // prints
	return 0;
}
