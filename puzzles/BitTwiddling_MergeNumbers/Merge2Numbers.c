#include <stdio.h>

int merge2Nums(int n, int m, int i, int j)
{
    /*
    3 steps:    
    
    1. Clear the bits in n between and including  i and j
    2. Move the number m to the position j and ending at i
    3. Merge the Cleared N and Shifted M
    
    */
    
    /* step 1 involves 2 substeps. 
    left mask and that has all 1s after j 
    right mask that has all 1s before i
    */

    // left mask
    int allOnes  = ~0;
    int leftMask = allOnes << (j+1);

    // right mask
    int rightMask = ((1<<i) -1);

    // merging the 2 masks
    int mask = leftMask | rightMask;

    // Finally step 1
    int n_cleared = n & mask;

    // Step 2
    int m_shifted = m << i;

    // Step 3
    int ans = n_cleared | m_shifted;

}


int main()
{
    int n = 0x400;
    int m = 0x13;
    int i = 2;
    int j = 6;

    int ans = merge2Nums(n, m, i, j);

    return 0;
}