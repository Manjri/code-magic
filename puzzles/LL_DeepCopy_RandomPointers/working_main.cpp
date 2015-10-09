/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <iostream>
#include <map>
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
     
        map<RandomListNode*, RandomListNode*> connections;
        RandomListNode *copyHead = new RandomListNode(head->label);
        RandomListNode *curr = copyHead;

        // add to map
        connections.insert(make_pair(curr, head));
        
        head = head->next;
        
        while(head)
        {
            curr->next = new RandomListNode(head->label);
            curr = curr->next;
            
            // add to map
            connections.insert(make_pair(curr, head));
            
            head = head->next;
        }
        
        curr = copyHead;
        
        while(curr)
        {
            map<RandomListNode*, RandomListNode*>::iterator it;
            
            it = connections.find(curr);
            
            RandomListNode *temp = it->second;
            
            for(it = connections.begin(); it!= connections.end(); it++)
            {
                    if(temp->random == it->second)
                    {
                        curr->random = (RandomListNode*)it->first;
                        break;
                    }
            }
            curr = curr->next;
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
