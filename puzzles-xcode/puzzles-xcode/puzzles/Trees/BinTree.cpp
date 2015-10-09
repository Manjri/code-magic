#include <iostream>
using namespace std;

class BinTree
{
private:
    class Node
    {
    public:
        int value;
        Node* left;
        Node* right;
    public:
        Node(int v)
        {
            value = v;
            left = NULL;
            right = NULL;
        }
    };
    
    Node* root;

    void recInsert(Node* &r, int x)
    {
        if(r == NULL)
            r = new Node(x);
        else
        {
            if(x <= r->value)
                recInsert(r->left, x);
            else
                recInsert(r->right, x);
        }
    }

    void recDisplay(Node* r)
    {
        if(r != NULL)
        {
            recDisplay(r->left);
            cout << r->value << endl;
            recDisplay(r->right);
        }
    }

    void recPreOrder(Node* r)
    {
        if(r!= NULL)
        {
            cout << r->value <<endl;
            recPreOrder(r->left);
            recPreOrder(r->right);
        }
    }

    void recPostOrder(Node* r)
    {
        if(r!=NULL)
        {
            recPostOrder(r->left);
            recPostOrder(r->right);
            cout << r->value << endl;
        }
    }


    void recInOrder(Node* r)
    {
        if(r!=NULL)
        {
            recInOrder(r->left);
            cout << r->value << endl;
            recInOrder(r->right);
        }
    }

public:

    BinTree()
    {
        root = NULL;
    }

    void insert(int x)
    {
        recInsert(root, x);
    }

    void display()
    {
        recDisplay(root);
    }

    void preOrder()
    {
        recPreOrder(root);
    }

    void postOrder()
    {
        recPostOrder(root);
    }

    void inOrder()
    {
        recInOrder(root);
    }
};


int main()
{
    BinTree tree;
    
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    //tree.display();
    //tree.preOrder();
    //tree.postOrder();
    tree.inOrder();
    return 0;
}