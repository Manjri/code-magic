#include <stdio.h>

int main(){
    int i = 1;
    int j = 2;

    // run till Cntrl+C is pressed
    while(1){
        printf("%d %s\n", i); // less args than # of format specifiers will                                
                              // cause a crash cause of printf will access 
                              // memory on the stack that it doesnt have access 
                              // rights to!


        // printf("%d\n", i, j);   // extra args is ok (will be ignored)
    }
    return 0;
}
