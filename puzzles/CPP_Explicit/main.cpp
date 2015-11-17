#include <iostream>
using namespace std;

class A{
    public:
        explicit A(int x = 0, bool b = true) : val(x), flag(b){}
        ~A() {}

        int getX() const{
            return val;
        }

    private:
        int val;
        bool flag;  
};

void doSomething(const A& aObject){
    cout << aObject.getX() << endl;
}

int main(){
    A aObj1;
    doSomething(aObj1);
    doSomething(A(28));
    return 0;
}
