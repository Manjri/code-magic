This is a simple RangeAllocator library that provides APIs for client code
to effectively manage memory by way of:
    1. Making just one system call at the beginning (malloc) to get a huge
    chunk of memory

    2. Creating a RangeAllocator object that initalizes various control
    structures that provide services to the client

    3. Calling allocate_range() and free_range() to get and destroy various ranges

    4. Call the destructor of the object (or make the call implicitly due to
    scope exit) to free up the total memory malloced intially in one shot

The last point is critical as it will gurantee that the memory is free
without worrying about client forgetting to make free_range() calls in between and
potentially avoid memory leaks.


Basic Implementation Idea:
--------------------------
The idea used in this implemenation is motivated by the requirements of
simplicity and efficiency. Not surprisingly, speed is the main attribute.

Allocations are made as chunks of memory blocks based on the size(and graunlarity)
as well as the allocation flags(and hints) The RangeAllocator maintains a list of
'free blocks' which is it dynamically updates after every call to allocate_range()
and free_range(). The 'free blocks' list is NOT a list in the sense of a LinkedList
data structure and therefore doesnt occupy additional memory. A typical free block
looks like the following:

Free blocks:

 ----
|size|
|next| ---
|    |    |
|    |    |
 ----     |
       /  |
 ---- |___|
|size||
|next| \
|    |
|    |
 ----


The information about the next free block is imprinted in the block itself.
The first block pointer (address) is maintained(and updated) in a object variable
that is used while 'walking' (dereferring the address itslef) the free blocks.

To be efficient, the memory blocks are coalesced whenever possible so that
the RangeAllocator can always serve the
largest range requirement that the client can ask. Without coalescing we would
be stuck with fragmentation and the allocator will soon grind to a halt.
This implmentation doesnt provide aligned address as it is not an explicit
requrement, however this can be easily supported with a 'header' block in every
allocated memory block.


Description of the files:
-------------------------
The APIs are described in the "rangeAllocator.h" file. Client needs to just
include this in his code that uses these APIs.
(example: main.cpp)

The API implementation is in the "rangeAllocator.cpp" file. In addition to the
standard allocate_range(), free_range() APIs, a printFreeList() API is provided
so that the client code can print the free blocks that exist in the given range
of memory. This is useful for example while debugging as well as profiling the
code to check the allocation usage.

To test this library, "tests.hpp"/"tests.cpp" are provided. Client code can test the
various APIs by executing the given test sequences in runTests() function.
The requirement for the client code is to create a RangeAllocator object and
pass that as argument. "tests.cpp" provides example of basic positive and negative
tests that should be called on the APIs. After each test, I free up the ranges that
were allocated in that test sequence - a sanity check/assertion is that the complete
block of memory should be printed in the Free-List, no holes (or blocks of seperate)
free blocks should exist. This tests the coalescing of the free_range() function.