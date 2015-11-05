//============================================================================
// Name        : BinaryTrees.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class BST
{
private:
    class Node
    {
    public:
        int key;
        Node* left;
        Node* right;
        
        Node(int data)
        {
            key = data;
            left = NULL;
            right = NULL;
        }
    };
    
    Node* root;
    
    void BinTreeInsert(Node* &rec, int val)
    {
        if(rec==NULL)
        {
            rec = new Node(val);
        }
        else
        {
            if(val <= rec->key)
                BinTreeInsert(rec->left, val);
            else
                BinTreeInsert(rec->right, val);
        }
    }
    void BinTreeInOrder(Node* rec)
    {
        if(rec)
        {
            BinTreeInOrder(rec->left);
            cout << rec->key << endl;
            BinTreeInOrder(rec->right);
        }
    }
    
    void BinTreeReverseOrder(Node *rec){
        if(rec){
            BinTreeReverseOrder(rec->right);
            cout << rec->key << endl;
            BinTreeReverseOrder(rec->left);
        }
    }
    
    void BinTreePreOrder(Node* rec)
    {
        if(rec)
        {
            cout << rec->key << endl;
            BinTreePreOrder(rec->left);
            BinTreePreOrder(rec->right);
        }
    }
    void BinTreePostOrder(Node* rec)
    {
        if(rec)
        {
            BinTreePostOrder(rec->left);
            BinTreePostOrder(rec->right);
            cout << rec->key << endl;
        }
    }
    void BinTreeSearch(Node* rec, int val)
    {
        if(rec)
        {
            if(rec->key == val)
            {
                cout << "\nFound " << val << endl;
                return;
            }
            else
            {
                if(val < rec->key)
                    BinTreeSearch(rec->left, val);
                else
                    BinTreeSearch(rec->right, val);
            }
        }
        else
            cout << "Not Found "<< val << endl;
    }
    void BinTreeDestroy(Node* leaf)
    {
        if(leaf)
        {
            BinTreeDestroy(leaf->left);
            BinTreeDestroy(leaf->right);
            delete leaf;
        }
    }
    
    Node* findMin(Node* root)
    {
        if(root == NULL)
            return root;
        
        while(root->left)
            root = root->left;
        
        return root;
    }
    
    Node* BinTreeSearchAndDelete(Node* root, int data)
    {
        
        if(root == NULL)
            return root;
        
        else if(data < root->key)
            root->left = BinTreeSearchAndDelete(root->left, data);
        
        else if(data > root->key)
            root->right = BinTreeSearchAndDelete(root->right, data);
        
        else // found the node to be deleted
        {
            //Case 1: no child
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            // Case 2: 1 child
            else if(root->left == NULL)
            {
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL)
            {
                Node* temp = root;
                root =  root->left;
                delete temp;
            }
            // Case 3: 2 children
            else
            {
                Node* temp = findMin(root->right);
                root->key = temp->key;
                root->right = BinTreeSearchAndDelete(root->right,temp->key);
            }
        }
        return root;
    }
    
public:
    BST()
    {
        root = NULL;
    }
    void insert(int key)
    {
        BinTreeInsert(root, key);
    }
    void search(int key)
    {
        BinTreeSearch(root, key);
    }
    void preOrder()
    {
        BinTreePreOrder(root);
    }
    void postOrder()
    {
        BinTreePostOrder(root);
    }
    void inOrder()
    {
        BinTreeInOrder(root);
    }
    // opposite order of inOrder()
    void reverseOrder(){
        BinTreeReverseOrder(root);
    }
    
    void deleteTree()
    {
        BinTreeDestroy(root);
        root = NULL;
    }
    void searchAndDelete(int data)
    {
        root = BinTreeSearchAndDelete(root, data);
    }
    ~BST()
    {
        BinTreeDestroy(root);
    }
};




int main()
{
    BST myBST;
    
    myBST.insert(4);
    myBST.insert(2);
    myBST.insert(1);
    myBST.insert(3);
    myBST.insert(6);
    myBST.insert(5);
    myBST.insert(7);
    
    cout << "InOrder Traversal: " << endl;
    myBST.inOrder();
    cout << "Reverse Traversal: " << endl;
    myBST.reverseOrder();
    
    return 0;
}
