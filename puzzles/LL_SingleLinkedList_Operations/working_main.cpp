#include <iostream>

using namespace std;


class Node
{
public:
    int num;
    Node* next;
    
public:
    Node()
    {
        next = NULL;
    }
    
    Node(int data, Node *ptr = 0)
    {
        num = data;
        next = ptr;
    }
    
};

class SLL
{
private:
    Node* head;
    Node* tail;
    
public:
    SLL()
    {
        head = tail = NULL;
    }
    
    void addToHead(int data)
    {
        head = new Node(data, head);
        
        // for single node in the list
        if(tail == 0)
            tail = head;
    }
    
    void addToTail(int data)
    {
        // if tail is not empty
        if(tail != NULL)
        {
            tail->next = new Node(data);
            tail = tail->next;
        }
        else
        {
            tail = new Node(data);
            head = tail;
        }
    }
    
    int deleteFromHead()
    {
        int temp = head->num;
            
        // list containing single node
        if(head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node* tempNode = head;
            head = head->next;
            delete tempNode;
        }
        return temp;
    }
    
    int deleteFromTail()
    {
        int temp = tail->num;
        
        // list containing single Node
        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
        }
        else
        {
            // we have to loop till we get the prev to tail
            Node* tempNode = head;
            
            for(; tempNode->next!=tail; tempNode = tempNode->next)
                ;
            delete tail;
            tail = tempNode;
            tempNode->next = NULL;
        }
        return temp;
    }
    
    void deleteNode(int data)
    {
        // if non-empty list
        if( head != 0)
        {
            // if only one node in the list && head contains the element
            if(head == tail && (head->num == data))
            {
                delete head;
                head = tail = NULL;
            }
            // head contains the element but list contains more elements
            else if(head->num == data)
            {
                Node *tempNode = head;
                head = head->next;
                delete tempNode;
            }
            // need to search the list for matching node
            else
            {
                // we will need to get the predecssor node to skip over deleteNode
                Node *predNode, *tempNode;
                for(predNode = head, tempNode = head->next;
                    tempNode!=0 && tempNode->num!=data;
                    predNode=predNode->next ,tempNode = tempNode->next)
                {
                    
                    if(tempNode!=0)
                    {
                        predNode->next = tempNode->next;
                        
                        if(tempNode == tail)
                            tail = predNode;
                        
                        delete tempNode;
                    }
                } // for-end
            } //else for non-matching head
        } //non-empty list
    }
    
};



int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2, n1);
    
    return 0;
}