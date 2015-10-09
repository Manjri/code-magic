#include <iostream>
#include <string>

using namespace std;

//find a repeat character
static char findRepeat(char* s)
{
    bool map[256] = {false};
    
    int len = strlen(s);
    
    for(int i=0; i<len; i++)
    {
        if(map[s[i]] != false)
            return s[i];
        else
            map[s[i]] = true;
    }
    
    // contains all unique
    return NULL;
}


// remove all instances of the repeat character
static void removeAllInstances(char* s, char c)
{
    int len = strlen(s);
    int p = 0;
    
    for(int i=0; i<len; i++)
    {
        if(s[i] != c)
            s[p++] = s[i];
    }
    s[p] = '\0';    // for the null character
}

void removeDups(char* s)
{
    removeAllInstances(s, findRepeat(s));
}

int main()
{
    char str[] = "abbcde";
    removeDups(str);
    cout << str << endl;
    return 0;
}