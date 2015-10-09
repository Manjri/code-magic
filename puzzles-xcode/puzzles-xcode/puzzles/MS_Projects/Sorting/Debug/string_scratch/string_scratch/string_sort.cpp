#include <iostream>
using namespace std;


// function to sort the string (array of chars)
// this is basically merge sort operating on chars instead of ints

void merge(char *str, char *helper, size_t low, size_t mid, size_t high)
{
    size_t helperLow = low;
    size_t helperHigh = mid+1;
    size_t current = helperLow;

    // copy into helper
    for(int i=low; i<=high; i++)
    {
        helper[i] = str[i];
    }

    while(helperLow <= mid && helperHigh <= high)
    {
        if(helper[helperLow] <= helper[helperHigh])
        {
            str[current] = helper[helperLow];
            current++;
            helperLow++;
        }
        else
        {
            str[current] = helper[helperHigh];
            current++;
            helperHigh++;
        }
    }
    int remaining = mid - helperLow;

    for(int i=0; i<=remaining; i++)
    {
        str[current+i] = helper[helperLow+i]; 
    }
}


void mergeStringSort(char *str, char *helper, size_t start, size_t end)
{
    if(start < end)
    {
        size_t mid = (start + end)/2;

        mergeStringSort(str, helper, start, mid);

        mergeStringSort(str, helper, mid+1, end);

        merge(str, helper, start, mid, end);

    }


}


//mergeStringSortHelper()
void mergeStringSortHelper(char *str, size_t len)
{
    char *helper = (char *)malloc(len);
    mergeStringSort(str, helper, 0, len-1);

}

bool checkIfAnagrams(char *s1, char *s2)
{
    // sort s1, sort s2
    mergeStringSortHelper(s1, strlen(s1));
    mergeStringSortHelper(s2, strlen(s2));

    if( strcmp(s1, s2) == 0 )
        return true;
    else
        return false;
}


int main()
{
    char test1[100] =  {0};
    char test2[100] =  {0};
    
    strcpy(test1, "cdeba");
    strcpy(test2, "abfde");

    cout << checkIfAnagrams(test1, test2) << endl;

    //mergeStringSortHelper(test, strlen(test));
    return 0;
}