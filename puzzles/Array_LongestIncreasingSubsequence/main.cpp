#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 
 Let S[pos] be defined as the smallest integer that ends an increasing sequence of length pos.
 Now iterate through every integer X of the input set and do the following:
 If X > last element in S, then append X to the end of S. This essentialy means we have found a new largest LIS.
 Otherwise find the smallest element in S, which is >= than X, and change it to X.
 Because S is sorted at any time, the element can be found using binary search in log(N).
 Total runtime - N integers and a binary search for each of them - N * log(N) = O(N log N)
 */


int ceilIndex(vector<int> input, vector<int> T, int end, int s)
{
    int start = 0;
    int middle;
    int len = end;
    
    while(start <= end)
    {
        middle = (start + end)/2;
        
        if(middle<len && input[T[middle]]<s && s<=input[T[middle+1]])
            return middle+1;
        
        else if(input[T[middle]] < s)
            start  = middle + 1;
        
        else
            end = middle - 1;
    }
    
    return -1;
}

int longestIncreasingSubsequence(vector<int> input)
{
    vector<int> T(input.size(), 0);
    vector<int> R(input.size(), -1);
    
    int len = 0;
    
    for(int i=1; i<input.size(); i++)
    {
        // if input[i] is less than 0th value then replace it there
        if(input[i] < input[T[0]])
            T[0] = i;
        
        // if input[i] is greater than the last value of T, then append it in T
        else if(input[i] > input[T[len]])
        {
            len++;
            T[len] = i;
            R[T[len]] = T[len-1];
        }
        // else do a binary search and find the ceiling of input[i] and put it there
        else
        {
            int index = ceilIndex(input, T, len, input[i]);
            T[index] = i;
            R[T[index]] = T[index-1];
        }
    }
    
    // print out the increasing sub-sequence in reverse order
    cout << "Longest Increasing Subsequence: " << endl;
    
    int index = T[len];
    ostringstream oss;
    string s;
    
    while(index != -1)
    {
        oss << input[index] << " ";
        s = oss.str() + s;
        oss.str("");
        //cout << input[index] << " ";
        index = R[index];
    }
    cout << s << endl;
    return len+1;
}

int main()
{
    vector<int> vec = vector<int>{3,4,-1,5,8,2,3,12,7,9,10};
    cout << "Maximum Length is: " << longestIncreasingSubsequence(vec) << endl;
    return 0;
}