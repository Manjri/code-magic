/*
 ============================================================================
 Name        : LL_ReverseList.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node* next;
}Node;

Node* reverseList(Node* head)
{
	Node* current = head;
	Node* prev = NULL;
	Node* next = head;

	while(next)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

Node* push(Node* head, int val)
{
	Node* n = malloc(sizeof(Node));
	n->val = val;
	n->next = NULL;

	if(head == NULL)
	{
		head = n;
	}
	else
	{
		n->next = head;
		head = n;
	}
	return head;
}

void printLL(Node* head)
{
	Node* n = head;
	while(n)
	{
		printf("%d ",n->val);
		n = n->next;
	}
}


int main(void) {
	Node* head = NULL;
	head = push(head, 1);
	head = push(head, 2);
	head = push(head, 3);
	printLL(head);

	head = reverseList(head);

	printf("\n");

	printLL(head);

	return EXIT_SUCCESS;
}
