//============================================================================
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    void reverseWords(string &s)
    {
        string result;
        unsigned int i;
        
        for(i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            
            int pos = i;
            
            while(i<s.size() && s[i]!= ' ')
                i++;
            
            if(result.size() != 0)
                result =  ' ' + result;
            
            result = s.substr(pos, i-pos) + result;
            
            i--;
        }
        
        s = result;
    }
};

int main() {
    Solution s;
    string str("Hello World!");
    
    s.reverseWords(str);
    //cout << str.size()<< endl;
    cout << str << endl;
    
    return 0;
}
