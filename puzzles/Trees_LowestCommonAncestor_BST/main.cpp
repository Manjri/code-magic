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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // either p/q is the root or p and q lie on opp sides of root
        if((root == p) || (root == q) || (p->val > root->val && q->val < root->val)
           || (q->val > root->val && p->val < root->val))
            return root;
        
        // recurse on right subtree
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        // recurse on left subtree
        else
            return lowestCommonAncestor(root->left, p, q);
        
    }
};