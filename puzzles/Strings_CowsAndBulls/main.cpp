/**
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> sVec(10,0);
        vector<int> gVec(10,0);

        
        // first pass
        for(int i=0; i<secret.size(); i++){
            char c1 = secret[i];
            char c2 = guess[i];

            if(c1 == c2)
                a++;
            else{
                sVec[c1-'0']++;
                gVec[c2-'0']++;
            }
        }
        
        // second pass
        for(int i=0; i<sVec.size(); i++){
            b += min(sVec[i], gVec[i]);
        }

        return string(to_string(a) + 'A' + to_string(b) + 'B'); 
    }
};

int main(){

    Solution s;
    
    cout << s.getHint("1123", "0111") << endl;

    return 0;
}
