#pragma once

#ifndef RNG_DATA_REG_ADDRESS
#define RNG_DATA_REG_ADDRESS    0x600260B0
#endif

uint32_t getNextRNG();
void printNESButtonBinary(uint8_t value);