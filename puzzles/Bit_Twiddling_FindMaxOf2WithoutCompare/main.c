//
//  main.cpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

uint32_t flip(uint32_t bit){
    return 1^bit;
}

uint32_t sign(uint32_t a){
    return flip((a>>31)&1);
}

// let k equal sign of a - b
// such that if (a - b)>=0 k = 1 else k = 0

void findMaxOf2(int32_t a, int32_t b){
    
    int32_t c = a - b;
    uint32_t sa = sign(a);  // if a>=0, then 1 else 0
    uint32_t sb = sign(b);  // if b>=0, then 1 else 0
    uint32_t sc = sign(c);  //  depends on whether a-b overflows!!
    
    // over-flow is possible when:
    // case 1: a > 0 and b < 0 -- overflow will result in a negative number - k=sign(a)
    // case 2: a < 0 and b > 0 -- overflow will resilt in a positive number - k=sign(a)
    // Both cases, a & b are opposite signs
    uint32_t use_sa = sa ^ sb;
    
    // if a & b have same sign, then k=sign(a-b)
    uint32_t use_sc = flip(use_sa);
    
    uint32_t k = use_sa*sa + use_sc*sc;
    uint32_t q = flip(k);
    uint32_t ans = k*a + q*b;
    
    printf("Higher of (%d,%d) is %d\n",a, b,ans);
    
}


int main(int argc, const char * argv[]) {
    
    int32_t a = -INT_MIN+2;
    int32_t b = 3;
    findMaxOf2(a, b);
    return 0;
}