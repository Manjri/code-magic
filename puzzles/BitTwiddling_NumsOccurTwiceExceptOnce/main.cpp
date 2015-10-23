class Solution {
public:
    int singleNumber(int A[], int n)
    {
        long number = 0;
        
        for(int i=0; i<n; i++)
        {
            number ^= A[i];
        }
        return number;
    }
};