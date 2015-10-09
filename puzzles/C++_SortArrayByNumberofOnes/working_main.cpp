#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int count_ones(int num)
{
    int result = 0;
    
    while(num)
    {
        if(num & 0x1)
            result++;
        
        num = num >> 1;
    }
    
    return result;
}

void sortByNumberOnes(int* s, int size)
{
    vector<pair<int, int>> v;
    
    for(int i=0; i<size; i++)
    {
        v.push_back(make_pair(s[i], count_ones(s[i])));
    }
    
    cout << "Original: " << endl;
    
    for (auto a : v)
    {
        cout << a.first << "\t" << a.second << endl;
    }
    
    // sort using a custom function object
    struct {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.second > b.second;
        }
    } valueLess;
    
    sort(v.begin(), v.end(), valueLess);

    cout << "Sorted:: " << endl;
    
    for (auto a : v)
    {
        std::cout << a.first << "\t" << a.second << endl;
    }

}

int main()
{
    int s[] = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    
    sortByNumberOnes(s, sizeof(s)/sizeof(s[0]));
    
    return 0;
    
}