#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode
{
public:
    IntSLLNode()
    {
        next = 0;
    }

    IntSLLNode(int d, IntSLLNode *n=0)
    {
        info = d;
        next = n;
    }

    int info;
    IntSLLNode *next;
};

class IntSLList
{
public:
    IntSLList()
    {
        head = tail = 0;
    }
    
    ~IntSLList();

    bool isEmpty()
    {
        return head == 0;
    }

    void addToHead(int);
    void addToTail(int);
    
    int deleteFromHead();   // delete head and return its info
    int deleteFromTail();   // delete tail and return its info

    void deleteNode(int);
    bool isInList(int) const;

private:
    IntSLLNode *head, *tail;
};


#endif