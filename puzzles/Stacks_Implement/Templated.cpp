#include <iostream>
#include <vector>
#include "assert.h"
using namespace std;

// using vector
template <class T>
class MyStack{
    
private:
    vector<T> *data;
    int count;
    int size;
    
public:
    MyStack(int n){
        size = n;
        data = new vector<T>;
        count = -1;
    }
    
    bool push(T x){
        if(count < size-1){
            data->push_back(x);
            count++;
            return true;
        }
        else{
            cout << "\nStack Full" << endl;
            return false;
        }
    }
    
    bool top(T &result){
        if(count >=0){
            result = data->back();
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
            data->pop_back();
            return true;
        }
        else{
            cout << "\nStack Empty" << endl;
            return false;
        }
    }
};


int main(){
    
    // test for vector-implementation
    MyStack<int> ms(5);
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

    return 0;
}