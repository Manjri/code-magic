/**
 Given an array of integers and a target number, find the two elements 
 whose sum is closest to the target number.
 */

#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

pair<int,int> findClosest(int arr[], int len, int sum)
{
    pair<int, int> ans;;
    
    sort(arr, arr+len);
    int i = 0;
    int j = len -1;
    unsigned nearest = UINT_MAX;
    unsigned absDiff = UINT_MAX;
    
    
    while( i < j){
        while((arr[i] + arr[j]) <= sum && i < j)
        {
            absDiff = abs(sum -(arr[i] + arr[j]));

            if(absDiff < nearest){
                ans.first = arr[i];
                ans.second = arr[j];
                nearest = absDiff;
            }
            
            if(absDiff == 0){
                return ans;
            }
            i++;
        }

        while((arr[i] + arr[j]) >= sum && i < j)
        {
            absDiff = abs(sum -(arr[i] + arr[j]));
            
            if(absDiff < nearest){
                ans.first = arr[i];
                ans.second = arr[j];
                nearest = absDiff;
            }
            
            if(absDiff == 0){
                return ans;
            }
            j--;
        }
    }
    return ans;
}

int main(void)
{
    int arr [10] = {-1,2,3,4,5,6,7,8,12,0};
    
    pair<int, int> ans = findClosest(arr, 10, 11);
    cout << ans.first << " " <<ans.second <<endl;
    

}
