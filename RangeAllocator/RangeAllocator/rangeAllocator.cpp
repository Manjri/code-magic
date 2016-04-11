//
//  rangeAllocator.cpp
//  RangeAllocator
//
//  Created by Nikhil Jagdale on 4/9/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "rangeAllocator.h"
#define __DEBUG__RA

RangeAllocator::RangeAllocator(vaddr_t base, size_t length, size_t granularity)
{
    if(base>0 && length>sizeof(freeBlock)){
        baseAddr = base;
        limit = baseAddr + length;
        this->granularity = granularity;
        free_addr = base;
        
        // Initialize the free list - initially complete range!
        freeList = (struct freeBlock*)base;
        freeList->size = length;
        freeList->next = nullptr;
        
#ifdef __DEBUG__RA
        //std::cout << "RangeAllocator::Constructor" << std::endl;
        printf("Range Start: %lx  Range End: %lx\n", baseAddr, limit);
#endif
    }else{
        assert(0);
    }
}

static size_t getBlockSize(size_t length, size_t granularity){
    
    size_t result = length;
    
    if(length%granularity){
        size_t factor = length/granularity + 1;
        result = factor*granularity;
    }
    
    return result;
}

void RangeAllocator::printFreeList(){
    freeBlock *f = freeList;
    vaddr_t addr;
    std::cout << "\n------- Free-List -------" << std::endl;
    while (f) {
        addr = (vaddr_t)f;
        printf("Addr:%lx Size:%lu\n", addr, f->size);
        f = f->next;
    }
    std::cout << "--------------------------" << std::endl;
}

vaddr_t RangeAllocator::allocate_range(size_t length,
                               allocation_flags flags, vaddr_t optional_hint)
{
    vaddr_t ptr;
    size_t block_length = getBlockSize(length, this->granularity);
    freeBlock *f = freeList;
    freeBlock *prev = nullptr;
    
    while(f){
        // First Fit - find the right free block
        if(length>f->size){
            prev = f;
            f = f->next;
            continue;
        }
        // remaining space can be converted into a new free block
        freeBlock* newBlock = (freeBlock*)(reinterpret_cast<vaddr_t>(f) + block_length);
        newBlock->size = (f->size - block_length);
        newBlock->next = f->next;
        
        if(prev==nullptr){  // first block used!
            freeList = newBlock;
        }else{
            prev->next = newBlock;
        }
        // new free block is the start of the allocation
        ptr = (vaddr_t)f;
#ifdef __DEBUG__RA
        printf("Alloc:\tPtr:%lx\tSize:%lu\n", ptr, block_length);
#endif
        return ptr;
    }
    
    return (vaddr_t)-1;
    
#ifdef NAIVE
    if((free_addr + block_length)>limit)
        ptr = (vaddr_t)-1;
    else{
        ptr = free_addr;    //GET_ALIGNED(free_addr, alignment);
        free_addr += block_length;
    }
    return ptr;
#endif
}

void RangeAllocator::free_range(vaddr_t base, size_t length){
    
    // find the free block that is immediately higher than this block
    freeBlock* fb = freeList;
    freeBlock* prev = nullptr;
    size_t blockLength = getBlockSize(length, this->granularity);
    
    while(fb){
        if((vaddr_t)fb >= (base+blockLength))
            break;
        prev = fb;
        fb = fb->next;
    }
    
    freeBlock* newBlock = (freeBlock*)base;
    newBlock->size = blockLength;
    
    if(prev == nullptr){
        newBlock->next = fb;
        freeList = newBlock;
        // TODO coalesce new block and next if
        // (newBlock+newBlock->length) == base
        
    }else{
        newBlock->next = prev->next;
        prev->next = newBlock;
        // TODO coalesce newBlock and next if
        // fb!=null && (newBlock+newBlock->length) == fb
    }
#ifdef __DEBUG__RA
    printf("Dealloc:\tPtr:%lx\tSize:%lu\n", (vaddr_t)newBlock, newBlock->size);
#endif
}

RangeAllocator::~RangeAllocator()
{
#ifdef __DEBUG__RA
    //std::cout << "RangeAllocator::Destructor" << std::endl;
#endif
    free((void*)baseAddr);
}
