/**
 * aabcdefghgijkg
 *
 * // check if each character is present in hashmap
 * // remember longest and position
 * // after a repeating character is found at 'pos' - account for the preceding lenght and position
 * // continue fresh from above 'pos'
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
    
};


int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring(string("dvdf")) << endl;
    
    return 0;
}
