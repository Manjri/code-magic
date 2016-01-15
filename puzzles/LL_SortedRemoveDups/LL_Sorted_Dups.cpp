#include <iostream>
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
Node* removeDupsSorted(Node* head);

// initial contents of the list
int initialContents[] = {8,8,8,7,7,6,5,4,4,3,2,2,1,};

Node* 
removeDupsSorted(Node* head)
{
	Node* curr = head;

	if(!curr)
		return curr;
	
	while(curr->next){
		if(curr->val == curr->next->val){
			Node* next_next = curr->next->next;
			free(curr->next);
			curr->next = next_next; // do not advance here as there maybe >1 dups
		}else{
			// tricky!! only advance if there is no deletion
			curr = curr->next;		
		}
	}

	return head;
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
	removeDupsSorted(head);
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






