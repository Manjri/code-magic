

/**
Write a routine that takes a seven-digit telephone number and prints out all of the
possible “words” or combinations of letters that can represent the given number.
Because the 0 and 1 keys have no letters on them, you should change only the digits
2–9 to letters. You’ll be passed an array of seven integers, with each element being
one digit in the number. You may assume that only valid phone numbers will be
passed to your routine. You can use the helper routine
char getCharKey( int telephoneKey, int place )
which takes a telephone key (0–9) and a place of either 1, 2, 3 and returns the character
corresponding to the letter in that position on the specified key. For example,
GetCharKey(3, 2) will return ‘E’ because the telephone key 3 has the letters “DEF”
on it and ‘E’ is the second letter.
*/

#include <stdio.h>

#define LEN 7

/*
2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz
*/

char getCharKey(int num, int pos)
{
    char keyval[8][4] = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'},              {'t','u','v'}, {'w','x','y','z'}};
    
    char val = num - 2;
  
    // todo: check if num>=2  <=9 and pos is in range >=1 <=4 always
    return (char)keyval[val][pos-1];
}

void printStrings(int* num, char* res, int pos)
{
    int i;

    if(pos == LEN)
    {
        printf("%s\n", res);
        return;
    }
    else
    {
        if (num[pos] == 7 || num[pos] == 9)
        {
            for(i=1; i<=4; i++)
            {
                res[pos] = getCharKey(num[pos], i);
                printStrings(num, res, pos+1);

                if(num[pos] == 0 || num[pos] == 1)
                    return;
            }
        }
        else
        {
            for(i=1; i<=3; i++)
            {
                res[pos] = getCharKey(num[pos], i);
                printStrings(num, res, pos+1);

                if(num[pos] == 0 || num[pos] == 1)
                    return;
            }
        }
    }
}

void printWords(int* num)
{
    char res[8];
    res[7] = '\0';
    printStrings(num, res, 0);
}


int main()
{
    int num[7] = {2,3,4,5,6,7,8,};
    
    printWords(num);

    return 0;
}


