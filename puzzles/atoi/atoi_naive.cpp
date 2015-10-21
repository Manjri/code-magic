// A simple C++ program for implementation of atoi
#include <stdio.h>

// A simple atoi() function
int myAtoi(char *str)
{
    int result = 0;
    
    for(int i=0; str[i] >= '0' && str[i] <= '9'; i++)
        result = result*10 + (str[i] - '0');
    
    return result;
}

// Driver program to test above function
int main()
{
    char str[] = "89789";
    int val = myAtoi(str);
    printf ("%d ", val);
    return 0;
}