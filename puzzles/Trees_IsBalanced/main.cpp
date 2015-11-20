/**
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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

private:
    int checkHeight(TreeNode* root){
        
        if(root == NULL)
            return 0;       // coming from a leaf
        
        int leftHeight = checkHeight(root->left);
        
        if(leftHeight == -1)    // unbalanced
            return -1;

        int rightHeight = checkHeight(root->right);
        
        if(rightHeight == -1)   // unbalanced
            return -1;        
        
        int heightDiff = abs(rightHeight - leftHeight);
        
        if(heightDiff > 1)  // unbalanced
            return -1;
        else
            return max(leftHeight, rightHeight)+1;    
    }        
    
public:
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
            return true;
        else
            return checkHeight(root)==-1?false:true;
    }
};
