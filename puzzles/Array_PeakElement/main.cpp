#include <iostream>
#include <vector>
using namespace std;

class Solution {

private:
    int findPeakElement(int left, int right, vector<int>& v){
        
        if(left == right)
            return left;
        
        int mid = left + (right-left)/2;
        
        if(v[mid] < v[mid+1])
            return findPeakElement(mid+1, right, v);
        else
            return findPeakElement(left, mid, v);
    }
public:
    
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        else
            return findPeakElement(0, nums.size()-1, nums);        
    }
};


int main(){
    
    int arr[] = {1,3,2,7,9};
    vector<int> myVec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    Solution s;
    cout << s.findPeakElement(myVec) << endl;
    return 0;
}
