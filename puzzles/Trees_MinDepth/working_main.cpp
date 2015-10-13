#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
    
        bool flag = false;
        queue<TreeNode*> Q;
        Q.push(root);
        int i = 0;
        while (Q.size()!=0) {
            i++;
            int k = Q.size();
            for (int j=0; j<k; j++) {
                TreeNode* rt = Q.front();
                if (rt->left) Q.push(rt->left);
                if (rt->right) Q.push(rt->right);
                Q.pop();
                if (rt->left==NULL && rt->right==NULL){ // leaf node reached, just return the level
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        return i;
    }
    
    
};

