#include <stdio.h>
#include "Node.h"
#include "LL_Oper.h"

Node* returnKthFromEnd(Node *head, int k)
{
    if(head != NULL)
    {
        Node* fastP;
        Node* slowP;
        int count = 0;

        fastP = head;
        slowP = head;

        if(k <= 0)
        {
            printf("\nK cannot be less than or equal 0");
            return NULL;
        }

        while(fastP)
        {
            if(count == (k-1))
            {
                break;
            }
            else
            {
                fastP = fastP->next;
                count++;
            }
        }
        if(fastP == NULL)
        {
            printf("\n Cannot reach kth element");
            return NULL;
        }

        // slow starts now
        while(fastP->next)
        {
            fastP = fastP->next;
            slowP = slowP->next;
        }

         return slowP;
    }
}

int testKFromEnd()
{
    Node* head = NULL;
    Node* elem;

    add_single_ll(&head, 1);
    add_single_ll(&head, 2);
    add_single_ll(&head, 3);
    
    elem = returnKthFromEnd(head, 2);
    printf("\n K-th Elem: %d", elem->data);

    return 0;
}



