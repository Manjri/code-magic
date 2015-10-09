#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int len = strs.size();
        int minSize = INT_MAX;
        int minIndex = 0;
        string result("");
        
        // corner case - no element
        if(len == 0)
            return result;
        
        // corner case - single element
        if(len == 1)
        {
            result = strs[0];
            return result;
        }
        
        
        //find shortest string from vector
        for(int i=0; i<len; i++)
        {
            size_t size = strs[i].size();
            if( size < minSize)
            {
                minSize = size;
                minIndex = i;
            }
        }
        
        for(int i=minSize; i>=0; i--)
        {
            result = strs[minIndex].substr(0,i);
            
            // now match the other strings
            int j = 0;
            for(; j<len; j++)
            {
                // skip for the minSize string
                if(j == minIndex)
                    continue;
                
                string temp = strs[j].substr(0,i);
                
                // all the vector elements must match
                if(result != temp)
                {
                    break;
                }
                
            }
            if(j == len)
                return result;
        }
        
        return result;
    }
};

int main()
{
    
    vector<string> vec;
    vec.push_back("abcd");
    vec.push_back("abc");
    vec.push_back("ab");
    Solution s;
    
    cout << "Common Prefix: " << s.longestCommonPrefix(vec) << endl;
    
}
