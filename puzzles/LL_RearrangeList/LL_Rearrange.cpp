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
int initialContents[] = {5,4,3,2,1};

Node* 
reverseList(Node* head)
{
	Node* curr = head;
	Node* prev = NULL;
	Node* next;

	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}


Node* rearrangeList(Node* head){

	// first find the mid-point
	Node* slow = head;
	Node* fast = head->next;

	while(fast){
		fast = fast->next;
		if(fast){
			slow = slow->next;
			fast = fast->next;
		}
	}
	// show where we are...
	cout << "Middle: " << slow->val << endl;

	Node* second= slow->next;
	second = reverseList(second);
	
	// terminate the first half
	slow->next = NULL;
	Node* first = head;

	Node* dummy = (Node*)malloc(sizeof(Node));
	dummy->val = 0;
	dummy->next = NULL;

	Node* curr = dummy;

	while(first || second){
		if(first){
			curr->next = first;
			first = first->next;
			curr = curr->next;
		}
		if(second){
			curr->next = second;
			second = second->next;
			curr = curr->next;
		}
	}
	return dummy->next;
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
	rearrangeList(head);
	printList(head);
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






