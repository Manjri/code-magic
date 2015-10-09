#include <stdio.h>

bool isMatch(char* s, char* p)
{
    const char *star = NULL;
    const char *ss = s;
    
    while(*s)
    {
        // char in both matches or we have '?' in pattern
        // advance both pointers and continue
        
        if( (*s == *p) || (*p == '?'))
        {
            s++;
            p++;
            continue;
        }
        
        // found a '*' in pattern
        // advance just the pattern pointer
        if(*p == '*')
        {
            star = p++;
            ss = s;
            continue;
        }
        
        // last character in pattern was a '*', current is not a '*'
        // advance the source pointer, pattern pointer to next char after '*'
        if(star)
        {
            p = star+1;
            s = ++ss;
            continue;
        }
        
        // last character was not a *
        // source char didnt match pattern char
        return false;
    }
    
    // check if we have pending chars after '*' in pattern
    while(*p == '*')
        p++;
    
    // check if pattern is at the end
    return (*p==NULL);
}

int main()
{
    return 0;
}