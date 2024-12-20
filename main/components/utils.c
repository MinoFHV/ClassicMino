#include <stdint.h>

#include "utils.h"


uint32_t getNextRNG()
{
    return *((uint32_t*) RNG_DATA_REG_ADDRESS);
}

void printNESButtonBinary(uint8_t value) {
    char bin_str[9] = {0};

    for (uint8_t i = 7; i >= 0; i--) {
        bin_str[7 - i] = (value >> i) & 1 ? '1' : '0';
    }

    ESP_LOGI("NES Controller", "Binary representation: %s", bin_str);
}