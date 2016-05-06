//
//  findMaxUsingOperators.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "findMaxUsingOperators.hpp"

using namespace std;

int findBigger(int a, int b){
    int res1 = a*b;
    int res2 = a+b;
    
    return (res1>res2) ? res1 : res2;
}

int findMax(deque<int> &arr){
    
    int first = 0, second = 0, maxOf2 = 0;
    
    while(!arr.empty() && arr.size()>1){
        
        // take 2 out
        first = arr.front();
        arr.pop_front();
        maxOf2 = first;
        
        if(!arr.empty()){
            second = arr.front();
            arr.pop_front();
            maxOf2 = findBigger(first, second);
        }
        
        arr.push_back(maxOf2);
    }
    
    return maxOf2;
}

int test() {
    deque<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    cout << "Highest Val: " << findMax(arr) << endl;
    return 0;
}