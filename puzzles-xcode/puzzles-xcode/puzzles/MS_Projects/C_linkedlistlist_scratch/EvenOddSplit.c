#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "LL_Oper.h"

void EvenOdd(Node* list, Node** oddList, Node** evenList)
{
    Node* even = NULL;
    Node* odd = NULL;

   // no element
    if(list == NULL)
        return;


    // single element
    if(list->next == NULL)
    {
        if(list->data % 2 == 0)
        {
            *evenList = list;
            *oddList = NULL;
        }
        else
        {
            *oddList = list;
            *evenList = NULL;
        }
        return;
    }

    // more than 1 element
    while(list)
    {
        // examine the current node
        if(list->data % 2 == 0)
        {
            if(!*evenList)
            {
                *evenList = list;
                even = *evenList;
            }
            else
            {                                
                even->next = list;
                even = list;
            }
        }
        else
        {
            if(!*oddList)
            {
                *oddList = list;
                odd = *oddList;
            }
            else
            {

                odd->next = list;
                odd = list;
            }
        }
        list = list->next;
      }
    
    // make the last elements null
    if(odd)
        odd->next = NULL;

    if(even)
         even->next = NULL;

 
}


int test_odd_even_split()
{
    Node* list = NULL;
    Node* even = NULL;
    Node* odd = NULL;

    add_single_ll(&list, 1);
    add_single_ll(&list, 2);
    add_single_ll(&list, 4);
    add_single_ll(&list, 6);

    print_single_ll(list);
    
    EvenOdd(list, &odd, &even);

    print_single_ll(even);
    print_single_ll(odd);

    return 0;
}
