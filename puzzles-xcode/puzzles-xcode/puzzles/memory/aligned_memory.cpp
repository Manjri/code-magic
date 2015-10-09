#include <iostream>

void* aligned_malloc(size_t reqd_bytes, size_t alignment);
void aligned_free(void* p);


void* aligned_malloc(size_t reqd_bytes, size_t alignment)
{
    void* p1;   // original block of mem
    void** p2;   // aligned block of mem

    int offset = (alignment - 1) + sizeof(void*);

    if((p1 = (void*)malloc(offset + reqd_bytes)) == NULL) 
        return NULL;

    p2 = (void**)(((size_t)p1 + offset) & ~(alignment-1));

    p2[-1] = p1;

    return p2;
}


void aligned_free(void *p2)
{
    void* p1 = ((void**)p2)[-1];
    free(p1);
}


int main()
{
    int* a;

    a = (int*)aligned_malloc(100, 16);
    memset(a, 0, 100);
    //
    aligned_free(a);
    return 0;
}