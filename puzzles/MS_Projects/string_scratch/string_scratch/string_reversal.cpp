#include <iostream>
using namespace std;

int reverseString(const char* str, char** out)
{
    int len = 0;
    int start, end;
    char* revStr;
    char temp;

    // check for null pointer exception
    if(str == NULL)
        return -1;

    // find the len
    for(int i=0; str[i] != NULL; i++, len++)
        ;
    //len doesnt include the NULL character

    if(len==0)
        return -1;

    revStr = (char*)malloc(sizeof(char)*(len+1));

    memcpy(revStr, str, (len+1));

    if(len==1)
    {
        *out = revStr;    
        return 0;
    }

    start = 0;
    end = len-1;

    while(start < end)
    {
        temp = revStr[start];
        revStr[start] = revStr[end];
        revStr[end] = temp;

        start ++;
        end--;
    }

    *out = revStr;
    return 0;

}

int main()
{
    const char* orig = "nik";
    const char* orig1 = NULL;
    char* rev;
    int error = 0;

    error = reverseString(orig1, &rev);

    if(error >= 0)
    {
        cout << "Orig String is: " << orig1 << "Rev String is: " << rev << endl;
    }
    else
    {
        cout << " Error !! " << endl;
    }


}