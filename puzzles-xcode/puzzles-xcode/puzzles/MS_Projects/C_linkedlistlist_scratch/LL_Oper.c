#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

void add_single_ll(Node** head, int data)
{
    if(!(*head))
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        
        if(!newNode)
            return;
        
        newNode->data = data;
        newNode->next = NULL;
        (*head) = newNode;
        return;
    }
    else
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        Node* currNode;

        if(!newNode)
            return;

        newNode->data = data;
        newNode->next = NULL;

        currNode = *head;

        while(currNode->next)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;

    }
}


void print_single_ll(Node* head)
{
    Node* curr;

    if(!head)
        printf("\nEmpty List");
    else
    {
        curr = head;
        printf("\n");
        while(curr)
        {
            printf("%d ->",curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

Node* reverse(Node* curr)
{
    Node *next, *prev=(Node*)NULL;

    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;

}




#if 0
void init_circular()
{
    head = addNode(0);
    tail = addNode(0);

    head->next = tail;
    tail->next = head;
}

void deleteFromLL(int data)
{
    Node* temp0 = head;
    Node* temp = head->next;

    while(temp != tail)
    {
        if(temp->data == data)
        {
            temp0->next = temp->next;
            free(temp);
            printf("\nFound and deleted node with data %d", data);
        }

        temp0 = temp;
        temp = temp->next;
    }
    printf("\n%d Not found !!", data);
}

void printLL(void)
{
    Node* n = head->next;
    while(n != tail)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
}
#endif 