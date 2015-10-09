#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string shortestPalindrome(string s)
    {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size(),l;
        
        for(l=n;l>=0;l--)
        {
            if(s.substr(0,l)==s2.substr(n-l))
                break;
        }
        string newString = s2.substr(0,n-l);
        return newString+s;
    }
};


int main()
{
    
    Solution s;
    string str("aabaxa");
    cout << "Original:  " << str <<"\nShortest Palindrome: " << s.shortestPalindrome(str) << endl;
    
    return 0;
}