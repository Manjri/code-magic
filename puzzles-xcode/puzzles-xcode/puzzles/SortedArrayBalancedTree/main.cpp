/* * main.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: nikhil
 */

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;

 }TreeNode;

TreeNode* NewTreeNode(int val)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

	node->val = val;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void inOrderDisplay(TreeNode* root)
{

	if(!root)
		return;

	inOrderDisplay(root->left);
	cout << root->val << endl;
	inOrderDisplay(root->right);

	return;

}

void preOrderDisplay(TreeNode* root)
{
	if(!root)
		return;

	cout << root->val << endl;
	preOrderDisplay(root->left);
	preOrderDisplay(root->right);
	return;
}

void postOrderDisplay(TreeNode* root)
{
	if(!root)
		return;

	postOrderDisplay(root->left);
	postOrderDisplay(root->right);
	cout << root->val << endl;
}

class Solution
{
    TreeNode* convertSortedArrayToTree(vector<int> &num, int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }

        int mid = (start+end)/2;

        TreeNode* root = NewTreeNode(num[mid]);

        root->left = convertSortedArrayToTree(num, start, mid-1);
        root->right = convertSortedArrayToTree(num, mid+1, end);

        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        return convertSortedArrayToTree(num, 0, num.size()-1);
    }
};


int main()
{
	Solution s;
	vector<int> num;

	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);

	TreeNode* root = s.sortedArrayToBST(num);
	cout << "Inorder" << endl;
	inOrderDisplay(root);
	cout << "Preorder" << endl;
	preOrderDisplay(root);
	cout << "Postorder" << endl;
	postOrderDisplay(root);
	return 0;
}



