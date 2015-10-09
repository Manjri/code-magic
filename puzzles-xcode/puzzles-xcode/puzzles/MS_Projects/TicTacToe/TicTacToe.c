/*
Design an algorithm to figure out if someone has won a game oftic-tac-toe.
*/
#include <stdio.h>
#include <string.h>

#define N 3

#define isEmpty(x) \
    (x == '/0')

char hasWon(char board[N][N])
{
    // check rows, coloumns, diagonal and reverse diagonal for successive element matches
    // optimize it such that if the first element is empty then stop further searching
    // each position can be empty, occupied by 'x'. occupied by 'o'

    int row = 0;
    int col = 0;
    int i = 0;
    int j= 0;
    
    //rows
    for(i=0; i<N; i++) 
    {
        if(isEmpty(board[i][0]))
        {
            for(j=1; j<N; j++)
            {
                if(board[i][j] != board[i][j-1])
                    break;
            }
            if(j == N)
                return board[i][0];

        }
    }

    //col
    for(j=0; j<N; j++) 
    {
        if(!isEmpty(board[0][j]))
        {
            for(i=1; i<N; i++)
            {
                if(board[i][j] != board[i-1][j])
                    break;
            }
            if(i == N)
                return board[0][j];

        }
    }
    //diagonal
    // top left to bottom right
    if(!isEmpty(board[0][0]))
    {
        for(i = 1; i<N; i++)
        {
            if(board[i][i] != board[i-1][i-1])
                break;
        }
        if(i == N)
            return board[0][0];
    }
    // reverse diagonal
    // bottom left to top right
    if(!isEmpty(board[N-1][0]))
    {
        for(i = 1; i<N; i++)
        {
            if(board[N-i-1][i] != board[N-i][i-1])
                break;
        }
        if(i == N)
            return board[N-1][0];
    }

    return NULL;
}


