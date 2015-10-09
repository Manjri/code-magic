//============================================================================
// Name        : ValidParenthesis.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}"
are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
		int len = s.length();
		char currChar;
		stack<int> mystack;
		int i;

		for( i=0; i< len; i++ )
		{
			currChar = s[i];
			int val = 0;

			switch(currChar)
			{
				case ')':
						{
							val = -1;
						}
						break;
				case '}':
						{
							val = -2;
						}
						break;
				case ']':
						{
							val = -3;
						}
						break;

				case '(':
						{
							val = 1;
						}
						break;

				case '{':
						{
							val = 2;
						}
						break;

				case '[':
						{
							val = 3;
						}
						break;
				default:
						return false;

			}
			if(i == 0)
			{
				if(val < 0)
					return false;
				else
				{
					mystack.push(val);
				}

			}
			else
			{
				if(val > 0)
				{
					mystack.push(val);
				}
				else
				{

					if(mystack.empty() || (int)mystack.top() != abs(val))
						return false;
					else
						mystack.pop();
				}
			}

		}
		if(i == len && mystack.empty())
			return true;

		}
};

int main()
{
	Solution s;
	s.isValid("([)}");
	cout << "" << endl; // prints 
	return 0;
}
