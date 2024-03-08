
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "playGame.h"
#include "endGame.h"

/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {

    Game *game; // pointer for the game structure
    
    // take in dimensions
    int gridsize = atoi(argv[1]);
    int winlen = atoi(argv[2]);
    
    // allocate memory and assign starting values to the structure
    game = initGame(gridsize, winlen);
    
    if(game != NULL){
        // play a full game
        playGame(game, gridsize, winlen);
    }

    free( game ); // free heap memory that was used

  return 0;
}

