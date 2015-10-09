#include <iostream>
#include <vector>
#include <string>

using namespace std;

void checkWords(vector<char> &vc, vector<string> &vs, vector<string> &res)
{
    char letters[128] = {0};
    char times[128] = {0};

    string word;
    int i,j, len;
    
    res.clear();

    for(i=0; i<vc.size(); i++)
        letters[vc[i]]++;

    for(i=0; i<vs.size(); i++)
    {
        word = vs[i];
        for(j=0, len=word.size(); j<len; j++)
        {
            if(++times[word[j]] > letters[word[j]])
                break;
        }
        if(j==len)
            res.push_back(word);

        for(j-=1;j>=0;j--)
            times[word[j]]--;
    }

}

int main()
{
    vector<char> letters;
    vector<string> words;
    vector<string> res;

    letters.push_back('a');
    letters.push_back('c');
    letters.push_back('t');

    words.push_back("cat");
    words.push_back("ac");
    words.push_back("act");
    words.push_back("stop");
    words.push_back("cac");

    checkWords(letters, words, res);

    for(int i=0; i<res.size(); i++)
        cout << res[i] <<"\n";

    return 0;
}