#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        vector<int> results;
        for(int i=0; i < m+n; i++){
            results.push_back(0);
        }
        
        for(int i=0; i<m;i++){
            int v1=num1[m-1-i] -'0';
            for(int j=0; j <n; j++){
                int v2 = num2[n-1-j] -'0';
                results[i+j] += v1 * v2;
            }
        }
        
        int carry =0;
        for(int i=0; i < m+n; i++){
            int value = results[i] + carry;
            results[i] = value % 10;
            carry = value/10;
        }
        
        string re="";
        bool findNoZero = false;
        for(int i= m+n-1; i >=0; i--){
            if(findNoZero){
                re += (results[i] + '0');
            }else{
                if(results[i] != 0){
                    findNoZero = true;
                    re += (results[i] + '0');
                }
            }
        }
        
        if(re == "")
            re = "0";
        return re;  
    }
};

int main()
{
    Solution s;
    string s1 = "123";
    string s2 = "45";
    cout << s.multiply(s1, s2) << endl;
    
    return 0;
}
