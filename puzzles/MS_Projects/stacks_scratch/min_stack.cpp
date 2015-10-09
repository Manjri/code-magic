#include <iostream>
using namespace std;

#define NUM_STACKS 3

class DefaultStack
{
public:
    DefaultStack(unsigned size=100)
    {
        current = -1;
        buf = new int[size];
        this->size = size;
    }

    void push(int value)
    {
        buf[++current] = value;
    }

    int pop()
    {
        return buf[current--];
    }

    int top()
    {
        return buf[current];
    }

    bool isEmpty()
    {
        return (current==-1);
    }

    bool isFull()
    {
        return (current == size-1);
    }   


    ~DefaultStack()
    {
        delete[] buf;
    }

private:
    int *buf;
    int current;
    unsigned size;
};


class MyStackWithMin
{
public:
    void push(int value)
    {
        if(value <= min())
            s2.push(value);

        s1.push(value);
    }

    int pop()
    {
        if(s1.top() == min())
            s2.pop();

        s1.pop();
    }

    int top()
    {
        return s1.top();
    }


    bool isEmpty()
    {
        s1.isEmpty();
    }

    int min()
    {
        if(s2.isEmpty())
            return INT_MAX;

        return s2.top();
    }
private:
    DefaultStack s1,s2; // s1 is the value stack and s2 is the min stack
};


int main()
{

    MyStackWithMin stack;

    stack.push(1);
    cout << stack.top();

    return 0;

}