/*
 * phoneBook.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: nikhil
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> letterCombinations(string digits)
{
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def",
    						"ghi", "jkl", "mno",
    						"pqrs", "tuv", "wxyz"};
    res.push_back("");

    for (int i = 0; i < digits.size(); i++) // for each digit in string
    {
        vector<string> tempres;

        string chars = charmap[digits[i] - '0'];

        for (int c = 0; c < chars.size();c++)	// for each char in the charMap
            for (int j = 0; j < res.size();j++)	// for each element in the vector res
            {
                tempres.push_back(res[j]+chars[c]); // build the string
                cout << std::string(res[j]+chars[c]) << endl;
            }
        res = tempres;
    }
    return res;
}


int main()
{
	vector<string> result;
	result = letterCombinations(std::string("234"));
	cout << result.size() << endl;

	for(std::vector<string>::iterator it = result.begin(); it != result.end(); it++)
		cout << *it << endl;
}




















#if 0
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    int getChar(int x, int y)
    {
        int key[10][4]= {{'0'},{'1'},{'a','b','c'},{'d', 'e', 'f'},{'g','h','i'},
        			{'j','k','l'},{'m','n','o'},{'p','q','r','s'},
        			{'t','u','v'},{'w','x','y','z'}};

        return key[x][y];
    }

    void phoneBook(string input, vector<string> output, string str, unsigned pos)
    {
        if(pos == input.length()-1)
        {
            output.insert()
        }

    }



    vector<string> letterCombinations(string digits)
    {

        int inputLen = digits.length();
        string res;

        return res;

    }
};
#endif
