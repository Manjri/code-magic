/**
 Question:
 Find the contiguous subarray within an array (containing at least one number) that has the
 largest sum.
 For example, given the array [2, 1, –3, 4, –1, 2, 1, –5, 4],
 The contiguous array [4, –1, 2, 1] has the largest sum = 6.
 
 Solution:
 O(n log n) runtime, O(log n) stack space – Divide and Conquer:
 Assume we partition the array A into two smaller arrays S and T at the middle index, M.
 Then, S = A1 … AM-1, and T = AM+1 … AN.
 The contiguous subarray that has the largest sum could either:
 i. Contain the middle element:
 a. The largest sum is the maximum suffix sum of S + AM + the maximum
 prefix sum of T.
 ii. Does not contain the middle element:
 a. The largest sum is in S, which we could apply the same algorithm to S.
 b. The largest sum is in T, which we could apply the same algorithm to T.
 */

#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))


int maxSubArrayHelper(int A[], int L, int R)
{
    if( L > R)
    {
        cout << L << " - " << R << " Max: " << INT_MIN << endl;
        return INT_MIN;
    }
    int M = ( L + R)/2;
    
    int leftAns = maxSubArrayHelper(A, L, M-1);
    int rightAns = maxSubArrayHelper(A, M+1, R);
    
    int lMaxSum = 0;
    int sum = 0;
    for(int i = M-1; i>=L; i--)
    {
        sum += A[i];
        lMaxSum = MAX(sum, lMaxSum);
    }
    
    int rMaxSum = 0;
    sum = 0;
    for(int i=M+1; i<=R; i++)
    {
        sum += A[i];
        rMaxSum = MAX(sum, rMaxSum);
    }
    
    int tempMax = MAX(lMaxSum + A[M] + rMaxSum, MAX(leftAns, rightAns));
    
    cout << L << " - " << M << " - " << R << " Max: " << tempMax << endl;
    
    return tempMax;
}

int maxSubArray(int A[], int n)
{
    
    return maxSubArrayHelper(A, 0, n-1);
}


int main()
{

    int A[] = {2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int n = sizeof(A) / sizeof(A[0]);
    
    printf("Max Sub-Sequence sum is %d\n", maxSubArray(A, n));

    return 0;

}