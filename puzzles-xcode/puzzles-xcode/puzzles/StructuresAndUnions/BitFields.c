#include <stdio.h>

typedef struct rgb_color_s
{
    unsigned char r:2; // 2 bits
    unsigned char g:2;
    unsigned char b:2;
}rgb_color_s;

typedef union rgb_color_u
{
    struct
    {
        unsigned char r:2, g:2, b:2;
        unsigned char:2; //free space
    };
    struct 
    {
        unsigned char rgb:6;
        unsigned char:2;
    };
}rgb_color_u;

int main()
{
    rgb_color_s color = {0};
    rgb_color_u color_union = {0};
     
    // padding  - largest address
    color.b = 1;
    color.g = 2;
    color.r = 2; //smallest address
#if 0
    printf("Red: %d\n", color.r);
    printf("Blue: %d\n", color.b);
    printf("Green: %d\n", color.g);
#endif
    color_union.r = 3;
    printf("Red: %d\n", color_union.r);
    color_union.rgb = 5;
    
    printf("Union: %d\n", color_union.rgb);
    
    printf("Red: %d\n", color_union.r);
    printf("Green: %d\n", color_union.g);
    printf("Blue: %d\n", color_union.b);

    return 0;
}