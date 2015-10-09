//============================================================================
// Name        : VersionNumbers.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:

	int getMajorOrMinor(string s, int major)
	{
		if(major == 0)
		{
			unsigned i = 0;
			int num = 0;

			while(i < s.length())
			{
				if(s[i] == '.')
					break;

				char d = s[i] - '0';
				num = num*10 + (char)d;
				i++;
			}
			return num;
		}
		else
		{
			unsigned i = 0;

			while(i<s.length() && s[i] != '.')
				i++;
			if(i == s.length())
				return 0;
			else
			{
				int num = 0;
				i++; // skip over the point
				while(i < s.length())
				{
					char d = s[i] - '0';
					num = num*10 + (char)d;
					i++;
				}
				return num;
			}

		}
	}


    int compareVersion(string version1, string version2)
    {
    	int major1 = getMajorOrMinor(version1,0);
    	int major2 = getMajorOrMinor(version2,0);

    	if(major1 == major2)
    	{
    		int minor1 = getMajorOrMinor(version1,1);
    		int minor2 = getMajorOrMinor(version2,1);

    		if(minor1 == minor2)
    			return 0;
    		else if(minor1 > minor2)
    			return 1;
    		else
    			return -1;

    	}
    	else if (major1 > major2)
    		return 1;
    	else
    		return -1;


    }
};

int main() {
	Solution s;
	cout << s.compareVersion("2.5", "2") << endl; // prints
	return 0;
}
