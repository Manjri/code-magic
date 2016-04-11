//
//  tests.cpp
//  RangeAllocator
//
//  Created by Nikhil Jagdale on 4/10/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "tests.hpp"

static bool testAllocatePositive(RangeAllocator& ra){
    bool flag = true;
    vaddr_t blocks[5];
    
    std::cout << "Allocate ranges\n";
    
    for(int i=0; i<=4 && flag; i++){
        vaddr_t ptr = ra.allocate_range(255, ALLOCATE_ANY, (vaddr_t)0);
        flag = ((i<4) ? (int)ptr>0 : (int)ptr == -1);
        
        if((int)ptr)
            blocks[i]=ptr;
        
    }
    //ra.printFreeList();
    std::cout << "Free ranges\n";
    
    for(int i=0; i<4; i++){
        if((int)blocks[i] != -1)
            ra.free_range(blocks[i], 255);
    }
    
    return flag;
}

static bool testAllocateNegative(RangeAllocator& ra){
    bool flag = true;
    for(int i=0; i<=4 && flag; i++){
        vaddr_t ptr = ra.allocate_range(257, ALLOCATE_ANY, (vaddr_t)0);
        flag = ((i<3) ? (int)ptr>0 : (int)ptr == -1);
        ra.printFreeList();
    }
    return flag;
}

static size_t getBlock(size_t length, size_t granularity){
    
    size_t result = length;
    
    if(length%granularity){
        size_t factor = length/granularity + 1;
        result = factor*granularity;
    }
    
    return result;
}

static void testGranularity(){
    
    std::cout << "\nGranularity Test for size 4:" << std::endl;
    for(int i=1; i<20; i++)
        std::cout << i << "-" << getBlock(i, 4) << " " ;
    std::cout << "\nGranularity Test Complete" << std::endl;
}


void runTests(RangeAllocator& ra){

    std::cout << "\n------- TestAllocate-Positive -------" << std::endl;
    testAllocatePositive(ra) ? std::cout << "Test Allocate Positive Passed" :
    std::cout << "Test Allocate Failed";
    std::cout << "\n--------------------------------------" << std::endl;
#if 0
    testAllocateNegative(ra) ? std::cout << "Test Allocate Negative Passed" :
    std::cout << "Test Allocate Negative Failed";
#endif
    //testGranularity();
    std::cout << std::endl;
}