#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size() == 0)
            return NULL;
        
        return dac(lists, 0, lists.size()-1);
    }
    
    ListNode* dac(vector<ListNode*>& lists, int l, int h)
    {
        if(l==h)
            return lists[l];
        
        int mid = (l+h)/2;
        
        ListNode* first = dac(lists, l, mid);
        ListNode* second = dac(lists, mid+1, h);
        
        return merge2Lists(first, second);
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val < l2->val)
        {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }
};


int main()
{
    
    ListNode *head = new ListNode(2);
    ListNode *first, *second;
    vector<ListNode*> vec;
    Solution s;
    
    ListNode *curr = head;
    for(int i=2; i<=5; i++)
    {
        curr->next = new ListNode(2*i);
        curr = curr->next;
    }
    first = head;
    
    head = new ListNode(1);
    curr = head;
    for(int i=1; i<=4; i++)
    {
        curr->next = new ListNode(2*i+1);
        curr = curr->next;
    }
    second = head;
    
    vec.push_back(first);
    vec.push_back(second);
    
    ListNode* result = s.mergeKLists(vec);
    
    return 0;
}
