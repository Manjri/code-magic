#include "sensor_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_VALUES 32

/**
 * getBytesFromFile reads data in bytes from a valid file
 * pointer and stores them in a byte array
 *  
 * Arguments: FilePointer, Pointer to OutputByteArray Pointer, 
 * Pointer to Output ArrayLength 
 *  
 * Return: None 
 */

static void getBytesFromFile(FILE* fp, char** outputArray, long* outputArrayLen)
{
    char* buf;          /* Array where each element holds a byte of data from 
                        the input file stream */
    long fileSize;
    size_t result;        /* Result of fread */

    if(!fp)
    {
        printf("\nFile Error !!!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);

    // buf should be equal to the file size in bytes
    buf = (char*) malloc(sizeof(char)*fileSize);
    
    if(!buf)
    {
        printf("\nMemory Error !!!\n");
        exit(2);
    }

    result = fread(buf, 1, fileSize, fp);

    if(result != fileSize)
    {
        printf("\nFile Read Error !!!\n");
        exit(3);
    }

    *outputArray = buf;
    *outputArrayLen = fileSize;
}


void sensorReadFromFile(char* inputFileName, char** outputArray, long* outputArrayLen)
{
    FILE* inputFile;
    char* buf;            /* Array where each element holds a byte of data from 
                          the input file stream */

    inputFile = fopen(inputFileName, "rb");
    
    if(!inputFile)
    {
        printf("\nFile Error !!!\n");
        exit(1);
    }

    getBytesFromFile(inputFile, outputArray, outputArrayLen);

    fclose(inputFile);

}


void sensorWriteIntoFile(char* outputFileName, uint16_t* data, long numDataElements, const char* header)
{
    int i;
    FILE* outputFile;
    
    // Create the output file
    outputFile = fopen(outputFileName, "w");

    if(!outputFile)
    {
        printf("\nFile Error !!!\n");
        exit(1);
    }

    // write header to the file
    fprintf(outputFile,"%s\n",header);

    if(numDataElements >= MAX_VALUES )
    {
        for(i = MAX_VALUES; i > 0; i--)
        {
            fprintf(outputFile, "%d\n", data[numDataElements-i]);
        }
    }
    else
    {
        for(i = 0; i < numDataElements; i++)
        {
            fprintf(outputFile, "%d\n", data[i]);
        }
    }

    fclose(outputFile);
}


void sensorAppendIntoFile(char* outputFileName, uint16_t* data, long numDataElements, const char* header)
{
    int i;
    FILE* outputFile;
    
    // Create the output file
    outputFile = fopen(outputFileName, "a");

    if(!outputFile)
    {
        printf("\nFile Error !!!\n");
        exit(1);
    }

    // write header to the file
    fprintf(outputFile,"%s\n",header);

    if(numDataElements >= MAX_VALUES )
    {
        for(i = MAX_VALUES; i > 0; i--)
        {
            fprintf(outputFile, "%d\n", data[numDataElements-i]);
        }
    }
    else
    {
        for(i = 0; i < numDataElements; i++)
        {
            fprintf(outputFile, "%d\n", data[i]);
        }
    }

    fclose(outputFile);
}
