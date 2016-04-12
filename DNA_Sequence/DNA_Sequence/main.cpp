//
//  main.cpp
//  DNA_Sequence
//
//  Created by Nikhil Jagdale on 4/6/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string, bool> mymap;
        vector<string> result;
        
        for(int i=0; (i+9)<s.length(); i++){
            string temp = s.substr(i,10);
            unordered_map<string,bool>::iterator it = mymap.find(temp);
            if(it!=mymap.end() && mymap[temp]==false){
                result.push_back(temp);
                mymap[temp] = true;
            }
            else if(it==mymap.end())
                mymap[temp] = false;
            else{
                // do nothing
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<string> result = s.findRepeatedDnaSequences("AAAAAAAAAAAAA");
    for(auto str : result)
        cout << str << " ";
    cout << endl;
    return 0;
}
