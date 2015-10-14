/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if(NULL == head)
            return NULL;
        
        unordered_map<RandomListNode*, RandomListNode*> connections;  //hashmap (old-random, new-random)
        RandomListNode *copyHead = new RandomListNode(head->label);
        RandomListNode *oldCurr = head;
        RandomListNode *newCurr = copyHead;
        // add to map
        connections.insert(make_pair(head,copyHead));
        
        oldCurr = oldCurr->next;
        
        while(oldCurr)
        {
            newCurr->next = new RandomListNode(oldCurr->label);
            newCurr = newCurr->next;
            // add to map
            connections.insert(make_pair(oldCurr, newCurr));
            oldCurr = oldCurr->next;
        }
        
        oldCurr = head;
        newCurr = copyHead;
        
        while(oldCurr)
        {
            newCurr->random = connections[oldCurr->random]; //hash on the key (old-random)
            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }
        
        return copyHead;
    }
    
};

int main()
{
    Solution s;
    RandomListNode *head = new RandomListNode(1);
    RandomListNode *first, *second, *third, *fourth, *fifth;
    RandomListNode *curr = head;
    
    for(int i=2; i<=5; i++)
    {
        curr->next = new RandomListNode(i);
        curr = curr->next;
    }
    first = head;
    second = first->next;
    third = second->next;
    fourth = third->next;
    fifth = fourth->next;

    first->random = third;
    second->random = fifth;
    third->random = NULL;
    fourth->random = NULL;
    fifth->random = first;
    
    
    
    RandomListNode *copy = s.copyRandomList(head);
    
    return 0;
}
