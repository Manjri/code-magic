#include <iostream>
#include <vector>

using namespace std;


template <class T>
class Solution
{
    
private:
    void swap(vector<T>& v, int l, int h)
    {
        T temp = v[l];
        v[l] = v[h];
        v[h] = temp;
    }
    
    void vector_print(vector<T> v)
    {
        for(int i = 0; i<v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
    
    void permute_helper(vector<vector<T>>& result, vector<T> nums, int l, int h)
    {
        if(l == h)
        {
            result.push_back(nums);
            vector_print(nums);
        }
        else
        {
            for(int i=l; i<=h; i++)
            {
                if(i!=l  && nums[i]==nums[l])   // trick to avoid printing dups (2)
                    continue;
                
                swap(nums, l, i);
                permute_helper(result, nums, l+1, h);   //backtracking using recursion
            }
        }
    }
    
public:
    vector<vector<T>> permuteUnique(vector<T>& nums)
    {
        vector<vector<T>> result;
        sort(nums.begin(), nums.end());     // trick to avoid printing dups (1)
        permute_helper(result, nums, 0, nums.size()-1);
        return result;
    }
};

int main()
{
#if 0
    Solution<int> s;
    vector<int> vec;
    vector<vector<int>> res;
    
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
#endif
    
    Solution<char> s;
    vector<char> vec;
    vector<vector<char>> res;
    
    vec.push_back('a');
    vec.push_back('b');
    vec.push_back('c');
    vec.push_back('c');
    
    
    res = s.permuteUnique(vec);
    
    return 0;
}

