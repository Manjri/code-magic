#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int len = nums.size();
        int last = 0;
        int curr = 0;
        int temp;
        
        if(len==0)
            return;
        
        // last and curr are in stride for non-zero numbers
        // when a zero is encountered last stops, while curr marches till next non-zero
        // when curr finally reaches a non-zero, it swaps with last (which is at a zero position) and increments it
        
        while(curr<len)
        {
            if(nums[curr]!=0)
            {
                swap(nums[curr], nums[last]);
                last++;
            }
            curr++;
        }
    }
};

int main(){
    
    vector<int> vec;
    Solution s;
    
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(0);
    
    for(int i=0; i<vec.size(); i++)
        cout << vec[i] << " ";
    
    cout << endl;
    
    s.moveZeroes(vec);
    
    for(int i=0; i<vec.size(); i++)
        cout << vec[i] << " ";
    
    return 0;
}