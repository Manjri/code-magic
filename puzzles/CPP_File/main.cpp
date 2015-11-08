#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeToFile(){
    ofstream myfile("example.txt");
    
    if(myfile.is_open()){
        myfile << "This is dummy example\nThis is is a dummy line\n";
        myfile.close();
        cout << "File contents written" << endl;
    }
    else
        cout << "File Error" << endl;
}

void readFromFile(){
    ifstream myfile("example.txt");
    string line;

    if(myfile.is_open()){
        
        while(getline(myfile, line)){
            cout << line << endl;
        }
        myfile.close();
    }
    else
        cout << "File Error" << endl;
}

int main(){
    readFromFile();
    return 0;
}

