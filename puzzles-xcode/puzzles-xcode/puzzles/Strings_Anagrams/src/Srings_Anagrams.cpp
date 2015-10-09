//============================================================================
// Name        : Srings_Anagrams.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<string> anagrams(vector<string> &str)
	{
		vector<string> res;
		map<string, int> mymap;

		for(int i=0; i<str.size(); i++)
		{
			string s = str[i];
			sort(s.begin(), s.end());

			if(mymap.find(s) != mymap.end())
			{
				// element already exists, add it to res
				res.push_back(str[i]);

				// if the previous anagram wasnt added add it now
				if(mymap[s] != -1)
				{
					res.push_back(str[mymap[s]]);
					mymap[s] = -1;
				}
			}
			else
			{
				mymap.insert(pair<string, int>(s, i));
				//mymap[s] = i;
			}
		}

		return res;
	}
};

int main() {

	vector<string> vec;
	vec.push_back("abc");
	vec.push_back("bac");
	vec.push_back("bdc");
	vec.push_back("cab");

	Solution s;
	vector<string> res = s.anagrams(vec);
	for(int i=0; i<res.size(); i++)
	{
		cout << res[i] << endl; // prints
	}

	return 0;
}
