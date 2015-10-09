#include <stdio.h>

#define REGIONS_OVERLAP(a_start, a_end, b_start, b_end) \
        (((a_start >= b_start) && (a_end <= b_start)) \
        || \
        ((a_start <= b_start) && (b_end <= a_start))) \



/*
      a_s     a_e
     b_s     b_e

      a_s     a_e
          b_s  b_e
    
      a_s          a_e
          b_s  b_e


*/

#define REGIONS_OVERLAP_1(a_start, a_end, b_start, b_end) \
        (((a_start >= b_start) && (a_start < b_end)) \
        || \
        ((a_end > b_start) && (a_end <= b_end)) \
        || \
        ((a_start <= b_start) && (a_end >= b_end)))


int test_overlap()
{
    int a_start = 50;
    int a_end   = 101;
    int b_start = 100;
    int b_end   = 200;

    printf("\na_start:%d, a_end:%d, b_start:%d, b_end:%d", a_start, a_end, b_start, b_end);

    if(REGIONS_OVERLAP_1(a_start, a_end, b_start, b_end))
    {
        printf("\nOverlap:TRUE");
        return 0;
    }
    printf("\nOverlap:FALSE");
    return 0;
}