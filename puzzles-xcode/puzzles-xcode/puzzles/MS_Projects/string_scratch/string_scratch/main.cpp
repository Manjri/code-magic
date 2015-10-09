#include <iostream>
#include <string>

using namespace std;

// replace all spaces with %20
char* spaceReplace(char* str, int length)
{
    int newLength = 0;
    int spaceCount = 0;

    // count the number of spaces
    for(int i=0; i<length; i++)
    {
        if(str[i] == ' ')
            spaceCount++;
    }  

    newLength = length + (spaceCount*2);

    char* newStr = (char*)malloc(newLength);

    newStr[newLength] = '\0';

    // traverse the string in the reverse direction and replace ' ' with '%''2''0'
    // if no ' ' then simply copy over the character
    for(int i = length-1; i >= 0; i--)
    {
        if( str[i] == ' ')
        {
            newStr[newLength-1] = '0';
            newStr[newLength-2] = '2';
            newStr[newLength-3] = '%';
            newLength -= 3;
        }
        else
        {
            newStr[newLength-1] = str[i];
            newLength -= 1;
        }
    }
    return newStr;
}



// tests if string contains unique chars or not
bool isUniqueString(string& pString)
{
    bool charSet[256] = {false};

    for(int i=0; i < pString.length(); i++)
    {
        if( charSet[pString.at(i)] )
            return false;
        else
            charSet[pString.at(i)] = true;
    }      
    
    return true;
}

// assuming the string contains only lower case a-z
bool isUniqueString1(string& pString)
{
    // 32 bits .. we are creating a bit vector
    int charSet = 0;

    for(int i=0; i<pString.length(); i++)
    {
        int val = pString.at(i) - 'a';
        if(charSet & (1 << val) > 0) 
            return false;
        else
            charSet |= 1 << val; 
    }
    return true;
}

string& swap(string& str, int x, int y)
{
    char ch;
    ch = str[x];
    str[x] = str[y];
    str[y] = ch;
    return str;
}

int findLength(char* str)
{
    int i;
    for(i=0; str[i] != '\0'; i++)
        ;
    return i;
}

string& reverseString(string& str)
{
    int len = str.length();
    int mid = len/2;

    for(int i=0; i< mid; i++)
    {
        swap(str, i, len-1-i);
    }
    return str;
}

void removeDuplicates(char* str)
{

    int len = findLength(str);
    if(!len)
        return;

    if(len < 2)
        return;

    int i, j;

    // [0, tail) in string will contain unique characters
    int tail = 1;

    // run the outer loop from 1 to len -1;
    for(i=1; i < len; i++)
    {
        // this loop will test str[i] against the elements in [0, tail)
        for(j = 0; j < tail; j++)
        {
            if (str[j] == str[i])
                break; // duplicate has been found, so break
        }

        if( j == tail)
        {
            // no duplicates found, add str[i] at the end..viz: tail position
            str[tail] = str[i];

            // increment tail
            tail++;
        }
    }
    str[tail] = '\0';
}

bool checkDups(string s)
{
    int len = s.length();
    bool flags[256] = {0};

    for(int i=0; i<len; i++)
    {
        if(flags[s[i]])
            return false;
        else
        {
            flags[s[i]] = 1;
        }
    }
    return true;
}



bool areAnagrams(char* s, char* t)
{
    if(s == NULL || t == NULL)
        return false;
    
    int lenS = findLength(s);
    int lenT = findLength(t);

    if(lenS != lenT) 
        return false;

    int cSet[256] = {0};
    int i ;
    int nUniqueS = 0;
    int nUniqueT = 0;

    for(i = 0; i < lenS; i++)
    {
        if(cSet[s[i]] == 0)
            nUniqueS++;

        cSet[s[i]]++;
    }

    for(i = 0; i < lenT; i++)
    {
        if(cSet[t[i]] == 0)
            return false;

        cSet[t[i]]--;

        if(cSet[t[i]] == 0)
            nUniqueT++;
        
    }
    if( nUniqueS == nUniqueT )
        return true;
    else
        return false;

}

void reverseString(char* str)
{
    // in place, becareful of null char
    char temp;
    char *end = str;

    if(str)
    {
        while(*end)
        {
            // reach the end + 1
            end++;
        }
        
        end--;

        while(str < end)
        {
            temp = *str;
            *str++ = *end;
            *end-- = temp;
        }

    }

 }


int main()
{

    //char str[] = "abb cc ddd e";
    //char str1[] = "nikhil";
    string s("nikhil");

    //bool test = checkDups(s);
    //cout << s << " tested for no dups: " << test << endl;
    
    cout << "original is " << s << endl;
    
    reverseString(s);
    
    cout << "reveresed is " << s << endl;

#if 0
    int len = 0;

    for(len=0; str[len] != '\0'; len++)
        len++;
       
    len++;

    cout << "Replaced string is: " << spaceReplace(str, len) << endl;


    char s[] = "abcd";
    char t[] = "cbad";

    cout << areAnagrams(s, t) << endl;


    char testString[] = "aacd";
    
    cout << " String before Removing Dups: " << testString << endl;

    removeDuplicates(testString);

    cout << "String before Removing Dups: " << testString << endl;

    cout << reverseString(testString) << endl;


    string testString("computer");

    if( isUniqueString1( testString ) )
    {
       cout << testString << " is a unique string" << endl;
    }
    else
    {
        cout << testString << " is NOT a unique string" << endl;
    }

#endif

    return 0;
}
