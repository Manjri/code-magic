//
//  main.cpp
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 4/5/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "findLongestConsecutive.h"

void printLongestConsecutive(int *arr, int n){
    
    unsigned int numMap[100] = {0};
    unsigned int maxCount = 0;
    unsigned int maxStart = 0;
    unsigned int lastSeen = -1;
    unsigned int tempCount = 0;
    unsigned int tempStart = 0;
    for(int i=0; i<n; i++){
        numMap[arr[i]]++;
    }

    for(int i=0; i<100; i++){

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
                    tempCount = 1;
                    tempStart = i;
                    lastSeen = i;
                }
            }
        }
    }
    printf("Printing longiest consecutive range: \n");
    for(int i=0; i<maxCount; i++)
        printf("%d ", maxStart+i);
    printf("\n");
}


int testLongestConsecutive()
{
    int arr[] = {36,41,56,35,44,33,34,92,43,32,42};
    printLongestConsecutive(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
