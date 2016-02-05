#include <iostream>
using namespace std;

// This shows how a struct acts just like a class
// We can use similar contructor types with 
// initalizor lists
// The difference however is that default members
// in a struct are public where as in a class 
// default members are private

struct Node{

	int data;
	struct Node* next;
	Node() : data(0), next(NULL) { cout << "Default Constructor\n";}
	Node(int x) : data(x), next(NULL){ cout << "One Arg Constructor\n"; }
	Node(int x, struct Node* ptr) : data(x), next(ptr) { cout << "Two Args Constructor\n"; }
};

typedef struct Node Node;

int main()
{
	Node* n1 = new Node();
	Node* n2 = new Node(1);
	Node* n3 = new Node(2, n2);

	return 0;

}
