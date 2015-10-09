#include <iostream>
using namespace std;

#define R 0
#define Y 1
#define B 2
#define G 3
#define SIZE 4

void mastermind(int guess[], int solution[], int *hit,  int *pseudoHit)
{
    *hit = 0;
    *pseudoHit = 0;
    int frequency[SIZE] = {0};

    for(int i=0; i<SIZE; i++)
    {
        if(guess[i] == solution[i])
            (*hit)++;
        else
            frequency[solution[i]]++;
    }

    for(int i=0; i<SIZE; i++)
    {
        if(frequency[guess[i]] > 0 && guess[i] != solution[i])
        {
            frequency[guess[i]]--;
            (*pseudoHit)++;
        }
    }

}

int main()
{
    int guess[SIZE] = {R,R,G,B};
    int solution[SIZE] = {R,Y,B,Y};
    int hits =0, pHits =0;
    // correct ans: Hits=1, PseudoHits=1

    mastermind(guess, solution, &hits, &pHits);

    cout << "\nHits: " << hits << " PseudoHits: " << pHits << endl;

    return 0;
}