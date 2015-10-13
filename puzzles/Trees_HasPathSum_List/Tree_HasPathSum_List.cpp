//============================================================================
// Name        : Tree_HasPathSum_List.cpp
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
	void pathSumCalculate(TreeNode* root, int sum,
							vector<vector<int>> &res,
							vector<int> &curr_path)
	{

		if(root == NULL)
			return;

		if(!root->left && !root->right && (root->val == sum))
		{
			curr_path.push_back(root->val);
			res.push_back(curr_path);
			curr_path.pop_back();
		}

		curr_path.push_back(root->val);
		pathSumCalculate(root->left, (sum - root->val), res, curr_path);
		curr_path.pop_back();

		curr_path.push_back(root->val);
		pathSumCalculate(root->right, (sum - root->val), res, curr_path);
		curr_path.pop_back();

	}

	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<vector<int>> res;
		vector<int> curr_path;
		pathSumCalculate(root, sum, res, curr_path);
		return res;
	}


};



int main() {
	cout << "" << endl; // prints 
	return 0;
}
