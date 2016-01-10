#include <stdio.h>

void reverse(char* str, int start, int end){
    while(start < end){
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

void reverseWords(char* str){

    // find length
    int len = 0, start  = 0;
    char* temp = str;
    char* result = NULL;

    for(;*temp; len++, temp++)
        ;

    temp = str;

    for(int i=0; i<len; i++){
        if(temp[i] == ' '){
        // found a space, reverse prev word
        reverse(str, start, i-1);                 
        start = i+1;
       }
    }

    // reached end of the word
    // or corner case of 1 word only
    reverse(str, start, len-1);

    // now reverse the whole string
    reverse(str, 0, len-1);

}

int main(){
    char str[] = "hello world!";
    printf("%s\n", str);
    reverseWords(str);        
    printf("%s\n", str);
    return 0;
}
