We strongly recommend you to minimize your browser and try this yourself first.
/**
The idea is simple, we start from 1 and go till a number whose square is smaller than or equals to n. For every number x, we recur for n-x. Below is the recursive formula.

If n <= 3, then return n
Else
minSquares(n) = min {1 + minSquares(n - x*x)}
where x >= 1 and x*x <= n
Below is a simple recursive solution based on above recursive formula.
*/



// A naive recursive C++ program to find minimum
// number of squares whose sum is equal to a given number
#include<bits/stdc++.h>
using namespace std;

// Returns count of minimum squares that sum to n
int getMinSquares(unsigned int n)
{
    // base cases
    if (n <= 3)
        return n;
    
    // getMinSquares rest of the table using recursive
    // formula
    int res = n; // Maximum squares required is n (1*1 + 1*1 + ..)
    
    // Go through all smaller numbers
    // to recursively find minimum
    for (int x = 1; x <= n; x++)
    {
        int temp = x*x;
        if (temp > n)
            break;
        else
            res =  min(res, 1+getMinSquares(n - temp));
    }
    return res;
}

// Driver program
int main()
{
    cout << getMinSquares(6);
    return 0;
}