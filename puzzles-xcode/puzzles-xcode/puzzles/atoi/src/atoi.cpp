//============================================================================
// Name        : atoi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

#define isNum(x) \
	(x >= '0' && x <= '9')

#define isSpace(x) \
	(x == ' ')

class Solution
{
private:

public:
    int atoi(string str)
    {
    	long num = 0;
    	int sign = 1;
    	int i = 0;

		while(isSpace(str[i]))
			i++;

		if(str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if(str[i] == '+')
		{
			sign = 1;
			i++;
		}
		while(str[i] != '\0')
		{
			if(isNum(str[i]))
			{
				if(sign==1)
				{
					if(num*10 < INT_MAX - ((str[i] - '0')%10))
						num = num*10 + ((str[i] - '0')%10);
					else
					{
						num = INT_MAX;
						break;
					}
				}
				else
				{
					if(num*10 - 1 < (INT_MAX - ((str[i] - '0')%10)))
						num = num*10 + ((str[i] - '0')%10);
					else
					{
						num = INT_MAX + 1;
						break;
					}
				}
			}
			else
				break;

			i++;
		}

		return num*sign;
    }
};


int main()
{
	string str("-9223372036854775809");
	Solution s;
	cout << s.atoi(str) << endl;
	return 0;
}
