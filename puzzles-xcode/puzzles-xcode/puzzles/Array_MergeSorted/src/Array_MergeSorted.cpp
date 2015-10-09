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
    void merge(int A[], int m, int B[], int n)
    {
        int i = 0;
        int* a = &A[0];
        int* b = &B[0];
        int cntB = 0;
        int cntA = 0;

        while(i < (m+n))
        {
        	if(cntA >= m)
        	{
        		while(cntB < n)
        		{
        			*a++ = *b++;
        			cntB++;
        		}
        		return;
        	}
        	else if(cntB >= n)
        		return;

        	else if(*b<*a)
            {
                int temp = *a;
                *a = *b;
                i++;
                int j = (m+n-1);
                while(j >= (i+1))
                {
                    A[j] = A[j-1];
                    j--;
                }
                A[i] = temp;
                cntB++;
                b++;
            }
            else
            {
            	cntA++;
            	i++;
            }
            a++;
        }


    }
};

int main() {
	Solution s;
	int A[6] = {0,1,2,8};
	int B[2] = {0,2};
	s.merge(A, 4, B, 2);
	for(int i = 0; i<6; i++)
	{
		cout << A[i] << endl;
	}
	cout << "" << endl; // prints 
	return 0;
}
