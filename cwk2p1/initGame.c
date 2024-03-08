
#include <stdio.h>
#include <stdlib.h>

#include "game.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {

    Game *game = (Game *)malloc(sizeof(Game));

    // For incorrect boardSize or winLength you should return a NULL pointer
    if(boardSize!=3 || winLength != 3){
        printf("Incorrect parameter values for board size or win length. Exiting\n");
        return NULL;
    }

    // Allocate the Game data structure
    // Initialise the Game data structure values
    // Board values should be set to '.' (unused location)
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            game->board[i][j] = '.';
        }
    }
    game->boardSize = boardSize;
    game->winLength = winLength;
    game->turns = 0;
    game->maxTurns = 9;
  
    return game;
}


