#include <iostream>
#include <deque>
using namespace std;

struct BTree
{
    int data;
    struct BTree* left;
    struct BTree* right;
};

void buildTree()
{

    struct BTree* root;
    root->data  = 1;
    root->left = NULL;
    root->right = NULL;
}


int main()
{
    deque<BTree *> q;
    


    return 0;
}