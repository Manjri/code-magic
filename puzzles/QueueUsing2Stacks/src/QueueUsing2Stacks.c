/*
 ============================================================================
 Name        : QueueUsing2Stacks.c
 Author      : Nikhil Jagdale
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct sNode
{
	int data;
	struct sNode* next;
}sNode;

typedef struct queue
{
	struct sNode* stack1;
	struct sNode* stack2;
}queue;

void push(sNode** head, int data)
{
	sNode* n;
	n = malloc(sizeof(sNode));

	if(!n)
	{
		printf("\n Stack Overflow!");
		exit(0);
	}
	else
	{
		n->data = data;
		n->next = *head;
	}
	*head = n;
}

int pop(sNode** head)
{
	if(!(*head))
	{
		printf("\nError .. pop from empty stack");
		exit(0);
		return 0;
	}
	else
	{
		sNode* top = *head;
		int data = top->data;
		*head = top->next;
		free(top);
		return data;
	}
}

void enqueue(queue* head, int data)
{
	// enqueue into stack always
	push(&head->stack1, data);
}

int dequeue(queue* head)
{
	// if stack 2 is non-empty pop from stack 2
	if(!head->stack1 && !head->stack2)
	{
		printf("\nQ empty");
		exit(0);
	}
	if(!head->stack2)
	{
		while(head->stack1)
		{
			push(&head->stack2, pop(&head->stack1));
		}
	}
	return pop(&head->stack2);
}

int main(void)
{
   /* Create a queue with items 1 2 3*/
   queue *q = malloc(sizeof(queue));
   q->stack1 = NULL;
   q->stack2 = NULL;

   enqueue(q, 1);
   enqueue(q, 2);
   enqueue(q, 3);

   /* Dequeue items */
   printf("%d  ", dequeue(q));
   printf("%d  ", dequeue(q));
   printf("%d  ", dequeue(q));

   //getchar();

	puts(""); /* prints  */
	return EXIT_SUCCESS;
}
