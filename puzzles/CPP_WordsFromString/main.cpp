#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void printWordsFromString(string s){
    istringstream iss(s);
    string word;
    while(iss >> word){
        cout << "Word: " << word << endl;
    }
}


int main(){
    string t;
    cout << "Enter a string: " << endl;
    getline(cin, t);
    cout << "String: " << t << endl;
    printWordsFromString(t);
    return 0;
}
