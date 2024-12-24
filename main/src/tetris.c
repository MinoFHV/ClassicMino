#include <stdint.h>
#include <esp_log.h>
#include <esp_timer.h>
#include <stdint.h>

#include "nes_controller.h"
#include "tetris.h"
#include "utils.h"


void gameLoop()
{

    uint64_t frameStartUS = 0;
    uint64_t frameWaitTimeUS = 0;
    uint64_t frameCount = 0;
    uint8_t gravityTimer = 0;
    uint8_t nesControllerButtonStates = 0b00000000;

    while (1)
    {

        frameStartUS = esp_timer_get_time();
        nesControllerButtonStates = nesControllerRead();

        if (frameCount % 60 == 0)
            ESP_LOGI("Game Loop", "A second has passed, currently at %llu", frameCount);

        if ((nesControllerButtonStates >> BUTTON_LEFT_BITPOS) & 1)
            ESP_LOGI("Game Loop", "Pressed Left!");
        if ((nesControllerButtonStates >> BUTTON_RIGHT_BITPOS) & 1)
            ESP_LOGI("Game Loop", "Pressed Right!");
        if ((nesControllerButtonStates >> BUTTON_UP_BITPOS) & 1)
            ESP_LOGI("Game Loop", "Pressed Up!");
        if ((nesControllerButtonStates >> BUTTON_DOWN_BITPOS) & 1)
            ESP_LOGI("Game Loop", "Pressed Down!");

        frameCount++;

        frameWaitTimeUS = FRAME_TIME_US - (esp_timer_get_time() - frameStartUS);
        if (frameWaitTimeUS > 0)
            esp_rom_delay_us(frameWaitTimeUS);

    }

}

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