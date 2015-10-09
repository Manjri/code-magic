//============================================================================
// Name        : Trees_HasPathSum.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:

	bool hasPathSum(TreeNode* root, int sum)
	{
		if(root == NULL)
			return false;

		// is a leaf node and has its sum to equal
		if((root->val == sum) && !root->left && !root->right)
			return true;

		return (hasPathSum(root->left, (sum - root->val))
				|| hasPathSum(root->right, (sum - root->val)));
	}

};


int main() {
	cout << "" << endl; // prints 
	return 0;
}
