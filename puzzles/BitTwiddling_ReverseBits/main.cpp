#include <iostream>
#include <vector>
using namespace std;


unsigned int reverseBits(unsigned int num){
    
    unsigned int reversed = num; // gets LSB of num
    unsigned shift = sizeof(reversed)*CHAR_BIT - 1; // extra shift needed at the end
    
    num >>= 1;
    
    while(num){
        reversed <<= 1;
        reversed |= num & 1;
        num >>= 1;
        shift--;
    }
    
    reversed <<= shift;                 // shift when num's highest bits are zero
    
    return reversed;
}


/* Driver Program to test above functions */
int main()
{
    unsigned orig = 0x101;
    unsigned reversed = reverseBits(orig);
    cout << reversed << endl;
    return 0;
}