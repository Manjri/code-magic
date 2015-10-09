#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    unordered_map<string, int>::iterator myMapIterator;

    m["foo"] = 0;
    m["bar"] = 1;

    for(myMapIterator = m.begin(); myMapIterator != m.end(); myMapIterator++)
    {
        cout << myMapIterator->first << ":" << myMapIterator->second << endl;
    }

    return 0;
}



#if 0
int main() 
{
    unordered_map <string, int> m;
    m["foo"] = 42;
    cout << m["foo"] << endl;
    return 0;
}
#endif