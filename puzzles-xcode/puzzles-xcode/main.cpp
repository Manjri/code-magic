#include <iostream>
#include <vector>
using namespace std;


/**
 
 1-2-3
 
 Initially we have 3 choices: 1,2,3 we choose 1 and go
 At 1, we have 2 choices: 2,3, we choose 2 and go
 At 2, we have 1 choice only: 3
 At 3 we are done - so 3 is explored
 Backtrack to 2, we didnt have any other choice other and 3 - so 2 is explored
 Backtrack to 1, we now explore 3 and go
 After visiting 3, we are done - so 3 is explored
 Backtrack back to 1 - our choices 2,3 are explored and so 1 is also explored.
 
 Backtrack to initial position and move with our next choice 2... and move ahead from 2
 story continues similarly...
 
 */



class Solution {
public:
    
    void genSubs(vector<int> nums, int start, vector<vector<int>>& sub, vector<int>& subs){
        sub.push_back(subs);
        for(int i=start; i<nums.size(); i++){
            subs.push_back(nums[i]);
            genSubs(nums, i+1, sub, subs);
            subs.pop_back();
        }
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subs;
        vector<vector<int>> sub;
        sort(nums.begin(), nums.end());
        genSubs(nums, 0, sub, subs);
        return sub;
    }
    
};





/* Driver Program to test above functions */
int main()
{
    Solution s;
    vector<int> vec = vector<int>{1,2,3};

    vector<vector<int>> result = s.subsets(vec);
    
    for(int i=0; i<result.size(); i++)
    {
        for(int j = 0; j<result[i].size(); j++)
            cout << result[i][j];
        cout << endl;
    }
    
    return 0;
}










#if 0

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    
    sort(nums.begin(), nums.end());
    
    result.push_back(vector<int>{});
    
    for(int len = 1; len<=nums.size(); len++){
        for(int i=0; i<nums.size() - len + 1; i++){
            vector<int>::iterator first = nums.begin() + i;
            vector<int>::iterator second = nums.begin() + i + len;
            result.push_back(vector<int>(first, second));
        }
    }
    
    return result;
}
#endif