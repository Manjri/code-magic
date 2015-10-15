#include <iostream>
#include <string>
#include <unordered_set>

/**
 Given a string s and a dictionary of words dict, determine if s can be segmented
 into a space-separated sequence of one or more dictionary words.
 
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 
 Return true because "leetcode" can be segmented as "leet code".
 */


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
        // only above the diagonal of table will be filled as we are going in forward direction
        // taking lengths 1, 2, 3 ... s.length() and checking
        for(int len=1; len<=s.length(); len++)
        {
            for(int i=0; i<(s.length()-(len-1)); i++)       // i limits to str.length()-len (it can start there)
            {                                               // limit: i<=str.length-len
                int j = i + len - 1;
                std::string str = s.substr(i, len);
                
                if(wordDict.find(str) != wordDict.end())    // word hashes, we are done
                {
                    DP[i][j] = true;
                    continue;
                }
                for(int k=i+1; k<=j; k++)                       // can we break up the word [i][k-1] [k][j]
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
    std::string s("bac");
    std::unordered_set<std::string> u;
    
    Solution sln;
    
    u.insert("ba");
    u.insert("c");
    
    std::cout << "Ans: " << sln.wordBreak(s, u) << std::endl;
    
    return 0;
}