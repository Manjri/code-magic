#include "data_process.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define __DEBUG /* Uncomment it if you want to print debug messages on the console */

// Useful Macros
#define EVEN_NUM(buf,N) (uint16_t) ((uint16_t)buf[N] << 4) | ((uint16_t)(buf[N+1] & 0xF0) >> 4)
#define ODD_NUM(buf, N) (uint16_t)((uint16_t)(buf[N] & 0x0F) << 8) | (uint16_t)(buf[N+1])


/** 
* A simple swap function 
* Arguments: Ptr to array, indices whose data is to be swapped
* Return: None 
*/
static void swap(uint16_t* data, int i, int j)
{
    uint16_t temp = data[j];
    data[j] = data[i];
    data[i] = temp;
}

void sensorSortAscending(uint16_t* data, long len, uint16_t** sortedData, long* sortedLen)
{
    long i,j;
    uint16_t* sortedArray;
    
    sortedArray = (uint16_t*) malloc(sizeof(char) * 2 * len);
    
    if(!sortedArray)
    {
        printf("\nMemory Error !!!\n");
        exit(1);
    }

    memcpy(sortedArray, data, sizeof(char) * 2 * len);

    for(i = 1; i < len; i++)
    {
        for(j = i; j > 0; j--)
        {
            if(sortedArray[j] < sortedArray[j-1])
                swap(sortedArray, j-1, j);
            else
                break;
        }
    }

    // remove duplicates
    for (i = j = 0; i < len; i++)
    {
		    if (sortedArray[i] != sortedArray[j])
        {
            sortedArray[++j] = sortedArray[i];
        }
    }
    
    *sortedData = sortedArray;
    *sortedLen = j+1;

}

void sensorExtract12BitValues(char* inputBuf, long inputLen, uint16_t** outputData, long* outputLen)
{
    uint16_t* data;       /* Array where each element holds a 12-bit number 
                          representing sensor data in the order in which it is read */

    long byteCount = 0;    /* used for counting the number of bytes read (starts with 0th byte) */

    int i, j;

    long num12BitWords;  // size in bytes

    /* To get # of 12 bit words...
       Input len in bytes * 8 give us total bits.. Divide by 12 to get # of 12bit words */
    num12BitWords = (inputLen * 8)/12;
    
    // data is a uint16 size array containing our 12-bit sensor values 
    // malloc should take in size as a multiple of 8 to avoid heap error 
    data = (uint16_t*) malloc(sizeof(char) * 2 * num12BitWords); 

    if(!data)
    {
        printf("\nMemory Error !!!\n");
        exit(2);
    }

    #ifdef __DEBUG
      printf("data[] output 16 bits...\n");
    #endif

    /* Start grabbing bytes in buf and form a 12 bit word in the order of reading */
    // BUG-FIX: Buffer Overrun error fixed. byteCount < inputLen - 1 
    for(i=0; byteCount < inputLen - 1; i++)
    {
        // Read even position 12-bit numbers in the stream (example:0th, 2nd, 4th data ...)
        if(i%2 == 0)
        {
            data[i] = EVEN_NUM(inputBuf, byteCount);
            byteCount += 1;
            #ifdef __DEBUG
              printf("data[%d]:%x\n",i,data[i]&0xFFFF);
            #endif
        }
        // Read odd position 12-bit numbers in the stream (example:1st, 3rd, 5th data ...)
        else
        {
            data[i] = ODD_NUM(inputBuf, byteCount);
            byteCount +=2;
            #ifdef __DEBUG
              printf("data[%d]:%x\n",i,data[i]&0xFFFF);
            #endif
        }

    }

    #ifdef __DEBUG
              printf("Number of 12 bit values (i):%d\n",i);
              printf("num12BitWords:%d\n",num12BitWords);
              printf("\nBuf FileSize:%d\nData FileSize:%d",inputLen, num12BitWords*2);
    #endif

    *outputData = data;
    *outputLen = i;

}
