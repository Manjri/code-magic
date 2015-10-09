/**
[A]
You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the 1 's digit is at the head
of the list. Write a function that adds the two numbers and returns the sum as a
linked list.

[B]
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
*/

#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include "LL_Oper.h"

/**
[A]
*/

Node* addLL(Node* l1, Node*l2, int carry)
{
    Node*n = (Node*)malloc(sizeof(Node)); 
    int val = 0;

    if(l1 == NULL && l2 == NULL && carry == 0)
    {
        return NULL;
    }
    
    if(!n)
        return NULL;

    val = carry;
    //n->next = NULL;


    // assuming nodes are of equal size (else pad it first)

    if(l1)
        val += l1->data;

    if(l2)
        val += l2->data;

    n->data = val % 10;

    if(11 != NULL || l2 != NULL)
    // rescurse
        n->next = addLL(l1==NULL ? NULL:l1->next, l2==NULL ? NULL:l2->next, (val/10));

    return n;
}


void testAddition()
{
    Node* l1 = NULL; 
    Node* l2 = NULL; 
    Node* res = NULL;

    add_single_ll(&l1, 6);
    add_single_ll(&l1, 1);
    add_single_ll(&l1, 7);
    
    add_single_ll(&l2, 2);
    add_single_ll(&l2, 9);
    add_single_ll(&l2, 5);

    print_single_ll(l1);
    print_single_ll(l2);

    res = addLL(l1,l2,0);
    print_single_ll(res);
}



