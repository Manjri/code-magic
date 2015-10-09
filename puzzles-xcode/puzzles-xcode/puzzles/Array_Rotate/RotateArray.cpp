//============================================================================
// Name        : RotateArray.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3,
the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
=== ROTATE RIGHT ===
[1,2,3,4,5,6,7]

[7,6,5,4,3,2,1] - Reverse 0,N-1
[5,6,7,4,3,2,1] - Reverse 0,k-1
[5,6,7,1,2,3,4] - Reverse k,N-1


=== ROTATE LEFT ===
[1,2,3,4,5,6,7]

[3,2,1,4,5,6,7] - Reverse 0,k-1
[3,2,1,7,6,5,4] - Reverse k,N-1
[4,5,6,7,1,2,3] - Reverse 0,N-1

*/

#include <iostream>
using namespace std;

class Solution
{
public:

    void reverse(int* start, int* end)
    {
        int temp;
        while(start < end)
        {

            temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }


    void rotate(int nums[], int n, int k)
    {
        k = k%n;
        reverse(&nums[0], &nums[n-1]);
        reverse(&nums[0], &nums[k-1]);
        reverse(&nums[k], &nums[n-1]);
    }
};

int main() {
	cout << "" << endl; // prints 
	return 0;
}
