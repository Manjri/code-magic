#include <stdio.h>

void foo(){
    static int x = 1;
    printf("%d\n", ++x);
}

int main(){
    foo();
    foo();
    return 0;
}
