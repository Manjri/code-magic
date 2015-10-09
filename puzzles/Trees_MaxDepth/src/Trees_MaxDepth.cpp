//============================================================================
// Name        : Trees_MaxDepth.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class Solution
{
public:
	int findMaxDepth(TreeNode* root)
	{
		if(root == NULL)
			return 0;
		else
		{
            return (MAX(findMaxDepth(root->left), findMaxDepth(root->right)) + 1);
        }
	}

};


int main() {
	cout << "" << endl; // prints 
	return 0;
}
