
#include <stdio.h>

#include "game.h"
#include "endGame.h"
#include "playGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol ) {
    
    // return 1(true) if game is won, 0(false) otherwise
    // Games can be won with horizontal, vertical or diagonal lines
    for(int i = 0; i<3; i++){
        if(game->board[i][0] == symbol && game->board[i][1] == symbol && game->board[i][2] == symbol){
            return 1;
        } else if(game->board[0][i] == symbol && game->board[1][i] == symbol && game->board[2][i] == symbol){
            return 1;
        } else if(game->board[0][0] == symbol && game->board[1][1] == symbol && game->board[2][2] == symbol){
            return 1;
        } else if(game->board[2][0] == symbol && game->board[1][1] == symbol && game->board[0][2] == symbol){
            return 1;
        }
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

