//============================================================================
// Name        : Stacks_MinStack.cpp
// Author      : Nikhil Jagdale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>

using namespace std;

struct Node
{
  int val;
  Node* next;
  Node(int x): val(x), next(NULL) {}
};

class MinStack {

private:
    class defaultStack
    {
    public:
        Node* head;

    public:

      defaultStack()
      {
          head = NULL;
      }

      void pushStack(int x)
      {
          Node* n =new Node(x);

          if(!head)
          {
            head = n;
          }
          else
          {
            n->next = head;
            head = n;
          }
      }

      void popStack()
      {
          if(!head->next)
          {
              delete head;
              head = NULL;
          }
          else
          {
              Node* temp = head;
              head = head->next;
              delete temp;
          }
      }

      int topStack()
      {
            return head->val;
      }

       bool isEmpty()
       {
           return (head == NULL);
       }

    };

    defaultStack s1, s2;

    int getMinVal()
    {
        if(s2.isEmpty())
            return INT_MAX;
        else
            return s2.topStack();
    }

public:
    void push(int x)
    {
        if(x <= getMinVal())
            s2.pushStack(x);

        s1.pushStack(x);

    }

    void pop()
    {
        if(s1.topStack() == getMinVal())
            s2.popStack();

        s1.popStack();
    }

    int top()
    {
        return s1.topStack();
    }

    int getMin()
    {
        return getMinVal();
    }

};

//push(2),push(0),push(3),push(0),getMin,pop,getMin,pop,getMin,pop,getMin


int main()
{
	MinStack m;

	m.push(2);
	m.push(0);
	m.push(3);
	m.push(0);

	cout << "Min: " << m.getMin() << endl;
	cout << "Top: " << m.top() << endl;
	m.pop();
	cout << "Top: " << m.top() << endl;

	cout << "Min: " << m.getMin() << endl;
	m.pop();
	cout << "Top: " << m.top() << endl;

	cout << "Min: " << m.getMin() << endl;
	m.pop();
	cout << "Top: " << m.top() << endl;

	cout << "Min: " << m.getMin() << endl;
	cout << "Top: " << m.top() << endl;
	return 0;
}

