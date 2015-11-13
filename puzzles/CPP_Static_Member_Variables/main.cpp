#include <iostream>
#include "Something.h"

// This works!
const double Something::fudgeFactor = 1.57;
int Something::s_nIDGenerator = 0;

int main()
{
    Something cFirst;
    Something cSecond;
    Something cThird;
   
    std::cout << cFirst.GetID() << std::endl;
    std::cout << cSecond.GetID() << std::endl;
    std::cout << cThird.GetID() << std::endl;
    return 0;
}
