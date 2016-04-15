#include <stdio.h>

typedef struct TreeNode{
    int                 val;
    struct TreeNode*    left;
    struct TreeNode*    right;
}TreeNode; 

// modifies the original tree!
// works from leaf to root
// DFS recursion
void mirrorTree(TreeNode* root){

    // Do DFS
    if(root){
        
        mirrorTree(root->left);
        mirrorTree(root->right);
        // swap the left and right
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

// no way to test this yet
// add code to make a tree
// In order traversal
int main(){
    return 0;
}
