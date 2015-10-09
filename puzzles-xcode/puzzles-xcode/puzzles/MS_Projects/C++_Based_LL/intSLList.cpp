#include <iostream>
#include "intSLList.h"

IntSLList::~IntSLList()
{
    //delete every node
    for(IntSLLNode *p; !isEmpty(); )
    {
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(int el)
{
    head = new IntSLLNode(el, head);

    if(tail == 0)
        tail = head;

}

void IntSLList::addToTail(int el)
{
    if(tail != 0)
    {
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    }
    head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead()
{
    int el = head->info;
    IntSLLNode *tmp = head;
    
    if(head == tail)        //only 1 element
        head = tail = 0;
    else
        head = head->next;

    delete tmp;
    return el;
}

int IntSLList::deleteFromTail()
{
    int el = tail->info;
    if(head == tail)        // only 1 element
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        // find the predecesor of tail
        IntSLLNode *tmp = head;
        for(;tmp->next != tail; tmp=tmp->next)
            ;
        delete tail;
        tail = tmp;     //predecesor becomes the tail
        tail->next = 0;
    }
    return el;
}

void IntSLList::deleteNode(int el)
{
    if(head!=0)
    {
       // only 1 node
        if(head == tail && head->info == el)
        {
            delete head;
            head = tail = 0;
        }
        else if(el=head->info)      // more than 1 node
        {
            IntSLLNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            IntSLLNode *pred, *tmp;
            
            for(pred = head, tmp=pred->next; tmp!=0 && el!=tmp->info;
                pred=pred->next, tmp=tmp->next)
                ;
            if(tmp != 0)
            {
                pred->next = tmp->next;
                
                if(tmp == tail)
                    tail = pred;

                delete tmp;
            }
        }
    }
}

bool IntSLList::isInList(int el) const
{
    IntSLLNode *tmp;

    for(tmp=head; tmp!=0 && tmp->info != el; tmp=tmp->next)
        ;

    return tmp != 0;
}









