#include <iostream>
//#include <string.h>
using namespace std;
// check if the binary representation equals the hex number

bool compareBinToHex(string binary, string hex);
double convertToDecimal(string num, int base);
unsigned toDigit(char c);

unsigned toDigit(char c)
{
    if(c >= '0' && c<= '9')
        return c - '0';

    else if(c >= 'a' && c <= 'f')
        return c + 10 - 'a';

    else if (c >= 'A' && c <= 'F')
        return c + 10 - 'A';

    else
    {
        cout << " Not a valid number " << endl;
        exit(1);
        return 0;
    }
}

double convertToDecimal(string num, int base)
{
    // get the decimal digit successfully

    double val = 0;
    unsigned digit;
    const char* str = num.data();
    int len = num.length();

    for(int i=len-1; i>=0; i--)
    {
        digit = toDigit(str[i]);
        val += digit * pow((double)base, (double)(num.length() - 1 - i));
    }

    return val;
}


/*
1. take the binary number, find its value in decimal
    a. call atoi sucessively
    b. add the numbers up per the base

2. take the hex number, find its value in decimal
    a. call atoi sucessively
    b. add the numbers up per the base

3. Compare the two
*/


bool compareBinToHex(string binary, string hex)
{
    double n1 = convertToDecimal(binary, 2);
    double n2 = convertToDecimal(hex, 16); 

    if(n1 < 0 || n2 < 0)
        return false;

    return (n1 == n2);
}

int main()
{

    cout << compareBinToHex("001", "357") << endl;

    return 0;
}