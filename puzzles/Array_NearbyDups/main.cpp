#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution{

public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
    
        // use a set to store elements in a sliding window fashion
        std::unordered_set<int> myset;

        for(int i=0; i<nums.size(); i++){
        
            // sliding window check: - delete front now 
            if(i > k)
                myset.erase(nums[i-k-1]);

            // check if element exists in the set
            if(myset.find(nums[i] != myset.end()))
                return true;
            else
                // add the element to the set
                myset.insert(nums[i]);
        }
        return false;
    }


};

int main(){
    Solution s;
       
}
            

    return 0;
}
