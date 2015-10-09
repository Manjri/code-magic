#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

// defines...
//#define ITER_VECT
#define ITER_LIST
//#define ITER_MAP
// #define VECT_EXAMPLE
//#define MAP_EXAMPLE

#ifdef MAP_EXAMPLE

int main()
{
    map<string, string> dict;
    map<string, string>::iterator p;
    string searchName;

    dict.insert(pair<string, string>("Joe", "555"));

    dict.insert(pair<string, string>("John", "222"));

    for(p=dict.begin(); p!=dict.end(); p++)
        cout << "Name: " << p->first << " Number: " << p->second << endl;

    /*
    cout << "Enter Name" << endl;
    cin >> searchName;

    p = dict.find(cin);
    */


    return 0;
}




#endif


#ifdef VECT_EXAMPLE

class DailyTemp
{
    int temp;
public:
    DailyTemp()
    {
        temp=0;
    }
    DailyTemp(int x)
    {
        temp = x;
    }
    DailyTemp& operator=(int x)
    {
        temp = x;
        return *this;
    }
    double get_temp()
    {
        return temp;
    }
};

bool operator<(DailyTemp a, DailyTemp b)
{
    return a.get_temp() < b.get_temp();
}

bool operator==(DailyTemp a, DailyTemp b)
{
    return a.get_temp()==b.get_temp();
}

bool operator>(DailyTemp a, DailyTemp b)
{
    return a.get_temp()>b.get_temp();
}

#endif



#ifdef VECT_EXAMPLE

int main()
{


    vector<DailyTemp> v;
    unsigned int i;

    for(i=0; i<7;i++)
    {
        v.push_back(DailyTemp(60+rand()%30));
    }

    cout << "\nFahr Temperatures:" << endl;
    for(i=0; i<v.size(); i++)
        cout << v[i].get_temp() << " " ;

    //convert to celsius
    for(i=0; i<v.size(); i++)
        v[i] = (int)(v[i].get_temp()-32) * 5/9;

    cout << endl;

    cout << "\nCentigrade Temperatures:" << endl;
    for(i=0; i<v.size(); i++)
        cout << v[i].get_temp() << " " ;
    
    cout << endl;

    return 0;
       
#endif


#ifdef ITER_VECT
// Iterating through a vector
    vector<int> vect;
    for(int nCount=0; nCount < 6; nCount++)
    {
        vect.push_back(nCount);
    }

    vector<int>::const_iterator it;

    it = vect.begin();

    while(it != vect.end())
    {
        cout << *it << " ";
        it++;
    }

    cout << endl;
#endif

#ifdef ITER_LIST

    list<int> li;
    for(int nCount=0; nCount < 6; nCount++)
        li.push_back(nCount);

    list<int>::const_iterator it;
    it = li.begin();

    while(it != li.end())
    {
        cout << *it++ << " " ;
    }

    cout << endl;
    
#endif

#ifdef ITER_MAP

    map<int, string> mymap;
    
    mymap.insert(make_pair(4, "Apple"));
    mymap.insert(make_pair(2, "Orange"));
    mymap.insert(make_pair(1, "Banana"));
    mymap.insert(make_pair(3, "Grapes"));

    map<int, string>::const_iterator it;

    it = mymap.begin();

    while(it != mymap.end())
    {
        cout << it->first << "=" << it->second << " ";
        it++;
    }

    cout << endl;

}
#endif



