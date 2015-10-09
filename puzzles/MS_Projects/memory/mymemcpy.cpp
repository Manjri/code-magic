#include <iostream>
using namespace std;

void mymemcpy(void* dest, void* src, unsigned int count)
{
    char* charSrc = (char*)src;
    char* charDest = (char*)dest;

    while(count--)
    {
        *(charDest++) = *(charSrc++);
    }
}


int main()
{
    int* mySrcArr = (int*)malloc(sizeof(int)*10);
    int* myDestArr = (int*)malloc(sizeof(int)*10);

    for(int i=0; i<10; i++)
        mySrcArr[i] = i+1;

    mymemcpy((void*)myDestArr, (void*)mySrcArr, 10*sizeof(int));

    return 0;
}