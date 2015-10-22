/**
 
 Given a binary tree, return all root-to-leaf paths.
 
 For example, given the following binary tree:
 
   1
  /  \
 2    3
  \
   5
 All root-to-leaf paths are:
 
 ["1->2->5", "1->3"]
 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void binaryTreePaths(TreeNode* root, vector<string>& result, string t){
        
        // leaf node - push_back into result
        if(!root->left && !root->right)
            result.push_back(t);
        
        // if left-child exists, attach the left child value and recurse
        if(root->left)
            binaryTreePaths(root->left, result, t + "->" + to_string(root->left->val));
        
        // if right-child exists, attach the right child value and recurse
        if(root->right)
            binaryTreePaths(root->right, result, t + "->" + to_string(root->right->val));
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> result;
        
        if(root==NULL)
            return result;
        
        binaryTreePaths(root, result, to_string(root->val));
        return result;
    }
};