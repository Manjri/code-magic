#include <iostream>
#include <unordered_set>

using namespace std;

int findLongestSeq(int *arr, int n){

    unordered_set<int> s;
    int ans = 0;

    for(int i=0; i<n; i++)
        s.insert(arr[i]);

    // check for each possible sequence
    // update the longest length
    for(int i=0; i<n; i++){

        // if current element is starting of
        // sequence
        if(s.find(arr[i]-1) == s.end()){
            
            int j = arr[i];
            while(s.find(j) != s.end()){
                j++;
            }
            ans = max(ans, j-arr[i]); 
        }
    }
    return ans;
}

int main(){
   int arr[] =  {1, 9, 3, 10, 4, 20, 2};
   int n = sizeof arr/ sizeof arr[0];
   cout << "Length of the Longest contiguous subsequence is "
            << findLongestSeq(arr, n) << endl;
   return 0;
}
