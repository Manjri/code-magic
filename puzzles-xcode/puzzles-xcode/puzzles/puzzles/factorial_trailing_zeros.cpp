#include <iostream>
using namespace std;

int computeTrailingZeros(int n)
{
    int count = 0;
    for(int i=5; n/i > 0; i*=5)
    {
        count += n/i;
    }
    return count;
}

int main()
{
    int num;
    cout << "\nEnter a number: ";
    cin >> num;
    cout << "\nTrailing zeros in " << num << ": " << computeTrailingZeros(num);
    return 0;
}

