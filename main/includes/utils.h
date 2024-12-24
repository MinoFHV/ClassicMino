#pragma once

#include <stdint.h>


#define RNG_DATA_REG_ADDRESS    0x600260B0

uint32_t getNextRNG();
void printNESButtonBinary(uint8_t value);