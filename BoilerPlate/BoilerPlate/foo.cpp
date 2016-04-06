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
