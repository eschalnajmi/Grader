
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "endGame.h"
#include "playGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol, int gridsize, int winlen ) {
    
    int hlen = 1;
    int vlen = 1;
    
    // return 1(true) if game is won, 0(false) otherwise
    // Games can be won with horizontal, vertical or diagonal lines
    
    // Checking if won horizontally
    for(int i = 0; i < gridsize; i++){
        for(int j = 0; j < gridsize-1; j++){
            if(game->board[i][j] == game->board[i][j+1] && game->board[i][j] != '.'){
                hlen++;
            } else{
                hlen = 1;
            }
            if(hlen == winlen){
                return 1;
            }
        }
    }
    
    // Checking if won vertically
    for(int j = 0; j < gridsize; j++){
        for(int i = 0; i < gridsize-1; i++){
            if(game->board[i][j] == game->board[i+1][j] && game->board[i][j] != '.'){
                vlen++;
            } else{
                vlen = 1;
            }
            if(vlen == winlen){
                return 1;
            }
        }
    }
    
    // Checking if won diagonally
    for(int i = 0; i < gridsize; i++){
        for(int j = 0; j < gridsize; j++){
            if(diagwin(game, game->board[i][j], symbol, winlen, 0, i, j) == 2){
                return 1;
            }
        }
    }
    
    for(int i = 0; i < gridsize; i++){
        for(int j = gridsize - 1; j > -1; j--){
            if(rdiagwin(game, game->board[i][j], symbol, winlen, 0, i, j) == 2){
                return 1;
            }
        }
    }
    

    return 0;
}

// function implemented recursively to check for diagonal wins
int diagwin(Game *game, char space, char symbol, int winlen, int dlen, int i, int j){
    if(space == symbol){
        dlen++;
        if(dlen == winlen){
            return 2;
        } else if(diagwin(game, game->board[i+1][j+1], symbol, winlen, dlen, i+1, j+1) == 1){
            return 1;
        } else if(diagwin(game, game->board[i+1][j+1], symbol, winlen, dlen, i+1, j+1) == 2){
            return 2;
        }
    } else{
        dlen = 1;
        return 0;
    }
    return 0;
}

int rdiagwin(Game *game, char space, char symbol, int winlen, int dlen, int i, int j){
    if(space == symbol){
        dlen++;
        if(dlen == winlen){
            return 2;
        } else if(rdiagwin(game, game->board[i+1][j-1], symbol, winlen, dlen, i+1, j-1) == 1){
            return 1;
        } else if(rdiagwin(game, game->board[i+1][j-1], symbol, winlen, dlen, i+1, j-1) == 2){
            return 2;
        }
    } else{
        dlen = 1;
        return 0;
    }
    return 0;
}



// test for a draw
int drawGame( Game *game ) {
    // return 1(true) if game is drawn, 0(false) otherwise
    if(game->turns == game->maxTurns){
        return 1;
    }
    return 0;
}

