
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "playGame.h"
#include "endGame.h"

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game, int gridsize, int winlen ) {

    char symbols[2] = { 'X','O' };
    
    // player 'X' plays first
    int player = 0;
    int win = -1;

    // starting board
    printf("New game starting\n");
    showGame( game, gridsize );
  
    // Your game should be controlled by an outer loop
    // Each pass through the loop is one completed move by a player
    while(win == -1){
        
        // Request a move from the next player and check it is valid (an unused square within the board)
        printf("Player %c: Enter your move as row column values:\n", symbols[player]);
        
        if(makeMove(game, symbols[player]) == 1){
            // After each completed move display the board
            showGame(game, gridsize);
            
            // After each valid move you can test for win or draw using functions you implement in endGame.c
            if(winGame(game, symbols[player], gridsize, winlen) == 1){
                printf("Player %c has won\n",symbols[player]); // use to announce a winner - game is over
                exit(-1);
            } else if(drawGame(game) == 1){
                printf("Match is drawn\n"); // use to announce a draw - game is over
                exit(-1);
            }
            
            if(player == 0){
                player = 1;
            } else {
                player = 0;
            }
        }
    }
    
    return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game, int boardSize ) {

    printf("\n");
    printf("     ");
    for(int i = 0; i < boardSize; i++){
        printf(" %i", i);
    }
    printf("\n");
    printf("\n");
    for(int i = 0; i < boardSize; i++){
        printf(" %i   ", i);
        for(int j = 0; j < boardSize; j++){
            printf(" %c", game->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return;
}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int isInt(char move){
    if(move < '0' || move > '9'){
        return -1;
    } else if((move-'0')%1!= 0){
        return -1;
    }
    return move - '0';
}

int makeMove( Game *game, char symbol ) {

    char cmove1, cmove2 = '\0';

    //read the players move from the keyboard, expected as two integers coordinates as shown on the board
    scanf(" %c %c", &cmove1, &cmove2);
    int move1 = isInt(cmove1);
    int move2 = isInt(cmove2);
    
    if(game->board[move1][move2] != '.'){
        // if we do not accept the move return 0
        printf("Move rejected. Please try again\n");
        return 0;
    }
    // if we accept then update the board and return 1
    game->board[move1][move2] = symbol;
    game->turns++;
    
    return 1;
}

