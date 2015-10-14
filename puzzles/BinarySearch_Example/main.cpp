#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int BinSearch(vector<int> v, int x) {
        
        int low = 0;
        int high = v.size()-1;
        int mid;
        
        while(low < high){
            
            mid = (low+high)/2;
            
            if(v[mid] < x){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return v[low] == x ? low : -1;
    }
};

int main(){
    Solution s;
    vector<int> vec = {1,2,3,4,5,6};
    cout << s.BinSearch(vec,6) << endl;
    return 0;
}