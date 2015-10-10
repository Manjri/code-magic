#include <iostream>
#include <unordered_map>
using namespace std;

/** 
 Leetcode:
 
 Given an array of integers, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> numMap;
        int len = nums.size();
        
        for(int i=0; i<len; i++)
        {
            if(numMap.find(target-nums[i])!=numMap.end())
                return (vector<int>{numMap[target-nums[i]]+1, i+1});
            
            numMap.insert({nums[i], i});
        }
    }
};