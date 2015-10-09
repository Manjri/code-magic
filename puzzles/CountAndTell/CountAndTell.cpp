/*
 * CountAndTell.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: nikhil
 */
#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Solution {
public:

    string countAndSay(int n) {

        int num_count[10] = {0};
        std::string s;
        std::string val;
        ostringstream ss;

        if(n == 1 )
        {
        	return "1";
        }
        s.clear();
        val.append("1");
        for(int i = 1; i<n; i++)
        {
        	s.clear();
            for(std::string::iterator it = val.begin(); it != val.end();)
            {
            	char ch = *it;
            	int num = ch - '0';
                num_count[num]++;
            	while(it!=val.end() && *++it==ch )
            	{
            		num_count[num]++;
            	}
            	ss << num_count[num];
            	s.append(ss.str());
            	ss.str(std::string());
            	ss << num;
            	s.append(ss.str());
            	ss.str(std::string());
            	num_count[num] = 0;
            }
            val = s;
        }
        return s;
    }
};

int main()
{
	Solution s;
	for(int i= 1; i<=20; i++)
		cout << "i:" << i << " " << s.countAndSay(i) << endl;

}





