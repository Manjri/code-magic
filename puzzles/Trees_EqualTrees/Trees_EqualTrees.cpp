//============================================================================
// Name        : Trees_EqualTrees.cpp
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
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};



class Solution
{

public:

	bool treesEqual(TreeNode* p, TreeNode* q)
	{
		if(p && q)
		{
			if(p->val == q->val)
				return (treesEqual(p->left, q->left) && treesEqual(p->right ,q->right));
			else
				return false;
		}
		else if(!p && !q)
			return true;

		else
			return false;
	}

};


int main() {
	cout << "" << endl; // prints 
	return 0;
}
