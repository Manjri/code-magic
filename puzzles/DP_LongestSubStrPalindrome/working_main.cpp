/*
 ============================================================================
 Name        : SwapNibbles.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <iostream>
#include <string>
using namespace std;

/**
 Method 1 ( Brute Force )
 The simple approach is to check each substring whether the substring is a
 palindrome or not. We can run three loops, the outer two loops pick all
 substrings one by one by fixing the corner characters, the inner loop checks
 whether the picked substring is palindrome or not.
 
 Time complexity: O ( n^3 )
 Auxiliary complexity: O ( 1 )
 
 
 Method 2 ( Dynamic Programming )
 The time complexity can be reduced by storing results of subproblems.
 We maintain a boolean table[n][n] that is filled in bottom up manner.
 The value of table[i][j] is true, if the substring is palindrome, otherwise false.
 To calculate table[i][j], we first check the value of table[i+1][j-1], if the
 value is true and str[i] is same as str[j], then we make table[i][j] true.
 Otherwise, the value of table[i][j] is made false.
 
 */


string longestPalindromeDP(string s)
{
    int n = s.length();
    int longestBegin = 0;
    int maxLen = 1;
    bool table[1000][1000] = {false};
    
    for(int i = 0; i < n; i++)
        table[i][i] = true;
    
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            table[i][i+1] = true;
            longestBegin = i;
            maxLen = 2;
        }
    }
    
    for(int len = 3; len <= n; len++)
    {
        for(int i = 0; i < n - len +1; i++)
        {
            int j = i+len-1;
            if( s[i] == s[j] && table[i+1][j-1])
            {
                table[i][j] = true;
                longestBegin = i;
                maxLen = len;
            }
        }
    }
    return s.substr(longestBegin, maxLen);
}


int main()
{
    string s("ababa");
    cout << longestPalindromeDP(s) << endl;
    
    return 0;
}