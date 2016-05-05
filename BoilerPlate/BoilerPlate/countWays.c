//
//  countWays.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "countWays.h"


static int countWays(uint8_t n){
    
    uint8_t numWays[n+1];
    
    numWays[0] = 0;
    numWays[1] = 1;
    numWays[2] = 2;
    numWays[3] = 4;
    
    for(size_t i=4; i<=n; i++){
        numWays[i] = numWays[i-1] + numWays[i-2] + numWays[i-3];
    }
    
    return numWays[n];
    
}

static int countWaysRecursiveHelper(int8_t n, uint8_t numWays[]){
    
    if(numWays[n]>0)
        return numWays[n];
    
    numWays[n] = countWaysRecursiveHelper(n-1, numWays) +
                    countWaysRecursiveHelper(n-2, numWays) +
                    countWaysRecursiveHelper(n-3, numWays);

    return numWays[n];

}

static int countWaysRecursive(int8_t n){
    unsigned char numWays[n+1];
    
    // init numWays cause it cannot be statically 0ed
    for(int i=0; i<=n; i++)
        numWays[i] = 0;
    
    numWays[1] = 1;
    numWays[2] = 2;
    numWays[3] = 4;
    
    return countWaysRecursiveHelper(n, numWays);
}


void test_climb_stairs(int8_t stairs) {
    
    int8_t n = stairs;
    
    printf("CountWays: Number of ways you can climb %d steps "
           "1-2-3 at at time is %d\n", n, countWays(n));

    printf("CountWaysRecursive: Number of ways you can climb %d steps "
           "1-2-3 at at time is %d\n", n, countWaysRecursive(n));

}