//
//  tictactoe.c
//  BoilerPlate
//
//  Created by Nikhil Jagdale on 5/1/16.
//  Copyright © 2016 Nikhil Jagdale. All rights reserved.
//

#include "tictactoe.h"

char board[3][3];

static void createBoard(){
    
    for(int i=0;i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j]=0;
        }//colns
    }//rows
    
    // set the seed
    srand((unsigned int)time(NULL));
}



static void player1Moves(){
    // player 1 plays 1
    while(1){
        size_t r = rand()%3;
        size_t c = rand()%3;
        if(board[r][c]==0){
            board[r][c] = 1;
            break;
        }
    }
}

static void player2Moves(){
    // player 2 plays 2
    while(1){
        size_t r = rand()%3;
        size_t c = rand()%3;
        if(board[r][c]==0){
            board[r][c] = 2;
            break;
        }
    }
}

static void showBoard(){
    
    for(int i=0;i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", board[i][j]);
        }//colns
        printf("\n");
    }//rows
}

static int checkRows(){
    
    for(int i=0; i<3; i++){
        
        if(board[i][0] &&
           board[i][0]==board[i][1] &&
           board[i][0]==board[i][2]
           )
            return board[i][0];
    }
    return 0;
}

static int checkCols(){
    
    for(int j=0; j<3; j++){
        
        if(board[0][j] &&
           board[0][j]==board[1][j] &&
           board[0][j]==board[2][j]
           )
            return board[0][j];
    }
    return 0;
}

static int checkDiags(){
    
    if(board[0][0]==1 && board[1][1]==1 && board[2][2]==1)
        return 1;
    
    if(board[0][0]==2 && board[1][1]==2 && board[2][2]==2)
        return 2;
    
    return 0;
}

static int checkBoard(){
    
    int ret = 0;
    if((ret = checkRows()))
        return ret;
    
    if((ret = checkCols()))
        return ret;
    
    if((ret = checkDiags()))
       return ret;
    
    return 0;
    
}

static int hasWon(){
    int ret = checkBoard();
    if(ret){
        printf("--> %d has won!\n",ret);
    }
    return ret;
}

static int playGame(){
    size_t count = 0;
    int turn = 0;
    int won = 0;

    printf("---------------\n");
    printf("::New Board::\n");
    printf("---------------\n");
    createBoard();
    showBoard();
    
    while(count<9){
        printf("Player %d moves\n",turn+1);
        if(turn==0)
            player1Moves();
        else
            player2Moves();
        count++;
        turn ^= 1;
        showBoard();
        usleep(1000000);
        
        if((won=hasWon()))
            return won;
    }
    if(count==9)
        printf("--> Draw!!\n");
    
    return won;
}

void playNGames(int n){
    
    // 2 players play N games
    char winTally[3] = {0,0,0};
    
    for(int i=0; i<n; i++){
        printf("Game %d about to start\n",i+1);
        winTally[playGame()]++;
    }
    printf("=============================\n");
    printf("Draws: \t\t%d\n",winTally[0]);
    printf("Player 1: \t%d\n",winTally[1]);
    printf("Player 2: \t%d\n",winTally[2]);
    printf("=============================\n");
}
