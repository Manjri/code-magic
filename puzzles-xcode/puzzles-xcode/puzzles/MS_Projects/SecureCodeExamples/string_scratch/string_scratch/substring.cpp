#include <stdio.h>
#include <string.h>

void search(char* pat, char* text)
{
    int M = strlen(pat);
    int N = strlen(text);

    // for loop to slide pat[] one by one

    for(int i=0; i < (N-M); i++)
    {
        int j;

        for(j=0; j < M; j++)
        {
            if(pat[j] != text[i+j])
                break;
        }
        if( j == M )
        {
            printf("\nPattern found at %d",(i));
        }
    }
}

int main()
{
    char* txt = "AABBAACCCDDDEEFFF";
    char* pat = "BBA";
        
    search(pat, txt);

    return 0;
}




