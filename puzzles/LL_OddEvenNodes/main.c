/**
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
*/

#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* gHead = NULL;

struct ListNode* oddEvenList(struct ListNode* head) {
  
    if(!head || !head->next || !head->next->next)
        return head;
 
    struct ListNode* odd = head;            // odd  = 1
    struct ListNode* even = head->next;     // even = 2
    struct ListNode* evenStart = even;
 
    while(odd && even && odd->next){
        
        odd->next = even->next;             
        if(odd->next){
            even->next = odd->next->next;
            odd = odd->next;
            even = even->next;
        }
        else{
            even->next = NULL;
            even = even->next;
        }      
    }

    odd->next = evenStart;
    return head; 
}

void addToFront(int num){

    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = num;
    temp->next = gHead;
    gHead = temp;
}

void printLL(struct ListNode* head){

    struct ListNode* temp = head;
    
    while(temp){
        printf("%d->",temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){

    addToFront(6);
    addToFront(5);
    addToFront(4);
    addToFront(3);
    addToFront(2);
    addToFront(1);

    printLL(gHead);

    gHead = oddEvenList(gHead);

    printLL(gHead);

    return 0;
}

