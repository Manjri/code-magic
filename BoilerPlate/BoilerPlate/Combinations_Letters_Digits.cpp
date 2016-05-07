//
//  Combinations_Letters_Digits.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/7/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "Combinations_Letters_Digits.hpp"

using namespace std;

vector<string> alpha = {"0123456789", "0123456789", "0123456789", "0123456789",
    "0123456789", "0123456789","0123456789", "0123456789",
    "0123456789", "0123456789"};

vector<string> alpha1 = {"0", "1", "abc", "def",
    "ghi", "jkl","mno", "pqrs",
    "tuv", "wxyz"};

vector<string> printCombinations(string s){
    
    vector<string> result = {""};
    
    for(int i=0; i<s.size(); i++){
        
        string chars = alpha[s[i]-'0'];
        vector<string> resultDelta;
        
        for(int c=0; c<chars.size(); c++){
            
            char letter = chars[c];
            
            for(int j=0; j<result.size(); j++){
                string s = result[j]+letter;
                resultDelta.push_back(s);
            }//result elements
        } // letters in map
        result = resultDelta;
    }//string digits
    return result;
}


void test_combinations() {
    
    vector<string> result = printCombinations("234");
    
    for(auto s : result){
        cout << s << " ";
    }
    cout << "Count: " << result.size() << endl;

}