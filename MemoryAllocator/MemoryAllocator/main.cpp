#include "StackAllocator.h"
#include "LinearAllocator.h"
#include "FreeListAllocator.h"
#include "PoolAllocator.h"

#include <stdlib.h>
#include <stdio.h>

#include <vector>

#include <Windows.h>

#define LINEAR_ALLOC 1
#define STACK_ALLOC 1
#define FREELIST_ALLOC 1
#define POOL_ALLOC 1

#define MAX_NUM_ALLOCS 100000

#define NUM_16B_ALLOCS 10000
#define NUM_256B_ALLOCS 1000
#define NUM_2MB_ALLOCS 50

#define MB2INBYTES  2097152 //2mb

#define MEM_SIZE 1048576000 //1GB

int main()
{
	void* pMem = malloc(MEM_SIZE);

	u64 ticksPerSecond;
	u64 start;
	u64 end;

	double elapsed;

	void* allocs[MAX_NUM_ALLOCS];

	QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);

	#if LINEAR_ALLOC
	/////////////////////////////////////////////////////////////////
	//Linear
	/////////////////////////////////////////////////////////////////

	LinearAllocator* pLinearAlloc = new LinearAllocator(MEM_SIZE, pMem);

	printf("----------------\n");
	printf("Malloc vs Linear\n");
	printf("----------------\n");

	QueryPerformanceCounter((LARGE_INTEGER*)&start);

	int k = 0;

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[k+i] = malloc(16);

	k += NUM_16B_ALLOCS;

	for(int i = 0; i < NUM_256B_ALLOCS; i++)
		allocs[k+i] = malloc(256);

	k += NUM_256B_ALLOCS;

	for(int i = 0; i < NUM_2MB_ALLOCS; i++)
		allocs[k+i] = malloc(MB2INBYTES);

	k += NUM_2MB_ALLOCS;

	for(int i = 0; i < k; i++)
		free(allocs[i]);

	QueryPerformanceCounter((LARGE_INTEGER*)&end);

	elapsed = (end - start)/(double)ticksPerSecond;

	printf("Malloc: %f\n", elapsed);

	QueryPerformanceCounter((LARGE_INTEGER*)&start);

	k = 0;

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[k+i] = pLinearAlloc->allocate(16, 8);

	k += NUM_16B_ALLOCS;

	for(int i = 0; i < NUM_256B_ALLOCS; i++)
		allocs[k+i] = pLinearAlloc->allocate(256, 8);

	k += NUM_256B_ALLOCS;

	for(int i = 0; i < NUM_2MB_ALLOCS; i++)
		allocs[k+i] = pLinearAlloc->allocate(MB2INBYTES, 8);

	k += NUM_2MB_ALLOCS;

	pLinearAlloc->clear();

	QueryPerformanceCounter((LARGE_INTEGER*)&end);

	elapsed = (end - start)/(double)ticksPerSecond;

	printf("Linear: %f\n\n", elapsed);

	pLinearAlloc->clear();

	delete pLinearAlloc;

	#endif

	#if STACK_ALLOC

	/////////////////////////////////////////////////////////////////
	//Stack
	/////////////////////////////////////////////////////////////////

	StackAllocator* pStackAlloc   = new StackAllocator(MEM_SIZE, pMem);

	printf("----------------\n");
	printf("Malloc vs Stack\n");
	printf("----------------\n");

	QueryPerformanceCounter((LARGE_INTEGER*)&start);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[i] = malloc(16);

	for(int i = NUM_16B_ALLOCS-1; i >= 0; i--)
		free(allocs[i]);

	for(int i = 0; i < NUM_256B_ALLOCS; i++)
		allocs[i] = malloc(256);

	for(int i = NUM_256B_ALLOCS-1; i >= 0; i--)
		free(allocs[i]);

	for(int i = 0; i < NUM_2MB_ALLOCS; i++)
		allocs[i] = malloc(MB2INBYTES);

	for(int i = NUM_2MB_ALLOCS-1; i >= 0; i--)
		free(allocs[i]);

	QueryPerformanceCounter((LARGE_INTEGER*)&end);

	elapsed = (end - start)/(double)ticksPerSecond;

	printf("Malloc: %f\n", elapsed);

	QueryPerformanceCounter((LARGE_INTEGER*)&start);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[i] = pStackAlloc->allocate(16, 8);

	for(int i = NUM_16B_ALLOCS-1; i >= 0; i--)
		pStackAlloc->deallocate(allocs[i]);

	for(int i = 0; i < NUM_256B_ALLOCS; i++)
		allocs[i] = pStackAlloc->allocate(256, 8);

	for(int i = NUM_256B_ALLOCS-1; i >= 0; i--)
		pStackAlloc->deallocate(allocs[i]);

	for(int i = 0; i < NUM_2MB_ALLOCS; i++)
		allocs[i] = pStackAlloc->allocate(MB2INBYTES, 8);;

	for(int i = NUM_2MB_ALLOCS-1; i >= 0; i--)
		pStackAlloc->deallocate(allocs[i]);

	QueryPerformanceCounter((LARGE_INTEGER*)&end);

	elapsed = (end - start)/(double)ticksPerSecond;

	printf("Stack: %f\n\n", elapsed);

	delete pStackAlloc;

	#endif

	#if FREELIST_ALLOC

	/////////////////////////////////////////////////////////////////
	//FreeList
	/////////////////////////////////////////////////////////////////

	FreeListAllocator* pFreeListAlloc = new FreeListAllocator(MEM_SIZE, pMem);

	printf("------------------\n");
	printf("Malloc vs FreeList\n");
	printf("------------------\n");

	QueryPerformanceCounter((LARGE_INTEGER*)&start);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[i] = malloc(16);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		free(allocs[i]);

	for(int i = 0; i < NUM_256B_ALLOCS; i++)
		allocs[i] = malloc(256);

	for(int i = 0; i < NUM_256B_ALLOCS; i++)
		free(allocs[i]);

	for(int i = 0; i < NUM_2MB_ALLOCS; i++)
		allocs[i] = malloc(MB2INBYTES);

	for(int i = 0; i < NUM_2MB_ALLOCS; i++)
		free(allocs[i]);

	QueryPerformanceCounter((LARGE_INTEGER*)&end);

	elapsed = (end - start)/(double)ticksPerSecond;

	printf("Malloc: %f\n", elapsed);

	QueryPerformanceCounter((LARGE_INTEGER*)&start);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[i] = pFreeListAlloc->allocate(16, 8);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		pFreeListAlloc->deallocate(allocs[i]);

	for(int i = 0; i < NUM_256B_ALLOCS; i++)
		allocs[i] = pFreeListAlloc->allocate(256, 8);

	for(int i = 0; i < NUM_256B_ALLOCS; i++)
		pFreeListAlloc->deallocate(allocs[i]);

	for(int i = 0; i < NUM_2MB_ALLOCS; i++)
		allocs[i] = pFreeListAlloc->allocate(MB2INBYTES, 8);

	for(int i = 0; i < NUM_2MB_ALLOCS; i++)
		pFreeListAlloc->deallocate(allocs[i]);

	QueryPerformanceCounter((LARGE_INTEGER*)&end);

	elapsed = (end - start)/(double)ticksPerSecond;

	printf("FreeList: %f\n\n", elapsed);

	delete pFreeListAlloc;

	#endif

	#if POOL_ALLOC

	/////////////////////////////////////////////////////////////////
	//Pool
	/////////////////////////////////////////////////////////////////

	PoolAllocator* pPoolAlloc = new PoolAllocator(16, 8, MEM_SIZE, pMem);

	printf("------------------\n");
	printf("Malloc vs Pool\n");
	printf("------------------\n");

	QueryPerformanceCounter((LARGE_INTEGER*)&start);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[i] = malloc(16);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		free(allocs[i]);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[i] = malloc(16);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		free(allocs[i]);

	QueryPerformanceCounter((LARGE_INTEGER*)&end);

	elapsed = (end - start)/(double)ticksPerSecond;

	printf("Malloc: %f\n", elapsed);

	QueryPerformanceCounter((LARGE_INTEGER*)&start);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[i] = pPoolAlloc->allocate(16, 8);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		pPoolAlloc->deallocate(allocs[i]);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		allocs[i] = pPoolAlloc->allocate(16, 8);

	for(int i = 0; i < NUM_16B_ALLOCS; i++)
		pPoolAlloc->deallocate(allocs[i]);

	QueryPerformanceCounter((LARGE_INTEGER*)&end);

	elapsed = (end - start)/(double)ticksPerSecond;

	printf("Pool: %f\n\n", elapsed);

	delete pPoolAlloc;

	#endif

	free(pMem);

	///////////////////////////////////
	// TEST FREE LIST ALLOCATOR
	///////////////////////////////////

	char* bigbuf = (char*)malloc(10000);

	// remember our allocs
	std::vector<void*> _allocs;

	FreeListAllocator allocator(10000, bigbuf);

	// lots of iterations
	for(int i = 0; i < 1000; i++)
	{
		// allocate blocks till the allocator is full
		for(;;)
		{
			size_t allocSize = rand()%500+1;
			u8 alignment = rand()%2 == 0 ? 4 : 2;

			//printf("%d %d\n", (int) allocSize, alignment);

			void* alloc = allocator.allocate(allocSize, alignment);

			if (!alloc)
				break;

			_allocs.push_back(alloc);
		}

		if(i%2 == 0)
		{
			// randomly deallocate ~50% of blocks (forward)
			for(size_t j = 0; j < _allocs.size(); j++)
			{
				if ((rand() % 2) == 0 && _allocs[j] != nullptr)
				{
					allocator.deallocate(_allocs[j]);
					_allocs[j] = nullptr;
				}
			}
		} else
		{
			// randomly deallocate ~50% of blocks (backwards)
			for(int j = _allocs.size()-1; j >= 0; j--)
			{
				if ((rand() % 2) == 0 && _allocs[j] != nullptr)
				{
					allocator.deallocate(_allocs[j]);
					_allocs[j] = nullptr;
				}
			}
		}
	}

	for(size_t i = 0; i < _allocs.size(); i++)
	{
		if(_allocs[i] != nullptr)
		{
			allocator.deallocate(_allocs[i]);
			_allocs[i] = nullptr;
		}
	}

	printf("%d == %d\n", 0, (int) allocator.getUsedMemory());

	getchar();

	return 0;
}