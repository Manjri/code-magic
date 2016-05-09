#include <stdio.h>
#include <stdlib.h>


void* alignedMalloc(size_t bytes, size_t alignment){

	void *p1;
	void **p2;	//aligned block
	int offset = alignment -1 + sizeof(void*);
	p1 = malloc(bytes + offset);
	if(p1==NULL)
		return;
	p2 = (void**)(((size_t)p1+offset) & ~(alignment-1));
	p2[-1] = p1;
	return p2;
}

void alignedFree(void *ptr){
	free(((void**)ptr)[-1]);
}

int main(){

	void *p1 = alignedMalloc(100, 16);
	printf("Aligned Malloc gave us: %p\n", (size_t*)p1);
	alignedFree(p1);
	return 0;
}
