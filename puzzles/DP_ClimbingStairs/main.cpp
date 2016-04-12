// A C program to count number of ways to reach n't stair when
// a person can climb 1, 2, ..m stairs at a time
#include<stdio.h>

int fib(int n){
    
    int arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2; i<=n; i++)
        arr[i] = arr[i-1] + arr[i-2];
    
    for(int i=0; i<=n; i++)
        printf(" a[%d]=%d ",i, arr[i]);
    printf("\n");
    
    return arr[n];
    
}
// countWays2 is a special case for taking only 1 or 2 steps
int countWays2(int s)
{
    return fib(s+1);
}


// A recursive function used by countWays (Generalized upto m steps)
int countWaysUtil(int n, int m)
{
    int res[n];
    res[0] = 1; res[1] = 1;
    for (int i=2; i<n; i++)
    {
    res[i] = 0;
    for (int j=1; j<=m && j<=i; j++)
        res[i] += res[i-j];
    }
    #if 0
    for(int i=0; i<n; i++)
        printf(" a[%d]=%d ",i, res[i]);
    printf("\n");
    #endif
    return res[n-1];
}

// Returns number of ways to reach s'th stair
int countWays(int s, int m)
{
    return countWaysUtil(s+1, m);
}

// Driver program to test above functions
int main ()
{
    int s = 2, m = 2;
    printf("Number of ways (Count2) = %d\n", countWays2(s));
    printf("Number of ways (Count1) = %d\n", countWays(s, m));
    return 0;
}

