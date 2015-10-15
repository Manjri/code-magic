#include <iostream>
#include <vector>
using namespace std;

void reverse_string(char *string)
{

    if(string == NULL)
        return;
    
    char* temp = string;
    
    while(temp && *temp)
        temp++;
    
    temp--;
    while(string < temp)
    {
        *string ^= *temp;
        *temp   ^= *string;
        *string ^= *temp;
        
        string++;
        temp--;
    }
}

/* returns a pointer to a newly-allocated reversed string */
char *reversed_string(const char *string)
{
    size_t count;
    const char *temp = string;
    
    for(count = 0 ;temp && *temp; count++, temp++)
        ;

    char *newString = (char*)malloc(sizeof(char)*(count+1));
    
    memcpy(newString, string, (count+1));
    reverse_string(newString);
    
    return newString;
}

int main(){
    
    char s[] = "nikhil";
    char *newStr = reversed_string(s);
    if(newStr)
        //cout << "string: " << s << endl;
        cout << "string: " << newStr << endl;
    return 0;
}