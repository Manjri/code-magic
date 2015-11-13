#include <stdio.h>

#define VAL 1

typedef int(*fptr)(int);

typedef struct Data{
    int data;
    fptr foo;
}Data_t;

int sum(int a){
    return a+VAL;
}

int main(){
    Data_t d;
    d.data = 1;
    d.foo = sum;
    printf("%d\n",d.foo(d.data));
    return 0;
}

