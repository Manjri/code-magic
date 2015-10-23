/**
You are a product manager and currently leading a team to develop a new product. 
 Unfortunately, the latest version of your product fails the quality check. 
 Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
 which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. 
 Implement a function to find the first bad version. You should minimize the number of calls to the API.

*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

/**
 n=100
 bad_version = 35
 
 100...
 
 1-100
 1-false 100-false
 
 1-false 50-true
 51-true 100-true -->eliminate 51-100
 
 1-false 25-false -->eliminiate 1-25
 26-false 50-true
 
 26-false 37-true
 38-true 50-true -->elimiate 38-50
 
 26-false 31-false  --> eliminate 26-32
 32-false 37-true
 
 32-false 34-false
 35-true  37-true --> 35 is the ans
 
 1-2 (2-bad version)
 
 mid = 1
 1-1
 2-2
 */


class Solution {
public:
    
    int firstBadVersionHelper(int l, int h) {
        
        if(l<h){
            int m = l + (h-l)/2;
            
            if(isBadVersion(m))
                return firstBadVersionHelper(l, m);
            else
                return firstBadVersionHelper(m+1,h);
        }
        else
            return l;
    }
    
    int firstBadVersion(int n) {
        return firstBadVersionHelper(1, n);
    }
    
};