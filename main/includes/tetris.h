#pragma once

#include <stdint.h>


// Frame Definitions
#define FRAME_TIME_US     (1000000 / 60)      // 60 FPS

void gameLoop();
uint8_t selectNextPiece();