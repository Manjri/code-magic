//
//  main.cpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//
#include <stdio.h>

int countWays(unsigned int n){
    
    unsigned int numWays[n+1];
    
    numWays[0] = 0;
    numWays[1] = 1;
    numWays[2] = 2;
    numWays[3] = 4;
    
    for(size_t i=4; i<=n; i++){
        numWays[i] = numWays[i-1] + numWays[i-2] + numWays[i-3];
    }
    
    return numWays[n];
    
}


int main(int argc, const char * argv[]) {

    unsigned int n = 7;
    
    printf("Number of ways you can climb %d steps "
           "1-2-3 at at time is %d\n", n, countWays(n));
    return 0;
}