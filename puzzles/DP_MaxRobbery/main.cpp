/**
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int evenIndexSum = 0, oddIndexSum = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            // even
            if(i%2==0)
                evenIndexSum = MAX(evenIndexSum+nums[i], oddIndexSum);
            else
                oddIndexSum = MAX(evenIndexSum, oddIndexSum+nums[i]);
        }
        
        return MAX(evenIndexSum, oddIndexSum);
        
    }
};

int main(){
    static const int arr[] = {2,1,1,2};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}
