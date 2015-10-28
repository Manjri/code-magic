#include <iostream>
#include "assert.h"
using namespace std;

// using linkedlists

typedef struct Node{
    int data;
    struct Node* next;
    Node(int x) : data(x), next(NULL){}
}Node;

class MyStack{
    
private:
    Node *head, *current;
    int count;

public:
    
    MyStack(){
        count = 0;
        head = current = NULL;
    }
    
    void push(int x){
        Node *n = new Node(x);
        
        if(!head){
            current = head = n;
        }
        else{
            current->next = n;
            current = current->next;
        }
    }
    
    bool top(int& result){
        
        if(!head){
            cout << "Stack Empty!" << endl;
            return false;
        }
        else{
            result = current->data;
            return true;
        }
    }
    
    bool pop(){
        if(!head){
            cout << "Stack Empty! " << endl;
            return false;
        }
        else if(head == current){
            free(current);
            head = current = NULL;
            return true;
        }
        else
        {
            Node *prev = head;
            for(;prev && prev->next !=current; prev=prev->next){
                
            }
            free(current);
            prev->next = NULL;
            current = prev;
            return true;
        }
    }
    
};



#if 0
// using arrays
class MyStack{
    
private:
    int *data;
    int count;
    int size;
    
public:
    MyStack(int n){
        size = n;
        data = new int(size);
        count = -1;
    }
    
    bool push(int x){
        if(count < size-1){
            data[++count] = x;
            return true;
        }
        else{
            cout << "\nStack Full" << endl;
            return false;
        }
    }
    
    bool top(int& result){
        if(count >=0){
            result = data[count];
            return true;
        }
        else{
            cout << "\nStack Empty" << endl;
            return false;
        }
    }
    
    bool pop(){
        if(count >=0){
            count--;
            return true;
        }
        else{
            cout << "\nStack Empty" << endl;
            return false;
        }
    }
};
#endif

int main(){

// test for LL-implemenation
    MyStack ms;
    int result;
    
    assert(ms.pop()==false);
    
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);
    for(int i=0; i<5; i++){
        ms.top(result);
        ms.pop();
        cout << result << " ";
    }
    cout << endl;
    
    ms.push(6);
    ms.top(result);
    cout << result << " ";
    ms.pop();
    
    assert(ms.pop()==false);
    
#if 0
// test for array-implementation
    MyStack ms(5);
    int result;
    
    assert(ms.pop()==false);
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    assert(ms.push(5) == true);
    assert(ms.push(6) == false);
    for(int i=0; i<5; i++){
        ms.top(result);
        ms.pop();
        cout << result << " ";
    }
    cout << endl;
#endif
    return 0;
}