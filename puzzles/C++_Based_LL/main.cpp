#include "intSLList.h"
#include <iostream>

int main()
{
    IntSLList list;

    list.addToHead(5);
    list.addToHead(7);
    list.deleteFromHead();
    return 0;

}