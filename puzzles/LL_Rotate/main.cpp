// Program to rotate a linked list counter clock wise
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    int data;
    struct node* next;
};

// This function rotates a linked list counter-clockwise and updates the head.
// The function assumes that k is smaller than size of linked list. It doesn't
// modify the list if k is greater than or equal to size
void rotate (struct node **headRef, int k){

    // empty LL or invalid k
    if(*headRef == NULL || k<=0)
        return;
    
    // store kth node
    struct node *current = *headRef;
    int count = 1;
    
    while(count<k && current){
        current = current->next;
        count++;
    }
    
    // k >= the size of list
    if(current == NULL)
        return;
    
    struct node *kNode = current;
    
    // go the end of LL to change next to head
    while(current->next)
        current = current->next;
    
    current->next = *headRef;
    *headRef = kNode->next;
    kNode->next = NULL;
    
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push (struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
    (struct node*) malloc(sizeof(struct node));
    
    /* put in the data  */
    new_node->data  = new_data;
    
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
    
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
    
    printf("Given linked list \n");
    printList(head);
    rotate(&head, 4);
    
    printf("\nRotated Linked list \n");
    printList(head);
    
    return (0);
}