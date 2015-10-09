#include <iostream>
using namespace std;

void swap(char *fir, char *sec)
{
    char temp = *fir;
    *fir = *sec;
    *sec = temp;
}

/* arr is the string, curr is the current index to start permutation from and size is sizeof the arr */
void permutation(char * arr, int curr, int size)
{
    if(curr == size-1)
    {
        for(int a=0; a<size; a++)
            cout << arr[a] << "\t";
        cout << endl;
    }

    else
    {
        for(int i=curr; i<size; i++)
        {
            swap(&arr[curr], &arr[i]);
            permutation(arr, curr+1, size);
            swap(&arr[curr], &arr[i]);
        }
    }
}

int main()
{

    char str[] = "abcd";

    permutation(str, 0, sizeof(str)-1);
    return 0;
}