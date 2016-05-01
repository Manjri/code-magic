#include <stdio.h>
#include <stdint.h>

int main(){
        
    int32_t x;
    for(int i=0; i<32;i++){
        uint32_t num = (uint32_t)(1<<(31-i))-1;
        printf("num:%x\n",num);
        x = num<<(31-i);
        printf("x: %d\n",x);
    }
    return 0;
}
