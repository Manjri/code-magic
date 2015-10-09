#ifndef _SENSOR_IO_H
#define _SENSOR_IO_H

#include <stdint.h>

/**
 * sensorReadFromFile reads data from an input file whose name is provided
 * and dumps the data in a byte array and provides the length of this array

 * Arguments: input file name, address of pointer to output array,
 * pointer to length of output array
 *  
 * Return: None 
 */

void sensorReadFromFile(char* inputFileName, char** outputArray, long* outputArrayLen);

/**
 * sensorWriteIntoFile writes data to an output file whose name is provided
 * 
 * Arguments: output file name, pointer to data array,
 * length of data array, pointer to header string
 *  
 * Return: None 
 */
void sensorWriteIntoFile(char* outputFileName, uint16_t* data, long numDataElements, const char* header);


/**
 * sensorAppendIntoFile appends data to an output file whose name is provided
 * 
 * Arguments: output file name, pointer to data array,
 * length of data array, pointer to header string
 *  
 * Return: None 
 */
void sensorAppendIntoFile(char* outputFileName, uint16_t* data, long numDataElements, const char* header);

#endif
