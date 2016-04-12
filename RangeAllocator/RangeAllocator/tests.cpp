#include "tests.hpp"
#define __TEST__ALLOCATE_P
#define __TEST__BELOW_P
#define __TEST_ABOVE_P
#define __TEST_EXACT_P

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

static bool testAllocateBelowP(RangeAllocator& ra){
    bool flag = true;
    vaddr_t blocks[2];
    vaddr_t ptr;
    
    std::cout << "Allocate ranges\n";
    
    for(int i=0; i<2 && flag; i++){
        if(i==0){
            ptr = ra.allocate_range(255, ALLOCATE_ANY, (vaddr_t)0);
        }else{
            ptr = ra.allocate_range(255, ALLOCATE_BELOW, (vaddr_t)(blocks[0]+513));
        }
        //printf("%lx\n", (int)ptr);
        flag = (int)ptr>=0;
        if((int)ptr)
            blocks[i]=ptr;
    }
    ra.free_range(blocks[0], 255);
    ra.free_range(blocks[1], 255);
    return flag;
}

static bool testAllocateBelowN(RangeAllocator& ra){
    bool flag = true;
    vaddr_t blocks[2];
    vaddr_t ptr;
    
    std::cout << "Allocate ranges\n";
    
    for(int i=0; i<2 && flag; i++){
        if(i==0){
            ptr = ra.allocate_range(255, ALLOCATE_ANY, (vaddr_t)0);
        }else{
            ptr = ra.allocate_range(255, ALLOCATE_BELOW, (vaddr_t)(blocks[0]+10));
        }
        //printf("%lx\n", (int)ptr);
        flag = (i==0)?(int)ptr>=0 : (int)ptr==-1;
        if((int)ptr)
            blocks[i]=ptr;
    }
    return flag;
}


static bool testAllocateAboveP(RangeAllocator& ra){
    bool flag = true;
    vaddr_t blocks[2];
    vaddr_t ptr;
    
    std::cout << "Allocate ranges\n";
    
    for(int i=0; i<2 && flag; i++){
        if(i==0){
            ptr = ra.allocate_range(255, ALLOCATE_ANY, (vaddr_t)0);
        }else{
            ptr = ra.allocate_range(255, ALLOCATE_ABOVE, (vaddr_t)(blocks[0]+300));
        }
        //printf("%lx\n", ptr);
        flag = (int)ptr>=0;
        if((int)ptr)
            blocks[i]=ptr;
    }
    ra.free_range(blocks[0], 255);
    ra.free_range(blocks[1], 255);
    return flag;
}

static bool testAllocateAboveN(RangeAllocator& ra){
    bool flag = true;
    vaddr_t blocks[2];
    vaddr_t ptr;
    
    std::cout << "Allocate ranges\n";
    
    for(int i=0; i<2 && flag; i++){
        if(i==0){
            ptr = ra.allocate_range(255, ALLOCATE_ANY, (vaddr_t)0);
        }else{
            ptr = ra.allocate_range(255, ALLOCATE_ABOVE, (vaddr_t)(blocks[0]-10));
        }
        //printf("%lx\n", (int)ptr);
        flag = (i==0)?(int)ptr>=0 : (int)ptr==-1;
        if((int)ptr)
            blocks[i]=ptr;
    }
    return flag;
}

static bool testAllocateExactP(RangeAllocator& ra){
    bool flag = true;
    vaddr_t blocks[2];
    vaddr_t ptr;
    
    std::cout << "Allocate ranges\n";
    
    for(int i=0; i<2 && flag; i++){
        if(i==0){
            ptr = ra.allocate_range(255, ALLOCATE_ANY, (vaddr_t)0);
        }else{
            ptr = ra.allocate_range(255, ALLOCATE_EXACT, (vaddr_t)(blocks[0]+256+1));
        }
        //printf("%lx\n", (int)ptr);
        flag = (int)ptr>=0;;
        if((int)ptr)
            blocks[i]=ptr;
    }
    ra.free_range(blocks[0], 255);
    ra.free_range(blocks[1], 255);
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

    std::cout << "\n******************** Tests Start! ********************" << std::endl;
#ifdef __TEST__ALLOCATE_P
    std::cout << "\n------- TestAllocate-Positive -------" << std::endl;
    testAllocatePositive(ra) ? std::cout << "Test Passed" : std::cout << "Test Failed";
    std::cout << "\n--------------------------------------" << std::endl;
#endif
#ifdef __TEST__BELOW_P
    std::cout << "\n------- TestAllocateBelow-Positive -------" << std::endl;
    testAllocateBelowP(ra)? std::cout << "Test Passed" : std::cout << "Test Failed";
    std::cout << "\n--------------------------------------" << std::endl;
#endif
#ifdef __TEST_BELOW_N
    std::cout << "\n------- TestAllocateBelow-Negative -------" << std::endl;
    testAllocateBelowN(ra)? std::cout << "Test Passed" : std::cout << "Test Failed";
    std::cout << "\n--------------------------------------" << std::
    endl;
#endif
#ifdef __TEST_ABOVE_P
    std::cout << "\n------- TestAllocateAbove-Positive -------" << std::endl;
    testAllocateAboveP(ra)? std::cout << "Test Passed" : std::cout << "Test Failed";
    std::cout << "\n--------------------------------------" << std::endl;
#endif
#ifdef __TEST_EXACT_P
    std::cout << "\n------- TestAllocateExact-Positive -------" << std::endl;
    testAllocateExactP(ra)? std::cout << "Test Passed" : std::cout << "Test Failed";
    std::cout << "\n--------------------------------------" << std::endl;
#endif
    
#if __TEST_ABOVE_N
    std::cout << "\n------- TestAllocateAbove-Negative -------" << std::endl;
    testAllocateAboveN(ra)? std::cout << "Test Passed" : std::cout << "Test Failed";
    std::cout << "\n--------------------------------------" << std::endl;

    testAllocateNegative(ra) ? std::cout << "Test Allocate Negative Passed" :
    std::cout << "Test Allocate Negative Failed";
#endif
    //testGranularity();
    std::cout << "\n******************** Tests Complete! ********************" << std::endl;
    std::cout << std::endl;
}