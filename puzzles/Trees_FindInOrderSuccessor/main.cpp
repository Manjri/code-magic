#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
 and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node * minValue(struct node* node);


/* Given a non-empty binary search tree, return the minimum data
 value found in that tree. Note that the entire tree does not need
 to be searched. */
struct node * minValue(struct node* node) {
    struct node* current = node;
    
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

/* Helper function that allocates a new node with the given data and
 NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data   = data;
    node->left   = NULL;
    node->right  = NULL;
    
    return(node);
}

/* Give a binary search tree and a number, inserts a new node with
 the given number in the correct place in the tree. Returns the new
 root pointer which the caller should then use (the standard trick to
 avoid using reference parameters). */
struct node* insert(struct node* node, int data)
{
    /* 1. If the tree is empty, return a new,
     single node */
    if (node == NULL)
        return(newNode(data));
    else
    {
        struct node *temp;
        
        /* 2. Otherwise, recur down the tree */
        if (data <= node->data)
        {
            temp = insert(node->left, data);
            node->left  = temp;
        }
        else
        {
            temp = insert(node->right, data);
            node->right = temp;
        }
        
        /* return the (unchanged) node pointer */
        return node;
    }
}

struct node* inOrderSuccessor(struct node *root, struct node *n)
{
    
    // If right subtree of node is not NULL, then succ lies in right subtree. Do following.
    // Go to right subtree and return the node with minimum key value in right subtree.
    
    if(n->right != NULL)
        return minValue(n->right);
    
    // If right sbtree of node is NULL, then start from root and use search like technique.
    // Travel down the tree, if a node’s data is greater than root’s data then go right side,
    // otherwise go to left side. Record the parent of the left child whose right child is this node
    else
    {
        struct node *succ = NULL;
        
        // Start from root and search for successor down the tree
        while(root != NULL)
        {
            if (n->data < root->data)
            {
                succ = root;
                root = root->left;
            }
            else if(n->data > root->data)
            {
                root = root->right;
            }
            else
                break;
        }
        return succ;
    }
    
}


/* Driver program to test above functions*/
int main()
{
    struct node* root = NULL, *temp, *succ, *min;
    
    //creating the tree given in the above diagram
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;
    
    succ =  inOrderSuccessor(root, temp);
    if(succ !=  NULL)
        printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);
    else
        printf("\n Inorder Successor doesn't exit");
    
    getchar();
    return 0;
}