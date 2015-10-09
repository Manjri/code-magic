/*
 * palindrome.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: nikhil
 */
#include <iostream>
#include <string>

using namespace std;

#define isAlphaNumeric(x) \
    	((x >= 'a' && x <= 'z') ||  \
    			(x >= 'A' && x <= 'Z') || \
    			(x >= '0' && x <= '9'))

#define isAlphaUpperCase(x) \
    	((x >= 'A' && x <= 'Z'))

#define isAlpha(x) \
    	((x >= 'A' && x <= 'Z') || \
    	(x >= 'a' && x <= 'z'))

#define convertToLower(x) \
    	(x + 'a' - 'A')

#define getLowerCase(x) \
		(isAlphaUpperCase(x) ? convertToLower(x):x)

class Solution
{


public:
    bool isPalindrome(string s)
    {
    	unsigned int start1 = 0;
    	unsigned int start2 = s.size()-1;

        // empty string return true
        if(!s.size())
        {
        	return true;
        }

        while(start1 < start2)
        {
        	while(start1 < s.size() && !isAlphaNumeric(s[start1]))
        		start1++;

        	if(start1 >= s.size())
        		break;

        	while(start2 > 0 && !isAlphaNumeric(s[start2]))
        		start2--;

        	if(start2 < 0)
        		break;

        	if(isAlpha(s[start1]) && isAlpha(s[start2]))
        	{
        		char c1 = getLowerCase(s[start1]);
        		char c2 = getLowerCase(s[start2]);

        		if(c1 != c2)
            		return false;
        	}
        	else
        	{
        		if(s[start1] != s[start2])
        			return false;
        	}

        	start1++;
        	start2--;

        }

        return true;
    }
};

int main()
{
	string str = "aA";
	Solution s;
	cout << s.isPalindrome(str) << endl;
	return 0;
}


