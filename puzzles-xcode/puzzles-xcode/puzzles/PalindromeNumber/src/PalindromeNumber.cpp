//============================================================================
// Name        : PalindromeNumber.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
    	int num = x;
    	int reverse = 0;

    	if(num < INT_MIN || num > INT_MAX)
    		return false;

    	while(num)
    	{
    		reverse = reverse*10 + num%10;
    		num /= 10;
    	}
    	return (reverse == x);
    }
};

int main() {

	Solution s;
	cout << INT_MIN << endl << s.isPalindrome(-2147447412) << endl; // prints
	return 0;
}
