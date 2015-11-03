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
using namespace std;


bool base64_scheme1::check_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

string base64_scheme1::encode(string source){
    
    size_t len = source.length();
    const unsigned char *str = reinterpret_cast<const unsigned char*>(source.c_str());
    string res;
    string mapping = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    
    wchar_t vec_4[4];      // 4 groups of 6 bits each
    wchar_t vec_3[3];      // 3 groups of 8 bits each
    
    int i = 0;
    
    while(len--){
        vec_3[i++] = *(str++);
        
        // 24 bits accumulated!
        if(i==3){
            vec_4[0] = (vec_3[0] & 0xfc) >> 2;
            vec_4[1] = ((vec_3[0] & 0x03) << 4) + ((vec_3[1] & 0xf0) >> 4);
            vec_4[2] = ((vec_3[1] & 0x0f) << 2) + ((vec_3[2] & 0xc0) >> 6);
            vec_4[3] = vec_3[2] & 0x3f;
            
            // string
            for(i=0; i<4; i++)
                res += mapping[vec_4[i]];
            
            i = 0;
        }
    }
    
    // padding
    
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
    wchar_t vec_4[4];     // 4 groups of 6 bits each
    wchar_t vec_3[3];     // 3 groups of 8 bits each
    
    
    while (len-- && ( source[pos] != '=') && check_base64(source[pos])) {
        vec_4[i++] = source[pos];
        pos++;
        
        // 24 bits accumulated!
        if (i ==4) {
            for (i = 0; i <4; i++)
                vec_4[i] = mapping.find(vec_4[i]);
            
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
