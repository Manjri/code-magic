#include <stdio.h>
#include <stdlib.h>

void print_stuff(int i){
	
	// This is will fail cause of stackoverflow
	//print_stuff(i); 
	printf("\n%d",i);

}

int main(){
	
	int* p;

	while(1){
		p = (int*) malloc(1024*1024);
		print_stuff(1);
	}

	return 0;
}
