//
//  main.c
//  ReverseWords
//
//  Created by Nikhil Jagdale on 7/30/15.
//  Copyright (c) 2015 Nikhil Jagdale. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void reverse(char *s, unsigned long start, unsigned long end)
{
    char temp;
    
    while(start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    
    return;
}

void reverseWords(char *s, unsigned long start, unsigned long end)
{
    unsigned long len = strlen(s)-1;
    int count = 0;
    int i=0;
    reverse(s, 0, len);
    
    for(i = 0; i<=len; i++)
    {
        if(s[i] == ' ')
        {
            /* i has reached space char, go back 1 */
            reverse(s, count, i-1);
            
            /* i is 1 beyond space now */
            count = i+1;
        }
    }
    /*
     1. reached the last word and we want to reverse it
     2. corner case: when there is only 1 word
     
     note i has reached NULL char due to for loop, we need to go back 1
     */
    reverse(s, count, i-1);
}

int main(int argc, const char * argv[]) {
    char s[] = "Hello World";
    reverseWords(s, 0, strlen(s)-1);
    printf("%s\n", s);
    return 0;
}