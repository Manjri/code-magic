#include <iostream>
#include <map>
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
Node* removeDupsUnsorted(Node* head);

// initial contents of the list
int initialContents[] = {3,8,8,2,5,1,9};

Node* 
removeDupsUnsorted(Node* head)
{
	map<int, int> listMap;
	Node* curr = head;
	Node* n = NULL;
	while(curr){
		if(listMap.find(curr->val)!=listMap.end()){
			// it exists so skip it
			n->next = curr->next;
		}else{
			// doesnt exists, add it to the map
			listMap[curr->val] = 1;
			n = curr;	
		}
		curr = curr->next;
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
	removeDupsUnsorted(head);
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






