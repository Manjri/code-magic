/**
 Question:
 You are climbing a staircase. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to
 the top?
 
 Solution:
 O(n) runtime, O(1) space – Dynamic programming:
 This is a classic Dynamic Programming problem.
 Define:
 f(n) = number of ways you can climb to the nth step.
 To reach to the nth step, you have only two choices:
 1. Advance one step from the n – 1th step.
 2. Advance two steps from the n – 2th step.
 Therefore, f(n) = f(n – 1) + f(n – 2), which is the exact same recurrence formula defined
 by the Fibonacci sequence (with different base cases, though).
 Set base cases f(1) = 1, f(2) = 2 and you are almost done.
 Now, we could calculate f(n) easily by storing previous values in an one dimension array
 and work our way up to n. Heck, we can even optimize this further by storing just the
 previous two values.
*/

#include <iostream>
using namespace std;


int climbStairs(int n)
{
    int p = 1;
    int q = 1;
    
    for (int i=2; i<=n; i++)
    {
        int temp  = q;
        q += p;
        p = temp;
    }
    
    return q;
}

int main()
{
    int n = 5;
    
    cout << "Climbing " << n << " stairs 1/2 steps at a time can be done in " <<
    climbStairs(n) << " ways" << endl;
    
    return 0;
}
