/*
Reverse Words
Write a function that reverses the order of the words in a string. For example, your
function should transform the string “Do or do not, there is no try.” to “try. no is
there not, do or Do”. Assume that all words are space delimited and treat punctuation
the same as letters.**/

/*
Algorithm:

its easier to do swap of characters in the string ... replace every character in the string from start to end
Then for every word from the beginning of the string, reverse the characters in the word

eg: 
string reversal

lasrever gnirts
reversal string

**/


#include <stdio.h>
#include <string.h>

void revereString(char* str, int start, int end)
{

    char temp;
    int len = strlen(str);
    // start = 0;
    // end = strlen(str) - 1;

    while(end > start)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    str[len] = '\0';
}


int main()
{
    char str[] = "string reversal";
    char space = ' ';
    int startWord = 0;
    int endWord = 0;
    int len = strlen(str);
    int i = 0;
    //int curr = 0;

    printf("\nOriginal String: %s", str);
    revereString(str, 0, (strlen(str)-1));
    

    // find each word till end of string is reached
    while( str[startWord] )
    {
        while(str[startWord] == space)
            startWord++;

        endWord = startWord;

        while(str[endWord] != space && str[endWord] != '\0')
            endWord++;
        endWord--;

        revereString(str, startWord, endWord);
        
        startWord = ++endWord;        
    }
    printf("\nReversed String: %s", str);
    return 0;
}