#include <stdint.h>

#include "tetris.h"
#include "utils.h"

// This algorithm is the official piece selection algorithm of Classic NES Tetris
// See: https://meatfighter.com/nintendotetrisai/#Picking_Tetriminos
//    : https://www.reddit.com/r/Tetris/comments/6o6tvv/comment/dkf3uy1
uint8_t selectNextPiece()
{

    // Memory variable for last roll, init as an invalid piece
    static uint8_t lastRoll = -1;

    // Roll a 8-sided die (0-6 = Pieces, 7 = Reroll)
    uint8_t nextPieceRoll = (uint8_t) (getNextRNG() % 8);

    // Check if 7 or same piece as before, then reroll, else piece take the piece
    if ((nextPieceRoll == 7) || (nextPieceRoll == lastRoll))
    {
        nextPieceRoll = (uint8_t) (getNextRNG() % 7);
    }

    lastRoll = nextPieceRoll;
    return nextPieceRoll;

}