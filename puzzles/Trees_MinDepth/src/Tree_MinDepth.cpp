//============================================================================
// Name        : Tree_MinDepth.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>

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
	int getMinDepth(TreeNode* root)
	{
		if(root == NULL)
			return INT_MAX;

		if(!root->left && !root->right)
			return 1;

		int lDepth  = getMinDepth(root->left);
		int rDepth  = getMinDepth(root->right);

		if(lDepth < rDepth)
			return lDepth+1;
		else
			return rDepth+1;

	}

	int findMinDepth(TreeNode* root)
	{
		if(root == NULL)
			return 0;
		else
			return getMinDepth(root);
	}
};


int main() {

	TreeNode* t1 = new TreeNode(1);
	t1->right = new TreeNode(2);
	Solution s;
	cout << s.findMinDepth(t1) << endl;
	return 0;
}
