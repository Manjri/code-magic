/**
 * Partition a linkedlist around a value x
 * such that all nodes less than x come
 * before all nodes greater than or equal to x
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Node
{
	int val;
	struct Node* next;
}Node;

// forward declerations of functions
Node* createNode(int v);
void printList(Node* head);
void freeList(Node* head);

// initial contents of the list
int initialContents[] = {0,6,2,7,1,4,5,-1};

Node* partitionList(Node* head, int value);


Node*
partitionList(Node* head, int value)
{

// Create 2 additional lists 'beforeList' & 
// 'afterList' and insert nodes into them
// while travering the given list.
// When you reach the end of the given list
// merge the before and after list

	Node* beforeList, *afterList;
	Node* curr = head;
	Node* start = beforeList;

	beforeList = NULL;
	afterList = NULL;

	while(curr){

		Node* temp = curr->next;

		if(curr->val < value){
			curr->next = beforeList;
			beforeList = curr;	
		
		}else{
			curr->next = afterList;
			afterList = curr;
		}

		curr = temp;

	}

	if(beforeList == NULL)
		return afterList;
	
	// Find the end of the beforeList and then merge the 2 lists
	Node* tempNode = beforeList;

	while(tempNode->next)
		tempNode = tempNode->next;
	
	tempNode->next = afterList;
	
	return beforeList;

}

int 
main()
{
	Node* head = NULL;
	Node* curr;
	
	// Put initial values in list. Will insert in reverse order
	for(int i=0; i<sizeof(initialContents)/sizeof(int); i++){
		curr = createNode(initialContents[i]);
		curr->next=head;
		head = curr;
	}

	printList(head);	
	Node* pList = partitionList(head, 3);
	printList(pList);
	freeList(head);
	return 0;
}

Node* 
createNode(int v)
{
	Node* n = (Node*) malloc(sizeof(Node));
	n->val = v;
	n->next = NULL;
	return n;
}

void
printList(Node* head){

	Node* curr = head;
	
	while(curr){
		cout << curr->val << "->";
		curr = curr->next;
	}
	
	cout << "NULL"<< endl;
}

void
freeList(Node* head)
{
	Node* curr = head;
	Node* next;
	while(curr){
		next = curr->next;
		free(curr);
		curr = next;
	}
}






