#ifndef _DATA_PROCESS_H
#define _DATA_PROCESS_H

#include <stdint.h>

/**
Simple Insertion Sort function 
Provides a sorted copy of the array along with its length
Duplicates if any are removed

Arguments: Ptr to array, length of array, address 
of pointer to sorted output array, pointer to length of 
sorted array

Return: None 
*/
void sensorSortAscending(uint16_t* data, long len, uint16_t** sortedData, long* sortedLen);

/**
 * sensorExtract12BitValues accepts a byte array and picks out 
 * successive 12 bit values and stores them individually in a 16 
 * bit uint array 
 *  
 * Arguments: Pointer to Input Byte Array, Length of Input, 
 * Pointer to Output Data Array Pointer, Pointer to Output Data 
 * Array Length 
 *  
 * Return: None 
 *  
 */
void sensorExtract12BitValues(char* inputBuf, long inputLen, uint16_t** outputData, long* outputLen);


#endif
