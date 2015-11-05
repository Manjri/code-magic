//
//  base_64_scheme1.cpp
//  puzzles-xcode
//
//  Created by Nikhil Jagdale on 11/1/15.
//  Copyright © 2015 Nikhil Jagdale. All rights reserved.
//

#include "base64_scheme1.h"
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


bool base64_scheme1::check_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

string base64_scheme1::encode(string source){
    
    size_t len = source.length();
    
    // length checks not done
    // return bool and take in an extra argument as string &result
    // ==> bool base_64_scheme1::encode(string source, string &result)
    // if len==0 return false
    // if len<24 return fasle
    
    const unsigned char *str = reinterpret_cast<const unsigned char*>(source.c_str());
    string res;
    string mapping = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
    vector<unsigned char> vec_4(4);      // 4 groups of 6 bits each
    vector<unsigned char> vec_3(3);      // 3 groups of 8 bits each
    
    int i = 0;
    
    while(len--){
        vec_3[i++] = *(str++);
        
        // 24 bits accumulated!
        // going left to right extract 6 bits at a time
        if(i==3){
            vec_4[0] = (vec_3[0] & 0xfc) >> 2;  // upper 6 bits of byte0
            vec_4[1] = ((vec_3[0] & 0x03) << 4) + ((vec_3[1] & 0xf0) >> 4); // lower 2 of byte0 + upper 4 of byte1
            vec_4[2] = ((vec_3[1] & 0x0f) << 2) + ((vec_3[2] & 0xc0) >> 6); // lower 4 of byte1 + upper 2 of byte2
            vec_4[3] = vec_3[2] & 0x3f; // lower 6 of byte3
            
            // string
            for(i=0; i<4; i++)
                res += mapping[vec_4[i]];       // look into mapping using the six bits as index
            
            i = 0;
        }
    }
    
    // padding
    // we have total bytes that are not multiples of 3 bytes
    // in that case add NULL Characters
    if(i){
        for(int j=i; j<3; j++)
            vec_3[j] = '\0';
        
        vec_4[0] = (vec_3[0] & 0xfc) >> 2;
        vec_4[1] = ((vec_3[0] & 0x03) << 4) + ((vec_3[1] & 0xf0) >> 4);
        vec_4[2] = (vec_3[1] & 0x0f << 2) + ((vec_3[2] & 0xc0) >> 6);
        vec_4[3] = vec_3[2] & 0x3f;
        
        // string
        for(int j=0; (j<i+1); j++)
            res += mapping[vec_4[j]];
        
        // Add 1 or more '=' to make base64 unit
        while((i++ < 3))
            res += '=';
    }
    
    return res;
}

string base64_scheme1::decode(string const &source) {
    size_t len = source.length();
    string res;
    int i = 0;
    int j = 0;
    int pos = 0;
    string mapping = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    vector<unsigned char> vec_4(4);     // 4 groups of 6 bits each
    vector<unsigned char> vec_3(3);     // 3 groups of 8 bits each
    
    
    while (len-- && ( source[pos] != '=') && check_base64(source[pos])) {
        vec_4[i++] = source[pos];
        pos++;
        
        // 24 bits accumulated!
        if (i ==4) {
            for (i = 0; i <4; i++)
                vec_4[i] = mapping.find(vec_4[i]);  // we're getting the index
            
            // coaleasce 8 bits together
            vec_3[0] = (vec_4[0] << 2) + ((vec_4[1] & 0x30) >> 4);
            vec_3[1] = ((vec_4[1] & 0xf) << 4) + ((vec_4[2] & 0x3c) >> 2);
            vec_3[2] = ((vec_4[2] & 0x3) << 6) + vec_4[3];
            
            // ascii string
            for (i = 0; (i < 3); i++)
                res += vec_3[i];
            i = 0;
        }
    }
    
    // padding
    
    if (i) {
        for (j = i; j <4; j++)
            vec_4[j] = 0;
        
        for (j = 0; j <4; j++)
            vec_4[j] = mapping.find(vec_4[j]);
        
        // coaleasce 8 bits together
        vec_3[0] = (vec_4[0] << 2) + ((vec_4[1] & 0x30) >> 4);
        vec_3[1] = ((vec_4[1] & 0xf) << 4) + ((vec_4[2] & 0x3c) >> 2);
        vec_3[2] = ((vec_4[2] & 0x3) << 6) + vec_4[3];
        
        // ascii string
        for (j = 0; (j < i - 1); j++)
            res += vec_3[j];
    }
    
    return res;
}
