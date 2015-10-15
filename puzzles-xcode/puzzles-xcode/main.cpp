#include <stdio.h>
#include <limits.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

/**
 * Bottom up way of solving this problem.
 * Keep coins[] sorted. Otherwise temp[j-arr[i]) + 1 can become Integer.Max_value + 1 which
 * can be very low negative number
 */

// Approach is to try to include the current coin value or to exclude it
// Either way, the preference is to choose minumum number of coins

int minCoinsBottomUp(int total, int coins[], int n)
{
    int temp[total+1];
    
    // Base Case
    temp[0] = 0;
    
    for(int i=1; i<=total; i++)
        temp[i] = INT_MAX - 1;
    
    for(int i=0; i<n; i++)    // try all coins
    {
        for(int j=1; j<=total; j++)  // try all totals
        {
            if(j >= coins[i])
            {
                temp[j] = MIN(temp[j], temp[j-coins[i]]+1);
            }
        }
    }
    return temp[total];
}


int main()
{
    int coins[] = {1, 5, 6, 8};
    int total = 11;
    int n = sizeof(coins)/sizeof(coins[0]);
    printf("%d\n", minCoinsBottomUp(total, coins, n));
    return 0;
}