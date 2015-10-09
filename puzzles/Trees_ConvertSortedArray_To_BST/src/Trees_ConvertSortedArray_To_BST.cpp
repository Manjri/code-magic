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

class Solution
{
public:

	TreeNode* convertToBST(int start, int end, vector<int> num)
	{
		if(start > end)
			return NULL;

		int mid = (start+end)/2;

		TreeNode* root = new TreeNode(num[mid]);

		root->left = convertToBST(start, mid-1, num);
		root->right = convertToBST(mid+1, end, num);

		return root;
	}

	TreeNode *sortedArrayToBST(vector<int> &num)
	{
		return convertToBST(0,(num.size()-1), num);
	}
};


int main() {
	cout << "" << endl; // prints 
	return 0;
}
