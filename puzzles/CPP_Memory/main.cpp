#include <iostream>
using namespace std;

class Base{
    public:
        Base();
        virtual void foo();
};

class Derived : public Base{
    public:
        Derived();
        void foo();
        void bar();
    private:
        int i,j;
};

Base::Base(){
}

void Base::foo(){
    cout << "Base:Foo()"<< endl;
}

Derived::Derived(){
    i = 5;
    j = 10;
}

void Derived::bar(){
    cout << "Bar:Derived()" << endl;
}


void Derived::foo(){
    cout << "Derived:Foo()"<< endl;
}

int main(){
    Base b;
    Derived d;
    return 0;
}
