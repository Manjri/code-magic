/**
 
 Calculate the max rectangular area of a histogram 
 Input is the bar heights given in an array
 
 For example:
      -----
 -----|   |----
 | 1  | 2 | 1 |
 ---------------
 
 arr[] = {1,2,1}
 
 Max Area here is: 3
 
 */

#include <iostream>
#include <stack>
using namespace std;

int maxArea(int arr[], int n){
    
    int area, maxArea = 0;
    stack<int> s;
    int i = 0;
    
    for(i=0; i<n;){
        
        if(s.empty() || arr[s.top()] <= arr[i]){
            s.push(i);
            i++;
        }
        else{
            // calculate area;
            int val = s.top();
            s.pop();
            if(s.empty())
                area = arr[val] * i;
            else
                area = arr[val] * (i-s.top()-1);
            
            // update maxArea
            maxArea = (area > maxArea) ? area : maxArea;
        }
    }
    
    while(!s.empty()){
        int val = s.top();
        s.pop();
        if(s.empty())
            area = arr[val] * i;
        else
            area = arr[val] * (i-s.top()-1);
        
        maxArea = (area > maxArea) ? area : maxArea;
    }
    
    return maxArea;
}

int main(){
    
    int arr[] = {1,2,1};
    cout << maxArea(arr, sizeof(arr)/sizeof(arr[0])) << endl;;
    return 0;
}

