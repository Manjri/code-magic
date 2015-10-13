//============================================================================
// Name        : Trees_IsSymmetric.cpp
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
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};


class Solution
{

public:

	bool isSymmetric(TreeNode* left, TreeNode* right)
	{
		if(!left)
			return right == NULL;

		if(!right)
			return left == NULL;

		if(left->val != right->val)
			return false;

		if(!isSymmetric(left->left, right->right))
			return false;

		if(!isSymmetric(left->right, right->left))
			return false;

		return true;
	}

	bool isSymmetric(TreeNode* root)
	{
		if(!root)
			return true;
		else
			return isSymmetric(root->left, root->right);
	}

};


int main() {
	cout << "" << endl; // prints 
	return 0;
}
