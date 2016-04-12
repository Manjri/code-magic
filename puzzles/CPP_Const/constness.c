#include <stdio.h>

int main(){
	const int* p;
	//int const* p;
	int x = 30;	// initialize it
	int y = 50;	// initialize it
	int *const q = &y;
	p = &x;
	//printf("Before x:%d\n",*p);
	printf("Before x:%d\n",*q);
	// now modify x;
	//*p = 60;	// compiler error: assignment of read-only location ‘*p’
	*q = 100;
	//printf("After x:%d\n",*p);
	printf("After x:%d\n",*q);
	// now change what q points to
	//q = &x; // compiler error: assignment of read-only variable 'q'
	return 0;
}
