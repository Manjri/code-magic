//============================================================================
// Name        : ZigZagPattern.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

// PAYPALISHIRING
// 01234567890123
// P   A   H   N
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int nRows)
    {
    	int size = s.size();
    	vector<int> v;

    	for(int i=0; i<size; i++)
    		v[i] = s[i];

    }
};

int main() {
	cout << "" << endl; // prints 
	return 0;
}
