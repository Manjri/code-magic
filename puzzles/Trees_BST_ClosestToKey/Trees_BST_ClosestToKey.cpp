//============================================================================
// Name        : Trees_BST_ClosestToKey.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



//Given a non-empty BST, each node has a double.
//Given a search key double k.  Find the node in the tree that is closest to k.

/**
 * 1. Look at L & R of root
 * 2. Pick the child whose diff is least from k
 * 3. If this difference is less than minimum, update minimum
 * 4.
 *
 */


#include <iostream>
#include <cmath>
using namespace std;

class BST
{
private:
	class Node
	{
	public:
		double key;
		Node* left;
		Node* right;

		Node(double data)
		{
			key = data;
			left = NULL;
			right = NULL;
		}
	};

	Node* root;

	void BinTreeInsert(Node* &rec, double val)
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
	void BinTreeSearch(Node* rec, double val)
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

	Node* closestNodeBST(Node* root, double val)
	{

		if(root == NULL)
			return NULL;

		if(root->key == val)
	        return root;

	    if(val < root->key)
	    {
	        if(!root->left)
	            return root;
	        Node* p = closestNodeBST(root->left, val);
	        return abs(p->key - val) > abs(root->key - val) ? root : p;
	    }
	    else
	    {
	        if(!root->right)
	            return root;
	        Node* p = closestNodeBST(root->right, val);
	        return abs(p->key - val) > abs(root->key - val) ? root : p;
	    }
	}

public:
	BST()
	{
		root = NULL;
	}
	void insert(double key)
	{
		BinTreeInsert(root, key);
	}
	void search(double key)
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
	void deleteTree()
	{
		BinTreeDestroy(root);
		root = NULL;
	}

	double closestBST(double val)
	{
		if(root == NULL)
			return (double)NULL;
		else
		{
			Node* n = closestNodeBST(root, val);
			return n->key;
		}
	}


	~BST()
	{
		BinTreeDestroy(root);
	}
};



int main() {
	BST tree;
	tree.insert(8);
	tree.insert(4);
	tree.insert(12);
	tree.insert(2);
	tree.insert(7);
	tree.insert(11);
	tree.insert(14);

    /**
      8
    4    12
   2 7  11 14
     
     
     */
    
	//tree.inOrder();
	cout << tree.closestBST(9.7) << endl;

	cout << "" << endl; // prints 
	return 0;
}
