/**
 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 */


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
    
    ListNode *addTwoLL(ListNode *l1, ListNode *l2, unsigned int carry)
    {
        if(l1 || l2 || carry)
        {
            unsigned int result = carry;
            
            if(l1)
                result += l1->val;
            
            if(l2)
                result += l2->val;
            
            unsigned int val = result % 10;
            unsigned int c = result / 10;
            
            ListNode *r = new ListNode(val);
            
            r->next = addTwoLL(l1?l1->next:NULL,l2?l2->next:NULL, c);
            
            return r;
        }
        return (ListNode *)NULL;
    }
    
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if(!l1 && !l2)
            return NULL;
        
        return addTwoLL(l1, l2, 0);
        
    }
};