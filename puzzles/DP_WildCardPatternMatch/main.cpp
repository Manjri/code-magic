/**
Pattern: x?y*z
String : xaylmz

? - represents any chars at this position
* - represents 0 or more chars at this position

We will follow a bottom-up approach is solving this using
Dynamic Programming


1. Assume the string & pattern is in char array form
2. Ensure consecutive '*'s in pattern are reduced to a single '*'
3. Form a 2-D boolean array 'T' of [string.length()][pattern.length()], init to false
4. Init T[0][0] to true and T[0][1] to true iff pattern[1] == '*' and pattern.length > 1
5. Using 2 nested for loops, scan every ith element of string and jth element of pattern
   and update the table T[i][j] using the following conditions:

        a) if(s[i-1] == p[j-1] || p[j-1] == '?')  
            T[i][j] = T[i-1][j-1];  
        b) else if(p[j-1] == '*')
            T[i][j] = T[i-1][j] | T[i][j-1];
        c) else // meaning s[i-1] != p[j-1] && p[j-1] != '*" && p[j-1] != '?'
            T[i][j] = false;
*/

#include <iostream>
#include <string>
using namespace std;

bool patternMatch(string s, string p){

// 1: is true in C++

// 2:
    int writeIndex = 0;
    bool isTrue = true;
    
    for(int i = 0; i<p.length(); i++){
        if(p[i] == '*'){
            if(isTrue){
                p[writeIndex++] = p[i];
                isTrue=false;
            }
        }else{
            p[writeIndex++] = p[i];
            isTrue = true;
        }      
    }
    string p1 = p.substr(0,writeIndex); 
  
    // Debug: Print the pattern
    cout << "Pattern is " << p1 << endl;

// 3:
    bool T[s.length()+1][p1.length()+1];
    memset(T, 0, sizeof(bool)*(s.length()+1)*(p1.length()+1));    
    
// 4:
    T[0][0] = true;

    if((p1[0]=='*') && p1.length()>0)
        T[0][1] = true;

// 5:
    for(int i=1; i<=s.length(); i++){
        for(int j=1; j<=p1.length(); j++){
            if((s[i-1] == p1[j-1]) || p1[j-1]=='?')
                T[i][j] = T[i-1][j-1];
            else if(p1[j-1] == '*')
                T[i][j] = T[i-1][j] | T[i][j-1];
            else
                T[i][j] = false;
        } 
    }  

// Debug: print the array
    for(int i=0; i<=s.length(); i++){
        for(int j=0; j<=p1.length(); j++)
            cout << T[i][j] << " ";
        cout << endl;
    }

    return T[s.length()][p1.length()];
}

int main(){

    string  s = "xaylmz";    
    string  p = "x?y******z";

    if(patternMatch(s, p) == true)
        cout << "String matches pattern" << endl;
    else
        cout << "String does not matches pattern" << endl;
    
    return 0;
}

