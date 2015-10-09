#include <iostream>
using namespace std;


double myatof(char* s)
{
    double value = 0;
    double sign = 1.0;
    double power = 1.0;

    if(s==NULL)
        return 0;

    if(*s == '-')
    {
        sign = -1.0;
        s++;
    }
    
    for(; s && (*s >= '0' && *s <= '9'); s++)
    {
        value = value*10.0 + (*s-'0');
    }
    
    if(*s == '.')
    {
        s++;

        for(; s && (*s >= '0' && *s <= '9'); s++)
        {
            value = value*10.0 + (*s-'0');
            power*= 10;
        }
    }
    
    return (value/power) * sign;
}

int main()

{
    cout << myatof("-1.0") << endl;

    return 0;
}