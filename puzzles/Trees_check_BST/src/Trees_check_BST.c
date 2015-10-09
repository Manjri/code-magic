/*
 ============================================================================
 Name        : Trees_check_BST.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
}Node;

/************* FASTER VERSION ***************************************************/
int checkBSTRecurs(Node* n, int min, int max)
{
	if(n == NULL)
		return TRUE;

	if(n->key < min || n->key > max)
		return FALSE;

	return
		checkBSTRecurs(n->left, min, n->key) &&
		checkBSTRecurs(n->right, n->key+1, max);
}


int checkBST(Node* n)
{
	return checkBSTRecurs(n, INT_MIN, INT_MAX);
}

/*************** SLOWER VERSION ***************************************************/

int minOfBST(Node* n)
{
	Node* current = n;

	while(current->left)
		current = current->left;

	return current->key;
}

int maxOfBST(Node* n)
{
	Node* current = n;

	while(current->right)
		current = current->right;

	return current->key;
}

int checkBST2(Node* n)
{
	if(n == NULL)
		return TRUE;

	if(n->left && n->key < maxOfBST(n->left))
		return FALSE;

	if (n->right && n->key >= minOfBST(n->right))
		return FALSE;

	if(!checkBST2(n->left) || !checkBST2(n->right))
		return FALSE;

	return TRUE;
}


int main(void) {
	puts(""); /* prints  */
	return EXIT_SUCCESS;
}
