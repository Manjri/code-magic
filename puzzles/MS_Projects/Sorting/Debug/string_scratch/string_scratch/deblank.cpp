#include <iostream>
#include <string>

using namespace std;

char* Deblank(char* input)
{
    char* output = input;
    unsigned i, j;
        
    if(!output)
        return NULL;
        
    for(i=0, j=0; i<strlen(input); i++, j++)
    {
        if(input[i] != ' ')
        {
            output[j] = input[i];
        }
        else
        {
            j--;
        }
    }
    
    output[j] = 0;
    
    return output;
}

int main()
{
    char* input  = (char*)malloc(sizeof(char)*20);
    strcpy(input, " abc");
        
    cout << Deblank(input) << endl;

    return 0;
}