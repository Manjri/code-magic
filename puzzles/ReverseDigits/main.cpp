/*
 * main.c
 *
 *  Created on: Feb 21, 2015
 *      Author: nikhil
 */
#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {

    	long reversed = 0;

    	while(x)
        {
        	reversed = (reversed * 10) + x%10;

        	if(reversed > INT_MAX || reversed < INT_MIN)
        	{
        		return 0;
        	}

        	x /= 10;
        }

        return reversed;
    }
};

int main()
{
	Solution s;
	//cout << "INT_MAX = "<< INT_MAX << endl;
	//cout << "-INT_MAX = "<< INT_MIN << endl;
	cout << s.reverse(-2147483412) << endl;
	return 0;
}

#if 0

class Solution
{
public:
    int reverse(int x)
    {
        stack<int> intStack;
        bool isNegative = false;
        int factor = 1;
        int reversed = 0;

        if(x<0)
        {
            isNegative = true;
            x *= -1;
        }
        while(x)
        {
            intStack.push(x%10);
            x = x/10;
        }

        while(!intStack.empty())
        {
        	if(intStack.top() > INT_MAX / factor)
        		return 0;

        	if(reversed < INT_MAX - (intStack.top() * factor))
        	{
        		reversed += (intStack.top() * factor);

        		if(isNegative && (reversed > INT_MAX-1))
        			return 0;

        		factor *= 10;
        		intStack.pop();
        	}
        	else
            	return 0;
        }

        if(isNegative)
            reversed *= -1;

        return reversed;
    }
};

#endif
