//
//  reversals.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/7/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "reversals.h"

/*
 i/p: 87654321
 o/p" 12345678
 */
uint32_t reverseWord_32(uint32_t x){
    
    /*
     8765 4321
     4321 8765
     2143 6587
     1234 5678
     */
    x = ((x & 0x0000FFFF)  << 16)  |  ((x & 0xFFFF0000) >> 16);
    x = ((x & 0x00FF00FF)  << 8)   |  ((x & 0xFF00FF00) >> 8);
    x = ((x & 0x0F0F0F0F)  << 4)   |  ((x & 0xF0F0F0F0) >> 4);
    x = ((x & 0x33333333)  << 2)   |  ((x & 0xCCCCCCCC) >> 2);
    x = ((x & 0x55555555)  << 1)   |  ((x & 0xAAAAAAAA) >> 1);
    
    return x;
}

// x is n bytes long
uint32_t reverseWord_32_loop(uint32_t x){
    
    int count = CHAR_BIT * 4 - 1;
    uint32_t result = x;
    
    // loop should run 31 times
    // we've already taken care of the LSB
    while(count>0){
        
        x      = x      >> 1;
        result = result << 1;
        
        if(x&1)
            result |= 1;
        
        count--;
    }
    return result;
}



void strReverse(char *str){
    
    char *end = str;
    
    while(end && *end){
        end++;
    }
        
    // end is at NULL terminating character
    // move it back by 1
    end--;
    
    // now start swapping!
    while(str < end){
        char temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}


void test_str_reversal(){
    char str[] = "Hello World!";
    printf("Before: %s\n",str);
    strReverse(str);
    printf("After: %s\n",str);
}


void test(){
    
    uint32_t word = 0x87654321;
    printf("Word: %08x Reversed: %08x\n", word, reverseWord_32(word));
    printf("Word: %08x Reversed: %08x\n", word, reverseWord_32_loop(word));
}