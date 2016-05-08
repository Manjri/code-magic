//
//  foo.cpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "foo.h"
#include <string>
#include <iostream>

void printNothing(void){
    
    std::cout << "Foo" << std::endl;
}

void strReverse(char *s){

    size_t len=0;
    size_t start = 0;
    char *temp = s;
    
    while(*temp){
        temp++;
        len++;
    }
    
    len--;
    
    while(start<len){
        char temp = s[start];
        s[start] = s[len];
        s[len] = temp;
        start++;
        len--;
    }
}


std::vector<int> findTriplets(std::vector<int> input, int sum){
    std::vector<int> result;
    
    for(int i=0; i<input.size()-1; i++){
        int low = i+1;
        long high = input.size()-1;
        while(low < high){
            int temp = input[i]+input[low]+input[high];
            if(temp < sum)
                low++;
            else if(temp > sum)
                high--;
            else{
                result.push_back(input[low]);
                result.push_back(input[i]);
                result.push_back(input[high]);
                break;
            }
        }
    }
    return result;
}

void testTriplets(){
    
    std::vector<int> v;
    v.push_back(12);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(6);
    v.push_back(9);
    
    std::vector<int> result = findTriplets(v, 24);
    
    if(result.size() == 0)
        std::cout << "No triplets found!" << std::endl;
    else{
        for(auto i : result)
            std::cout << i << " ";
    }
}









