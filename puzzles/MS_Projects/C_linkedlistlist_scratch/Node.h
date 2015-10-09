#ifndef __NODE_H__
#define __NODE_H__

#include <stdlib.h>

typedef struct Node
{
    struct Node* next;
    int data;
}Node;

typedef struct PartialSum{

    Node sum;
    int carr;
}PartialSum;


#endif