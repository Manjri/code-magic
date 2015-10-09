#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node* next;

}Node;

void FrontBackSpilt(Node* source, Node** front, Node** back)
{

    Node* slow;
    Node* fast;

    // base case for < 2 nodes
    if(source==NULL || source->next == NULL)
    {
        *front = source;
        *back = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;

        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
    
        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }
}

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    // Base cases
    if(a==NULL)
        return b;

    if(b==NULL)
        return a;

    if(a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

// merge-sort
void mergesort(Node** headref)
{
    Node* head = *headref;
    Node* a;
    Node* b;

    // base case for < 2 nodes
    if(head == NULL || head->next==NULL)
        return;

    FrontBackSpilt(head, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *headref = SortedMerge(a,b);

}

// add elements at start
void push(Node** head, int data)
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = *head;
    *head = n;
}

void print(Node* head)
{
    while(head !=NULL)
    {
        cout << head->data << " " ;
        head = head->next;
    }
}

int main()
{
    Node* head = NULL ;
    Node** headref = &head;
    
    push(headref, 10);
    push(headref, 50);
    push(headref, 20);
    push(headref, 30);
    push(headref, 40);
    push(headref, 60);

    mergesort(headref);

    return 0;
}