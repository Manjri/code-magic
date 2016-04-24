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

vaddr_t RangeAllocator::_allocateAny(size_t length)
{
    vaddr_t ptr;
    size_t block_length = getBlockSize(length, this->granularity);
    freeBlock *f = freeList;
    freeBlock *prev = nullptr;
    
    while(f){
        // First Fit - find the right free block
        if(block_length>f->size){
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
}

vaddr_t RangeAllocator::_allocateAbove(size_t length, vaddr_t targetAddr)
{
    vaddr_t ptr;
    size_t block_length = getBlockSize(length, this->granularity);
    freeBlock *f = freeList;
    freeBlock *prev = nullptr;
    
    while(f){
        
        // Start address of free block ahead of targetAddr!!
        if((vaddr_t)f<targetAddr &&
           (targetAddr-(vaddr_t)f +1 + block_length)<=f->size){

            // 2 blocks will have to be made
            // save off the current free block info
            size_t freeBlockSize = f->size;
            freeBlock *freeBlockNext = f->next;
            size_t delta = (targetAddr - (reinterpret_cast<vaddr_t>(f)) + 1);
            
            freeBlock *newBlock1 = f;
            newBlock1->size = delta;
        
            f = (freeBlock*)(vaddr_t(reinterpret_cast<vaddr_t>(f) + delta));
            // remaining space can be converted into a new free block
            freeBlock* newBlock2 = (freeBlock*)(reinterpret_cast<vaddr_t>(f) + block_length);
            newBlock2->size = (freeBlockSize - block_length - newBlock1->size);
            newBlock2->next = freeBlockNext;
            
            newBlock1->next = newBlock2;
            
            if(prev==nullptr){  // first block used!
                freeList = newBlock1;
            }else{
                prev->next = newBlock1;
            }
            // new free block is the start of the allocation
            ptr = (vaddr_t)f;
#ifdef __DEBUG__RA
            printf("Alloc:\tPtr:%lx\tSize:%lu\n", ptr, block_length);
            printf("NewBlock1:%lx\tSize:%lu\n", (vaddr_t)newBlock1, newBlock1->size);
            printf("NewBlock2:%lx\tSize:%lu\n", (vaddr_t)newBlock2, newBlock2->size);
#endif
            return ptr;
        }else{
            prev = f;
            f = f->next;
            continue;
        }
    }
    return (vaddr_t)-1;
}

vaddr_t RangeAllocator::_allocateBelow(size_t length, vaddr_t targetAddr)
{
    vaddr_t ptr;
    size_t block_length = getBlockSize(length, this->granularity);
    freeBlock *f = freeList;
    freeBlock *prev = nullptr;
    
    while(f){
        
        // Start & end address of free block below targetAddr!!
        if((vaddr_t)f<targetAddr && block_length<=f->size &&
           ((vaddr_t)f + block_length)<targetAddr){
            
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
            printf("NewBlock:%lx\tSize:%lu\n", (vaddr_t)newBlock,newBlock->size);
#endif
            return ptr;
        }else{
            prev = f;
            f = f->next;
            continue;
        }
    }
    return (vaddr_t)-1;
}

vaddr_t RangeAllocator::_allocateExact(size_t length, vaddr_t targetAddr)
{
    vaddr_t ptr;
    size_t block_length = getBlockSize(length, this->granularity);
    freeBlock *f = freeList;
    freeBlock *prev = nullptr;
    
    while(f){
        
        // Start address of free block ahead/equal of targetAddr!!
        if((vaddr_t)f<=targetAddr &&
           (targetAddr-(vaddr_t)f +1 + block_length)<=f->size){
            
            // 2 blocks will have to be made
            // save off the current free block info
            size_t freeBlockSize = f->size;
            freeBlock *freeBlockNext = f->next;
            size_t delta = (targetAddr - (reinterpret_cast<vaddr_t>(f)) + 1);
            
            freeBlock *newBlock1 = f;
            newBlock1->size = delta-1;
            
            f = (freeBlock*)targetAddr;
            // remaining space can be converted into a new free block
            freeBlock* newBlock2 = (freeBlock*)(reinterpret_cast<vaddr_t>(f) + block_length);
            newBlock2->size = (freeBlockSize - block_length - newBlock1->size);
            newBlock2->next = freeBlockNext;
            
            newBlock1->next = newBlock2;
            
            if(prev==nullptr){  // first block used!
                freeList = newBlock1;
            }else{
                prev->next = newBlock1;
            }
            // new free block is the start of the allocation
            ptr = (vaddr_t)f;
#ifdef __DEBUG__RA
            printf("Alloc:\tPtr:%lx\tSize:%lu\n", ptr, block_length);
            printf("NewBlock1:%lx\tSize:%lu\n", (vaddr_t)newBlock1, newBlock1->size);
            printf("NewBlock2:%lx\tSize:%lu\n", (vaddr_t)newBlock2, newBlock2->size);
#endif
            return ptr;
        }else{
            prev = f;
            f = f->next;
            continue;
        }
    }
    return (vaddr_t)-1;
}

vaddr_t RangeAllocator::allocate_range(size_t length,
                                       allocation_flags flags, vaddr_t optional_hint){
    vaddr_t ptr;
    
    switch (flags) {
        case ALLOCATE_ANY:
            ptr = _allocateAny(length);
            break;
        case ALLOCATE_BELOW:
            ptr = _allocateBelow(length, optional_hint);
            break;
        case ALLOCATE_ABOVE:
            ptr = _allocateAbove(length, optional_hint);
            break;
        case ALLOCATE_EXACT:
            ptr = _allocateExact(length, optional_hint);
            break;
        default:
            break;
    }
    return ptr;
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
    vaddr_t blockEnd = (vaddr_t)newBlock+newBlock->size;
    
    if(prev == nullptr){
        prev = (freeBlock*)base;
        prev->size = blockLength;
        prev->next = fb;
        freeList = prev;
    }else if((vaddr_t)((vaddr_t)prev+prev->size)==(vaddr_t)(freeBlock*)base){
        prev->size += blockLength;
    }else{
        newBlock->next = prev->next;
        prev->next = newBlock;
        prev = newBlock;
    }
    if(fb && (vaddr_t)fb==blockEnd){
        prev->size += fb->size;
        prev->next = fb->next;
    }
#ifdef __DEBUG__RA
    printf("Dealloc:\tPtr:%lx\tSize:%lu\n", (vaddr_t)prev, prev->size);
#endif
}

#if 0
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
#endif


RangeAllocator::~RangeAllocator()
{
#ifdef __DEBUG__RA
    //std::cout << "RangeAllocator::Destructor" << std::endl;
#endif
    free((void*)baseAddr);
}
