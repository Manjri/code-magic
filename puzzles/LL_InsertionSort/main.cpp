#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * Add(ListNode *head, int d)
{
    ListNode *temp = new ListNode(d);
    temp->next = head;
    return temp;
}

void Print(ListNode *head)
{
    while( head )
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode * SortedInsert(ListNode * head, ListNode *newNode )
{
    //special case: newnode to be added as first node
    if( head == NULL || head->val >= newNode->val)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    ListNode *ptr = head;
    ListNode *prev = NULL;
    while ( ptr != NULL && ptr->val < newNode->val )
    {
        prev = ptr;
        ptr = ptr->next;
    }
    newNode->next = ptr;
    prev->next = newNode;
    return head;
}

ListNode* InsertionSort(ListNode *head)
{
    if( !head || !head->next )
        return head;
    
    ListNode * ptr = head->next;
    ListNode * result = head;
    result->next = NULL;
    
    while ( ptr )
    {
        ListNode *temp = ptr;
        ptr = ptr->next;
        result = SortedInsert(result,temp);
    }
    
    return result;
}

int main()
{
    ListNode *head = new ListNode(9);
    head = Add(head,3);
    head = Add(head,5);
    head = Add(head,1);
    head = Add(head,6);
    head = Add(head,4);
    head = Add(head,2);
    head = InsertionSort(head);
    Print(head);
    return 0;
}