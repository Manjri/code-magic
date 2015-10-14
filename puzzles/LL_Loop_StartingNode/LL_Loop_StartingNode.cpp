//============================================================================
// Name        : LL_Loop_StartingNode.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
 *
 * */

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{

private:
ListNode* findCycleStart(ListNode* cycleNode, ListNode* head)
{
    // count the number of nodes in cycle
    int k = 1;
    ListNode* ptr1 = cycleNode;
    ListNode* ptr2 = cycleNode;

    while(ptr2->next != ptr1)
    {
        k++;
        ptr2 = ptr2->next;
    }

    ptr1 = head;
    ptr2 = head;

    //move ptr2 k nodes apart
    for(int i=0; i<k; i++)
        ptr2 = ptr2->next;

    // move ptr1 and the ptr2 at the same pace,
    // place where they meet is the cycle start

    while(ptr2 != ptr1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr2;
}

public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                ListNode* start = findCycleStart(slow, head);
                return start;
            }
        }

        return NULL;
    }
};





int main() {
	cout << "" << endl; // prints 
	return 0;
}
