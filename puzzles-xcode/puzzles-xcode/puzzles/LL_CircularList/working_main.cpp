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

class CircularLL
{
private:
    Node* tail;
    
public:
    CircularLL()
    {
        tail = NULL;
    }
    
    void addToTail(int data)
    {
        // if tail is empty
        if(tail == NULL)
        {
            tail = new Node(data);
            tail->next = tail;
        }
        else
        {
            tail->next = new Node(data, tail->next);
            tail = tail->next;
        }
    }
    int deleteFromHead()
    {
        int tempData;
        
        // Circular LL contains only one node
        if(tail == tail->next)
        {
            tempData = tail->num;
            delete tail;
            tail = NULL;
        }
        else
        {
            Node* front = tail->next;
            tempData = front->num;
            tail->next = front->next;
            delete front;
        }
        
        return tempData;
    }

    
    void displayList()
    {
        if(tail)
        {
            Node *front = tail->next;
            Node *p = front;

            cout << p->num << endl;
            
            front = front->next;
            while(p != front)
            {
                cout << front->num <<endl;
                front = front->next;
            }
        }
    }
};



int main()
{
    CircularLL *cll = new CircularLL();
    
    cll->addToTail(1);
    cll->addToTail(2);
    cll->addToTail(3);
    cll->addToTail(4);
    
    cll->displayList();
    
    cll->deleteFromHead();
    cll->deleteFromHead();
    
    cll->displayList();
    
    return 0;
}