#include <iostream>
#include <queue>

using namespace std;

void printLevelOrder(BinaryTree *root)
{
    if (!root)
        return;
    
    queue<BinaryTree*> nodesQueue;
    
    int nodesInCurrentLevel = 1;
    int nodesInNextLevel = 0;
    
    nodesQueue.push(root);
    
    while (!nodesQueue.empty())
    {
        BinaryTree *currNode = nodesQueue.front();
        nodesQueue.pop();
        nodesInCurrentLevel--;
        
        cout << currNode->data << " ";
        
        if(currNode->left)
        {
            nodesQueue.push(currNode->left);
            nodesInCurrentLevel++;
        }
        if(currNode->right)
        {
            nodesQueue.push(currNode->right);
            nodesInNextLevel++;
        }
        if (nodesInCurrentLevel == 0)
        {
            cout << endl;       // newline for next level
            nodesInCurrentLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
        }
    }
}