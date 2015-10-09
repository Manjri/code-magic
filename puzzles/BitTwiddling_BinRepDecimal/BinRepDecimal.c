#include <stdio.h>

int printBinary(double num, char* s)
{
    
    int count = 0;
    double r;
    
    if(num >=1 || num <=0)
    {
        printf("\nError");
        return NULL;
    }
    
    s[count] = '.';
    count++;

    while(num >0)
    {
        
        if(count>=31)
        {
            printf("\nError ... Representation longer than 32 bits");
            return NULL;
        }
        
        r = num * 2;
        
        if(r >= 1)
        {
            s[count] = 1;
            num = r - 1;
        }
        else
        {
            s[count] = 0;
            num = r;
        }

        count++;
    }
    s[count] = '\0';
    return 1;
}


int main()
{
    double num = 0.5;
    char s[50];

    if(printBinary(num, s))
        printf("Binary rep is: %s", s);
    else
        printf("\nNot valid binary number");
    return 0;
}