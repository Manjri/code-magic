#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        int c = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        string s = "";
        
        while(i>=0 || j>=0 || c==1)
        {
            // get the sum of the 2 positions and prev carry
            c += i>=0 ? (a[i--]  - '0'): 0; // ternary takes into account shorter string and gives a 0
            c += j>=0 ? (b[j--] - '0'): 0;
            
            // get the digit, convert to ascii and append on left
            s = char((c % 2) + '0') + s;
            
            // get the carry
            c = c/2;
        }
        return s;
    }
};