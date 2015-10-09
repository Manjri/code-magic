/*
 * main.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: nikhil
 */
#include <iostream>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(const char *s)
    {
    	// find the size and go till end
    	int pos = 0;
    	int i = 0;
    	int size = 0;

    	for(i = 0; s[i]!= '\0'; i++)
    		;
    	pos = i-1; // last char of string

    	// find first non-space char
    	while(pos >= 0)
    	{
    		if(s[pos] == ' ')
    			pos--;
    		else
    			break;
    	}

    	if (pos == -1)
    		return 0;

    	while(pos >= 0)
    	{
    		if(s[pos] != ' ')
    		{
    			size++;
    			pos--;
    		}
    		else
    			break;
    	}
    	return size;

    }
};

int main()
{
	Solution s;
	const char str[] = " ab";
	cout << s.lengthOfLastWord(str) << endl;
	return 0;
}



