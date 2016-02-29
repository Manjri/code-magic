#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Dog{

    string name_;

    public:
        Dog(string name){
            cout << "Dog is created: " << name << endl;
            name_ = name;
        }
        Dog(){
            cout << "Nameless dog created: " << endl;
            name_ = "nameless";
        }
        ~Dog(){
            cout << "Dog is destroyed: " << name_ << endl;
        }
        void bark(){
            cout << "Dog " << name_ << " rules!" << endl;
        }
};

void foo(){
    shared_ptr<Dog> p(new Dog("Gunner"));   //count = 1
    {
        shared_ptr<Dog> p2 = p;    //count = 2
        cout << p.use_count() << endl;
    }
    cout << p.use_count() << endl;
    // count = 1       
    p->bark();
}// count =0

int main(){
    //foo();
    
    // a different way to create a smart pointer
    shared_ptr<Dog> p = make_shared<Dog>("Tank");   // faster & safer
    (*p).bark();

    return 0;
}
