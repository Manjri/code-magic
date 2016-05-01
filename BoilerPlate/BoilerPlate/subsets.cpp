//
//  subsets.cpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/30/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "subsets.hpp"
using namespace std;

static void findSubsets(vector<vector<char>>& soln,
                 vector<char>& res,
                 size_t low,
                 size_t high,
                 char *str
                 )
{
    if(low!=0)
        soln.push_back(res);
    
    for(size_t i=low; i<=high; i++){
        res.push_back(str[i]);
        findSubsets(soln, res, i+1, high, str);
        res.pop_back();
    }
}

void printAllSubsets(char *str)
{
    size_t len = strlen(str);
    vector<char> result;
    vector<vector<char>> soln;
    findSubsets(soln, result, 0,len-1,str);
    
    cout << "Start of Subsets" << endl;
    for(auto v : soln){
        for( auto r : v){
            cout << r;
        }
        cout << " ";
    }
    cout << "\nEnd of Subsets" << endl;
}

void testPrintAllSubsets(){
    char str[] = "abc";
    printAllSubsets(str);
}
