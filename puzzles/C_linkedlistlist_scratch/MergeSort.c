#include <stdio.h>
#include "Node.h"
#include "LL_Oper.h"

void Split(Node* head, Node** left, Node** right)
{
    Node* slow = NULL;
    Node* fast = NULL;
    
    // base case - length < 2 case
    if(head == NULL || head->next == NULL)
    {
        *left = head;
        *right = NULL;
        return ;
    }

    slow = head;
    fast = head->next;

    while(fast!= NULL)
    {
        fast = fast->next;

        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    //at this point slow is one node before mid-point, set the left and right pointers

    *left = head;
    *right = slow->next;
    slow->next = NULL;

    return;
}

Node* MergeBack(Node* left, Node* right)
{
    Node* result = NULL;
    
    //base case
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;

    if(left->data <= right->data)
    {
        result = left;
        result->next = MergeBack(left->next, right);
    }
    else
    {
        result = right;
        result->next = MergeBack(left, right->next);
    }

    return result;
}



void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* left = NULL;
    Node* right = NULL;

    // base case, length < 2 
    if(head == NULL || head->next == NULL)
    {
        return;
    }
    // break lists into left and right sub-lists 
    Split(head, &left, &right);

    //recurse over left and right sub-lists
    MergeSort(&left);
    MergeSort(&right);

    //Finally Merge back
    *headRef = MergeBack(left, right);
}

int testMergeSort()
{
    Node* head = 0;
    
    add_single_ll(&head, 6);
    add_single_ll(&head, 5);
    add_single_ll(&head, 4);
    add_single_ll(&head, 3);
    add_single_ll(&head, 2);
    add_single_ll(&head, 1);

    print_single_ll(head);

    MergeSort(&head);

    print_single_ll(head);

    return 0;
}