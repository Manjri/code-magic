//============================================================================
// Name        : BinaryTrees.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <stack>
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
	void BinTreePreOrder(Node* rec)
	{
		if(rec)
		{
			cout << rec->key << endl;
			BinTreePreOrder(rec->left);
			BinTreePreOrder(rec->right);
		}
	}
    void BinTreeReverseOrder(Node *rec){
        if(rec){
            BinTreeReverseOrder(rec->right);
            cout << rec->key << endl;
            BinTreeReverseOrder(rec->left);
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

	void BinTreeLevelOrder(Node *root)
	{
		if(root){
			// print root first!
			cout << root->key;
			cout << "\n";
			queue<Node*> q;
			int oldLevel = 0;
			int newLevel = 0;
			// insert into queue for the level
			// L,R
			if(root->left){
				q.push(root->left);		
				oldLevel++;
			}
			if(root->right){
				q.push(root->right);	
				oldLevel++;
			}
			while(!q.empty()){
				Node *n = q.front();
				
				if(n->left){
					q.push(n->left);
					newLevel++;
				}
		
				if(n->right){
					q.push(n->right);
					newLevel++;
				}
	
				cout << n->key << " ";
				q.pop();
				oldLevel--;
			
				if(oldLevel == 0){
						oldLevel = newLevel;
						newLevel = 0;
						cout << "\n";
				}
			}// while q non-empty

		}
	}

void BinTreeZigZag(Node *root)
{

		if(root){
			// print root first!
			cout << root->key;
			cout << "\n";
			queue<Node*> q;
			int oldLevel = 0;
			int newLevel = 0;
			int dir = 1;
			bool reversed = false;
			// insert into queue for the level
			// L,R
			if(root->left){
				q.push(root->left);		
				oldLevel++;
			}
			if(root->right){
				q.push(root->right);	
				oldLevel++;
			}
			while(!q.empty()){
				Node *n = q.front();
				
				if(!reversed){
					if(n->left){
						q.push(n->left);
						newLevel++;
					}
		
					if(n->right){
						q.push(n->right);
						newLevel++;
					}
				}else{
					if(n->right){
						q.push(n->right);
						newLevel++;
					}
		
					if(n->left){
						q.push(n->left);
						newLevel++;
					}
				}
				cout << n->key << " ";
				q.pop();
				oldLevel--;
			
				if(oldLevel == 0){
						oldLevel = newLevel;
						newLevel = 0;
						//cout << "\n";
						// reverse the order inside the queue
						// to do that we can put it inside the stack and pull out
						stack<Node*> s;
						while(!q.empty()){
							s.push(q.front());
							//cout << (q.front())->key << " ";
							q.pop();
						}
						//cout << "\n";
						//cout << "After reversing ..\n";
						while(!s.empty()){
							q.push(s.top());
							//cout << (s.top())->key << " ";
							s.pop();
						}
					  cout << "\n";		
						// flip the direction
						reversed = true;
				}
			}// while q non-empty

		}
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

	void printLevelOrder()
	{
		BinTreeLevelOrder(root);
	}

	void printZigZagOrder()
	{
		BinTreeZigZag(root);
	}

	~BST()
	{
		BinTreeDestroy(root);
	}
};




int main()
{
	BST myBST;

    myBST.insert(90);
    myBST.insert(50);
    myBST.insert(150);
    myBST.insert(20);
    myBST.insert(75);
    myBST.insert(95);
    myBST.insert(175);
    myBST.insert(5);
    myBST.insert(25);
    myBST.insert(66);
    myBST.insert(80);
    myBST.insert(92);
    myBST.insert(111);
    myBST.insert(166);
    myBST.insert(200);



#if 0
	myBST.inOrder();
	myBST.preOrder();
	myBST.postOrder();

	myBST.search(4);
	myBST.search(100);

	myBST.deleteTree();

	myBST.inOrder();

	cout << "End of Operations!!" << endl; // prints
#endif

	myBST.printLevelOrder();
	cout << "Now Zig-Zag" << "\n\n";
	myBST.printZigZagOrder();
	return 0;
}
