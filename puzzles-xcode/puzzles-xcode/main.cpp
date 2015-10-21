#include <iostream>
using namespace std;

// Driver program to test above function
int main()
{
    char *s1 = "nikhil";
    char s2[] = "abc";
    cout << s1 << endl;
    cout << s2 << endl;
    s1[1] = 'j';
    s2[1] = 'd';
    cout << s2 << endl;
    return 0;
}