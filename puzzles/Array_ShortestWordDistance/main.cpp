#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MIN(a,b) ((a) < (b) ? (a) : (b))

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        int word1Pos = -1, word2Pos = -1;
        unsigned int minDistance = UINT_MAX;
        
        for(int i=0; i<words.size(); i++){
            if(words[i] == word1)
                word1Pos = i;
            
            if(words[i] == word2)
                word2Pos = i;
            
            if(word1Pos && word2Pos)
                minDistance = MIN(minDistance, abs(word2Pos-i));
            
        }
        return minDistance;
    }
};

// Driver program to test methods of graph class
int main()
{
    Solution sol;
    vector<string> vec = vector<string>{"a", "c", "b", "b", "a"};
    
    cout << sol.shortestDistance(vec, "a", "b") << endl;
    return 0;
}