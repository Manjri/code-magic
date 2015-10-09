#include <iostream>
using namespace std;

class BinSearchTree
{
private:
    class Node
    {
    public:

        int data;
        Node* right;
        Node* left;
    
        Node(int x)
        {
            data = x;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    void recInsert(Node* &r, int x)
    {
        if (r == NULL)
        {
            r = new Node(x);
        }
        else
        {
            if( x < r->data )
                return recInsert(r->left, x);

            else
                return recInsert(r->right, x);
        }
    }

    void recDisplay(Node* r)
    {
        if(r != NULL)
        {
            recDisplay(r->left);
            cout << r->data << endl;
            recDisplay(r->right);
        }

    }

public:
    BinSearchTree()
    {
        root  = NULL;
    }

    void insert(int x)
    {
        recInsert(root, x);
    }

    void display()
    {
        recDisplay(root);
    }
};



int main()
{
    BinSearchTree tree;

    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);

    tree.insert(5);
    tree.insert(0);

    tree.display();

    return 0;
}