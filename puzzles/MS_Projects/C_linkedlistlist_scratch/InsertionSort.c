#include <stdio.h>
#include "Node.h"
#include "LL_Oper.h"

Node* insertionSortLL(Node* pList)
{
    Node* head;
    Node* curr;

    // check for NULL or single element List
    if(!pList || !pList->next)
        return pList;

    head = NULL;
    
    while(pList)
    {
        curr = pList;
        // save the next pointer
        pList = pList->next;

        if(head == NULL || curr->data < head->data)
        {
            curr->next = head;
            head = curr;
        }
        else
        {
            Node* p = head;

            while(p)
            {
                if(p->next == NULL || curr->data < p->next->data)
                {
                    curr->next = p->next;
                    p->next = curr;
                    break;
                }
                p = p->next;
            }
        }
    }
    return head;
}



int test_insertion_sort()
{
    // create a list
    Node* head = NULL;
    Node* sorted = NULL;

    add_single_ll(&head, 6);
    add_single_ll(&head, 3);
    add_single_ll(&head, 4);
    add_single_ll(&head, 5);

    sorted = insertionSortLL(head);

    return 0;
}