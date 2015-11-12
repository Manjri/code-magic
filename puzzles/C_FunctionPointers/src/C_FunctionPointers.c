/*
 ============================================================================
 Name        : C_FunctionPointers.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef int (*callback_fn)(void*);

typedef struct callback_s
{	void *user_data;
	callback_fn func_callback;
}callback_t;

int foo(void* data)
{
	*((int*)data) = 1;
	return *((int*)data);
}

void init(callback_t* arg)
{
	int* ptr = (int*)malloc(sizeof(int));
	arg->user_data = (void*)ptr;
    //arg->func_callback = &foo;
    arg->func_callback = foo;
}


int main(void) {
	callback_t* myCallBack = (callback_t*)malloc(sizeof(callback_t));
	init(myCallBack);
	printf("Value is: %d", myCallBack->func_callback(myCallBack->user_data));
	return EXIT_SUCCESS;
}
