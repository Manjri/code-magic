#include <iostream>
using namespace std;

int flip(int bit)
{
    return bit^1;
}

/* returns 1 if a is positive and 0 if negative*/
int sign(int a)
{
    return flip((a >> 31 & 0x1));
}

int main()
{
    /*
    if a and b have diff signs...
    if a>0 then b<0 ... k=1
    if a<0 then b>0 ... k=0
    either way k = sign(a)
    */

    int a = 0, b = 0, c = 0, k = 0, q=0;
    int use_sign_of_a = 0;
    int use_sign_of_c= 0;
    int sa, sb, sc;

    cout << "\nEnter number a: " ;
    cin >> a;
    cout << "\nEnter number b: " ;
    cin >> b;

    c = a - b;

    sa = sign(a); // 1 if a>=0 else 0
    sb = sign(a); // 1 if b>=0 else 0
    sc = sign(c); // depends on whether a-b overflows

    // if a & b have different signs then k = sign(a)
    use_sign_of_a = sa ^ sb;

    // if a & b have same sign then k = sign(a - b)
    use_sign_of_c = flip(sa ^ sb);

    k = (use_sign_of_a * sa) + (use_sign_of_c * sc);
    
    // opposite of k
    q = flip(k);

    cout << "Max of a and b is: " << (a*k + b*q) << endl;

    return 0;
}