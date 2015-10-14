#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        
        int low = 0;
        int high = x;
        int mid;
        
        if(x < 2)
            return x;
        
        while(low < high){
            
            mid = (low+high)/2;
            
            // x > mid*mid
            if(x/mid > mid){
                low = mid+1;
            }
            // x <= mid*mid;
            else{
                high = mid;
            }
        }
        return low > x/low ? low-1: low;
    }
};

int main(){
    Solution s;
    cout << s.mySqrt(9) << endl;
    return 0;
}