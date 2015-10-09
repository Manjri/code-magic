// set.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int findSingleElement(int arr[], int n)
{
    set<int> s;
    
    for (int i=0; i<n; i++) {
        
        if(s.find(arr[i])!=s.end())
        {
            // found it, now erase it
            s.erase(arr[i]);
        }else{
            
            // add it into the set
            s.insert(arr[i]);
        }
    }
    
    return *(s.begin());
}

int findSingleElement1(int arr[], int n)
{
    
    map<int, int> m;

    for(int i=0; i<n; i++)
    {
        m[arr[i]]++;
    }
    
    for(auto i : m)
    {
        if(i.second == 1)
            return i.first;
    }
    
    // should never reach here
    return 0;
}

int findSingleElement2(int arr[], int n)
{
    
    int result = 0;
    
    for(int i= 0; i<n; i++)
    {
        result ^= arr[i];
    }
    
    return result;
}

int main( int argc, char ** argv )
{
    int arr[] = {4,2,4,5,2,5,3};
    cout << "Odd Element is: " << findSingleElement2(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    return 0;
}
