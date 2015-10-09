#include <iostream>
#include <string>
#include <unordered_set>


class Solution {
public:
    bool wordBreak(std::string s, std::unordered_set<std::string>& wordDict)
    {
        if(wordDict.size() == 0)
            return false;
        
        // using DP
        bool **DP = new bool*[s.length()];
        
        for(int i=0; i<s.length(); i++)
        {
            DP[i] = new bool[s.length()];
        }
        
        for(int i=0; i<s.length(); i++)
        {
            for(int j=0; j<s.length(); j++)
            {
                DP[i][j] = false;
            }
        }
        
        
        // fill up the DP table bottom up
        for(int len=1; len<=s.length(); len++)
        {
            for(int i=0; i<(s.length()-(len-1)); i++)
            {
                int j = i + len - 1;
                std::string str = s.substr(i, len);
                
                if(wordDict.find(str) != wordDict.end())
                {
                    DP[i][j] = true;
                    continue;
                }
                for(int k=i+1; k<=j; k++)
                {
                    if(DP[i][k-1]!=false && DP[k][j]!=false)
                    {
                        DP[i][j] = true;
                        break;
                    }
                }
            }//for-i-loop
        }//for-len-loop
        
        return DP[0][s.length()-1];
        
    }
};

int main()
{
    std::string s("ba");
    std::unordered_set<std::string> u;
    
    Solution sln;
    
    u.insert("b");
    u.insert("a");
    
    std::cout << "Ans: " << sln.wordBreak(s, u) << std::endl;
    
    return 0;
}