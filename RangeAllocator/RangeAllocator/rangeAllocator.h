#ifndef hwte__range_allocator__hh__
#define hwte__range_allocator__hh__


#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

typedef void *ralloc_t;

typedef enum
{
	ALLOCATE_ANY,
	ALLOCATE_EXACT,
	ALLOCATE_ABOVE,
	ALLOCATE_BELOW,
} allocation_flags;

typedef uintptr_t vaddr_t;

#define GET_ALIGNED(addr, align) \
    ((addr+align-1) & ~(align-1))

class RangeAllocator
{
public:
    RangeAllocator(vaddr_t base, size_t length, size_t granularity);
    
    ~RangeAllocator();
    

    vaddr_t allocate_range(size_t length, allocation_flags flags,
                            vaddr_t optional_hint);
    
    void free_range(vaddr_t base, size_t length);
    
    void printFreeList();
    
private:
    vaddr_t baseAddr;
    size_t  granularity;
    size_t  free_addr;
    size_t  limit;
    
    typedef struct freeBlock{
        size_t size;
        freeBlock *next;
    }freeBlock;
    
    freeBlock* freeList;
    
    vaddr_t _allocateAny(size_t length);
    
    vaddr_t _allocateExact(size_t length, vaddr_t optional_hint);
    
    vaddr_t _allocateAbove(size_t length,vaddr_t optional_hint);
    
    vaddr_t _allocateBelow(size_t length, vaddr_t optional_hint);
};

#endif
