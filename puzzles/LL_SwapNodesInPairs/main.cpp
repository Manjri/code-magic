// Uses Recursion

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *nextNode = head->next;
        ListNode *newHead = nextNode->next;
        nextNode->next = head;
        head->next = swapPairs(newHead);
        return nextNode;
    }
};