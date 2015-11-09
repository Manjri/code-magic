#include <iostream>
#include <vector>
using namespace std;

// Shows Factor Design Pattern
class Stooge{
    public:
        static Stooge* makeStooge(int choice); // static class function
        virtual void slapStick() = 0; // implemented by derived
        virtual ~Stooge(){}
};

class Larry : public Stooge{
    public:
        void slapStick(){
           cout << "Larry: poke eyes" << endl; 
        }
        
        ~Larry(){}
};

class Moe : public Stooge{
    public:
        void slapStick(){
           cout << "Moe: slap head" << endl; 
        }
        ~Moe(){}
};

class Curly : public Stooge{
    public:
        void slapStick(){
           cout << "Curly: suffer abuse" << endl; 
        }
        ~Curly(){}
};

Stooge* Stooge::makeStooge(int choice){
    switch(choice){
        case 1: return new Larry;
                break;
        case 2: return new Moe;
                break;
        case 3: return new Curly;
                break;
        default:{
                    cout << "Enter valid choice next time!!";
                    return NULL;
                }
    }
}

int main(){
 
    vector<Stooge*> roles;
    int choice;
    
    while(true){
        cout << "Larry(1) Moe(2) Curly(3) Exit(0)" << endl;
        cin >> choice;

        if(choice==0)
            break;
       
        Stooge *s = Stooge::makeStooge(choice);
        
        if(s)
            roles.push_back(s);
    }
    
    for(auto r : roles)
        r->slapStick();

    for(auto x : roles)
        delete x;

    return 0;
}
