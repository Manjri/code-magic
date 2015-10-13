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
    
    void levelOrderBottom(TreeNode* root, vector<vector<int>>& v, int level){
        if(root == NULL)
            return;
        
        if(v.empty() || (level >  v.size()-1)){
            v.push_back(vector<int>());                 // add a new level
        }
        
        v[level].push_back(root->val);                  // insert root-val first
        
        levelOrderBottom(root->left, v, level+1);       // recurse for children - at next level
        levelOrderBottom(root->right, v, level+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderBottom(root, result, 0);
        return vector<vector<int>>(result.rbegin(), result.rend());
    }
};