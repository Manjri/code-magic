#include <stdio.h>

int getSingle(int arr[], int n)
{
    int result = 0;
    int count[64] = {0};
    
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((arr[j] >> i) & 1)
                count[i]++;
        }
        
        result |= ((count[i] % 3) << i);
    }
    
    return result;
}

int getSingle1(int arr[], int n)
{
    int ones = 0, twos = 0, threes = 0;
    
    for(int i = 0; i<n; i++){
        
        twos |= (ones & arr[i]);
        
        ones ^= arr[i];
        
        threes = ones & twos;
        
        ones &= ~threes;
        
        twos &= ~threes;
    }
    
    return ones;
}


int main()
{
    int arr[] = {3, 3, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The element with single occurrence is %d\n",
           getSingle1(arr, n));
    return 0;
}