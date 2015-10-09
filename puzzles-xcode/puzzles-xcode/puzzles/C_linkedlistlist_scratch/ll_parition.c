/**

Write code to partition a linked list around a value x, such that all nodes less than x
come before alt nodes greater than or equal to x

*/
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"


void partitionLL(Node** head, int x)
{
    // create an additional list
    
    Node* curr = *head;
    Node* afterListStart = NULL;
    Node* beforeListStart = NULL;
    Node* afterListEnd = NULL;
    Node* beforeListEnd = NULL;

    if(!curr)
        return;

    while(curr)
    {
        if(curr->data < x)
        {
            //before list
            if(!beforeListStart)
            {
                // first entry into beforeList
                
                beforeListStart = curr;
                beforeListEnd = curr;
            }
            else
            {
                beforeListEnd->next = curr;
                beforeListEnd = beforeListEnd->next;
            }
            
        }
        else
        {
            if(!afterListStart)
            {
                // first entry into afterlist
                
                afterListStart = curr;
                afterListEnd = afterListStart;
            }
            else
            {
                afterListEnd->next = curr;
                afterListEnd = afterListEnd->next;
            }
        }
        curr = curr->next;
    }

    // merge back
    beforeListEnd->next = afterListStart;
    afterListEnd->next = NULL;
    *head = beforeListStart;    
}