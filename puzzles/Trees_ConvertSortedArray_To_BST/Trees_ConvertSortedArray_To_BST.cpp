//============================================================================
// Name        : Trees_ConvertSortedArray_To_BST.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        
        if(l<=r){
            int mid = l + (r-l)/2;
            TreeNode* n = new TreeNode(nums[mid]);
            n->left = sortedArrayToBST(nums, l, mid-1);
            n->right = sortedArrayToBST(nums, mid+1, r);
            return n;
        }
        else{
            return NULL;
        }
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size() == 0)
            return NULL;
        else if(nums.size()==1)
            return new TreeNode(nums[0]);
        else{
            return sortedArrayToBST(nums, 0, nums.size()-1);
        }
        
    }
    
};


int main() {
	cout << "" << endl; // prints 
	return 0;
}
