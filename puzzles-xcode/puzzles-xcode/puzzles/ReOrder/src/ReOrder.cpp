//============================================================================
// Name        : ReOrder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
};

class Solution {

public:
	void reverseList(ListNode* &head)
	{
		ListNode* temp;
		ListNode* next = NULL;
		ListNode* curr = head;

		while(curr)
		{
			temp = curr->next;
			curr->next = next;
			next = curr;
			curr = temp;
		}
		head = next;
	}

public:
    void reorderList(ListNode *head)
    {
        // find the mid of the list
        ListNode* slow = head;
        ListNode* fast = head;

        if(!slow || !slow->next || !slow->next->next)
        	return;


        while(fast->next && fast->next->next)
        {
        	slow = slow->next;

        	fast = fast->next;
        	fast = fast->next;

        }

        // slow is at mid

        reverseList(slow);

        ListNode* first = head;
        ListNode* second = slow;
        ListNode* temp;

        while(second && first && first!=second)
        {
        	temp = second->next;
        	second->next = first->next;
        	first->next = second;
        	first = second->next;
        	second = temp;
        }
    }
};

int main()
{
	Solution s;

	ListNode* first = (ListNode*)malloc(sizeof(ListNode));
	ListNode* second = (ListNode*)malloc(sizeof(ListNode));
	ListNode* third = (ListNode*)malloc(sizeof(ListNode));
	ListNode* fourth = (ListNode*)malloc(sizeof(ListNode));
	ListNode* fifth = (ListNode*)malloc(sizeof(ListNode));

	first->val = 1;
	first->next = second;

	second->val = 2;
	second->next = third;

	third->val = 3;
	third->next = fourth;

	fourth->val = 4;
	fourth->next = fifth;

	fifth->val = 5;
	fifth->next = NULL;

	s.reorderList(first);

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
