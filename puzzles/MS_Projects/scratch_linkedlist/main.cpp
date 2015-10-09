#include <iostream>
#include <list>
#include <map>

using namespace std;

/* adding elements in to 2 linked lists and generating a LL with its numbers
eg: 
617 + 295 = 912

7->1->6 + 5->9->2 = 2->1->9

recursively implement it...

*/
#if 0
list<int> addLL(list<int> l1, list<int> l2, int carry)
{
    list<int>::const_iterator l1_Iter;
    list<int>::const_iterator l2_Iter;

    /* we are done if both the LLs AND the carry are null */
    if(l1.empty() && l2.empty() && carry == 0)
        return (list<int>)NULL;

    // init the iterators
    l1_Iter = l1.begin();
    l2_Iter = l2.begin();

    // add value and data from l1 and l2
    int value = carry;
    if(!l1.empty())
        value += l1.

}
#endif

void removeDups(list<int>& inList)
{
    map<int, bool> mymap;
    map<int, bool>::iterator map_it;

    list<int>::const_iterator it;
    it = inList.begin();

    while(it != inList.end())
    {
        map_it = mymap.find(*it);

        if(map_it != mymap.end())
        {
            // duplicate found
            it = inList.erase(it);
        }
        else
        {
            // first instance of this element
            // store it
            mymap.insert(make_pair(*it, true));
        }

        it++;
    }
    
    return;
}




void removeDups_1(list<int>& l)
{
    map<int, bool> m;
    list<int>::iterator i;

    i=l.begin();
    m.clear();

    for(;i!=l.end(); i++)
    {
        if(m.find(*i)!=m.end())
        {
            i = l.erase(i);
            i--; // will not fail for 1st element 
        }
        else
        {
            m.insert(pair<int, bool>(*i,true));
        }
    }
}


int main()
{
    // remove duplicates from a linked list using a temp buffer 
    
    // define a list variable
    list<int> li;
    
    // start adding elements...
    li.push_back(100);
    li.push_back(150);
    li.push_back(150);
    li.push_back(200);
    li.push_back(300);
    li.push_back(300);
    li.push_back(400);
    li.push_back(400);
    li.push_back(500);

    // print the list
    list<int>::const_iterator it, new_it;

    it = li.begin();

    cout <<  "Before the Remove Dups function" << endl;

    while(it != li.end())
    {
        cout << *it << " ";
        it++;
    }

    cout << endl;

    cout <<  "After the Remove Dups function" << endl;

    //removeDups(li);
    removeDups_1(li);

    new_it = li.begin();

    while(new_it != li.end())
    {
        cout << *new_it << " ";
        new_it++;
    }

    cout << endl;
    
    return 0;
}
