#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    string s = "123 456 789";
    istringstream iss(s);
    
    for(int i=0; i<3; i++){
        int val;
        iss >> val;
        cout << (val*2) << endl;
    }
    return 0;
}
