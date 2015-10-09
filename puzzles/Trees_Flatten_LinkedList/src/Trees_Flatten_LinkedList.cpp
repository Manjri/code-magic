//============================================================================
// Name        : Trees_Flatten_LinkedList.cpp
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
	void flatten(TreeNode* root)
	{

		while(root)
		{
			if(root->left)
			{
				TreeNode* preR = root->left;

				while(preR->right)
					preR = preR->right;

				preR->right = root->right;

				root->right = root->left;
				root->left = NULL;
			}
			root = root->right;
		}
	}
};

int main() {
	cout << "" << endl; // prints 
	return 0;
}
