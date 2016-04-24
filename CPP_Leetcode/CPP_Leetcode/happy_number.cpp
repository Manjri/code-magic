//
//  happy_number.cpp
//  CPP_Leetcode
//
//  Created by Nikhil Jagdale on 4/18/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "happy_number.hpp"


bool Solution::isHappy(int n){
        std::set<int> digits;
        std::set<int>::iterator it;
        std::pair<std::set<int>::iterator, bool> p;
        p.second = true;
        int temp, result;
        
        while(p.second){
            
            result = 0;
            while(n){
                temp = n%10;
                n = n/10;
                result += temp*temp;
            }
            
            if(result == 1)
                return true;
            else
                n = result;
            
            p = digits.insert(n);
        }
        return false;
}
