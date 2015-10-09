#include <iostream>
using namespace std;


char *rev(char* l, char* r)
{
    char *str = l;
    char temp;

    while( l<=r )
    {
        temp = *l;
        *l = *r;
        *r = temp;
        l++;
        r--;
    }

    return str;
}

int main()
{
    char mystr[80];
    char *s_word, *e_word;

    strcpy(mystr, "this is a string");

    rev(mystr, &mystr[(strlen(mystr)-1)]);

    s_word = mystr;
    e_word = s_word;

    while(1)
    {
        if(*e_word == ' ' || *e_word =='\0')
        {
           rev(s_word, (e_word-1));

           if(*e_word == '\0')
               break;
           else
               s_word = ++e_word;

        }
        e_word++;
    }

    cout << mystr << endl;

    return 0;
}
