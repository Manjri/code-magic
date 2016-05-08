//
//  main.cpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//
#include <stdio.h>
#include <limits.h>

void printLongestConsecutive(int *arr, int n){
    
    unsigned int numMap[UINT_MAX] = {0};
    unsigned int maxCount = 0;
    unsigned int maxStart = 0;
    unsigned int lastSeen = -1;
    unsigned int tempCount = 0;
    unsigned int tempStart = 0;
    for(int i=0; i<n; i++){
        numMap[arr[n]]++;
    }

    for(int i=0; i<UINT_MAX; i++){

        if(numMap[i]){
            if(i==0){
                lastSeen = 0;
                tempStart = i;
            }
            else{
                if(i == (lastSeen+1)){
                    // consecutive
                    tempCount++;
                    lastSeen = i;
                    if(tempCount>maxCount){
                        maxCount = tempCount;
                        maxStart = tempStart;
                    }
                }else{
                    tempCount = 0;
                    tempStart = i;
                    lastSeen = i;
                }
            }
        }
    }
    printf("Printing longest consecutive range: \n");
    for(int i=0; i<maxCount; i++)
        printf("%d ", numMap[maxStart+i]);
    printf("\n");
}

int main()
{
    int arr[] = {1,9,3,10,4,20,2};
    printLongestConsecutive(arr, sizeof(arr)/sizeof(arr[0]));
}
