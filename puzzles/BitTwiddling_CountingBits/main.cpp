/**
Given a non negative integer number num. For every numbers i 
in the range 0 ≤ i ≤ num calculate the number of 1's in their
binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2]
*/
#include <iostream>
#include <vector>
using namespace std;

//#define __debug

class Solution{

public:
    vector<int> countBits(int num){
    
        vector<int> result = vector<int>(num+1);
        int count_max = 1;
        int count = 0;
        result[0] = 0;

        for(int i=1; i<=num; i++){
            result[i] = result[count]+1;

            #ifdef __debug
            cout << "i:" << i << " count: " 
                << count << " count_max: " << count_max << endl;
            #endif
            count++;

            if(count == count_max){
                count_max *= 2;
                count = 0;
            }
        }        
        return result;    
    }
};

int main(){

    Solution s;
    int num = 4;
    vector<int> result = s.countBits(num);
    
    cout << "For number: " << num << endl; 

    for(auto i : result)
        cout << i << " ";
    
    cout << endl; 
    return 0;
}
