//
//  sortedArrayMedian.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/1/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "sortedArrayMedian.h"
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))


int findMedian(int arr1[], int arr2[],
               int low1, int high1,
               int low2, int high2){

    int m1=0, m2=0;
    int n1 = high1-low1+1;
    int n2 = high2-low2+1;
    
    if(n1>2){
        // odd
        if(n1%2){
            m1 = arr1[low1+n1/2];
            m2 = arr2[low2+n1/2];
        }else{  // even
            m1 = (arr1[low1+n1/2-1]+arr1[low1+n1/2])/2;
            m2 = (arr2[low2+n2/2-1]+arr2[low2+n2/2])/2;
        }
        // recurse over sub-arrays
        if(m1<m2){ // [m1..high1  low1 ... m2]
            return findMedian(arr1, arr2, (low1+(n1/2)), high1, low2, (low2+(n2/2)));
        }else{     // [low1...m1 m2 ... high]
            return findMedian(arr1, arr2, low1, (low1+(n1/2)), (low2+(n2/2)), high2);
        }
    }else{
        return (MAX(arr1[low1],arr2[low2]) + MIN(arr1[high1],arr2[high2]))/2;
    }
}

void testMedian(){
    int arr1[] = {1,12,15,26,38};
    int arr2[] = {2,13,17,30,45};
    int median = findMedian(arr1, arr2, 0, ARRAY_SIZE(arr1)-1, 0, ARRAY_SIZE(arr2)-1);
    printf("Median of 2 arrays is: %d\n",median);
}
