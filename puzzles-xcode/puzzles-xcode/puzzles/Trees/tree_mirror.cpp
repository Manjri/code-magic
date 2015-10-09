#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* InsertNode(Node *root, int data)
{

    if(root == NULL)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else
    {
        if(data <= root->data)
            root->left = InsertNode(root->left, data);
        else
            root->right = InsertNode(root->right, data);
    }

    return root;
}

void doubleTree(Node* node)
{
    //base case
    if(node == NULL)
        return;

    doubleTree(node->left);
    doubleTree(node->right);

    Node* temp = node->left;
    node->left = (Node*)malloc(sizeof(Node));
    node->left->data = node->data;
    node->left->left = temp;
    node->left->right = NULL;
    

}

int main()
{
    Node* root = NULL;
    root = InsertNode(root, 2);
    root = InsertNode(root, 1);
    root = InsertNode(root, 3);
    
    doubleTree(root);
    
    return 0;
}