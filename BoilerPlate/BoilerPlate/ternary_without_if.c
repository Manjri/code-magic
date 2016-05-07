//
//  ternary_without_if.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/6/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "ternary_without_if.h"

void func(){
    uint8_t a,b,c;
    
    a = -2;
    b = 2;
    c = 3;
    
    
    uint8_t y = (!a)*c + (!!a)*b;
    
    printf("Result = %02x\n",y);
}