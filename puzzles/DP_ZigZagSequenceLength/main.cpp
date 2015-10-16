/**
 [TOPCODER]
 
 Problem Statement
 A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a zig-zag sequence.
 
 For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and the second because its last difference is zero.
 
 Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. A subsequence is obtained by deleting some number of elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
 

**/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX(a,b) (a) > (b) ? (a) : (b)

class ZigZag {
public:
    int longestZigZag(vector <int> sequence)
    {
        if(sequence.size() == 1) return 1;
        
        vector<int> dp0(sequence.size());
        vector<int> dp1(sequence.size());
        
        for(int i=0; i<sequence.size(); i++){
            dp0[i] = dp1[i] = 1;
            
            for(int j = 0; j<=(i-1); j++){
                
                if(sequence[i] - sequence[j] > 0)
                    dp0[i] = MAX(dp1[j]+1, dp0[i]);
                else if(sequence[i] - sequence[j] < 0)
                    dp1[i] = MAX(dp0[j]+1, dp1[i]);
            }
        }
        return MAX(dp0[sequence.size()-1], dp1[sequence.size()-1]);
    }
};



/**
 
 NonDP - Greedy Approach with O(n) run time
 
 #include <string>
 #include <vector>
 #include <sstream>
 #include <algorithm>
 #include <iostream>
 
 //#include <functional>
 //#include <map>
 //#include <set>
 //#include <numeric>
 //#include <queue>
 //#include <stack>
 //#include <list>
 
 using namespace std;
 
 class ZigZag {
 public:
     int longestZigZag(vector <int> sequence)
     {
        if(sequence.size() == 1)
            return 1;
         
        vector<int> v(sequence.size()-1);
        
        for(int i=1;i<sequence.size();i++)
        {
         v[i-1] = sequence[i] - sequence[i-1];
        }
        //    dir is first nonzero
        int ii=0;
        while( ii < v.size() && v[ii] == 0)
         ii++;
 
        if(ii == v.size()) 
            return 1;
 
        int dir = v[ii];
        int len = 2;
        for(int i=ii+1;i<v.size();i++)
        {
         if(v[i] * dir < 0)
         {
            dir *= -1;
            len++;
         }
        }
        return len;
     }
 };
 
 
 
*/