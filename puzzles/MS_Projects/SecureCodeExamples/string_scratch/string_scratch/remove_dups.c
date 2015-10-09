#include <stdio.h>

int findlen(char* input)
{
    int i;

    for(i = 0; input[i]!= '\0'; i++)
        ;
    
    return i;
}



void removeDups(char* input)
{   
    int tail = 1;
    int len = findlen(input);
    int i, j;

    for(i=1; i<=len-1;i++)
    {
        for(j = 0; j<tail; j++)
        {
            if(input[i] == input[j])
            {
                break;
            }    
        }
        if( j == tail)
        {
            // no dups found
            input[j] = input[i];
            tail++;
        }
    }
    input[tail] = '\0';
}

int main()
{
    char str[] = "aabc";
    
    removeDups(str);

    printf("%s", str);

    return 0;
}