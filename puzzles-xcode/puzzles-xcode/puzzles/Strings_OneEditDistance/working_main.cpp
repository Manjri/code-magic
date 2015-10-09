#include <iostream>
#include <string>

// Given two strings S and T, determine if they are both one edit distance apart.

/**
1. Modify (shift = 0)
 abcde
 abXde

2. Insert/Remove (shift=1)
 abcde
 abXcde
 
3. Append (shift=1)
 abcde
 abcdeX / abcde (shift=0)
 
O(n) time
O(1) space

*/


class Solution {
public:
    bool isOneEditDistance(std::string s, std::string t)
    {
        std::string bigger = t;
        std::string smaller = s;
        unsigned int shift = 0;
        
        if(s.length() > t.length())
        {
            bigger  = s;
            smaller = t;
        }
        
        shift = bigger.length() - smaller.length();
        
        if(shift>1)
            return false;
        
        int index = 0;
        
        while((index < smaller.length()) && (smaller[index] == bigger[index]))
            index++;
        
        // append
        if(index == smaller.length())
            return shift > 0;
        
        // modify & insert
        if(shift == 0)
            index++;
        
        while((index < smaller.length()) && (bigger[index+shift]==smaller[index]))
            index++;
        
        return index == smaller.length();
        
        
    }
};

int main()
{
    std::string s("ba");
    std::string t("a");
    
    Solution sln;
    
    std::cout << "Is One Distance Apart? " << sln.isOneEditDistance(s, t) << std::endl;
    
    return 0;
}