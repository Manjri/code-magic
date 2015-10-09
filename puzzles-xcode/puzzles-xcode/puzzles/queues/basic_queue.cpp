#include <iostream>
using namespace std;

class Node{

public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue{

public:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int d)
    {
        if(front==NULL)
        {
            Node* n = new Node(d);
            front  = rear = n;
        }
        else
        {
            Node* n = new Node(d);
            rear->next = n;
            rear = n;
        }
    }

    int dequeue()
    {
        if(front==NULL)
            exit(1);

        else if(front==rear)
        {
            int temp = front->data;
            delete(front);
            front = rear = NULL;
            return temp;
        }
        else
        {
            int temp = front->data;
            Node* next = front->next;
            delete(front);
            front = next;
            return temp;
        }

    }

};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);

    cout << "Dequeuing once.. " << q.dequeue() << endl;
    cout << "Dequeuing twice.. " << q.dequeue() << endl;
    cout << "Dequeuing thrice.. " << q.dequeue() << endl;
    return 0;
}