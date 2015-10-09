//============================================================================
// Name        : LL_LoopDetect.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }

        return false;
    }
};

int main() {
	cout << "" << endl; // prints 
	return 0;
}
