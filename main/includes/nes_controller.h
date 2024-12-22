#pragma once

// Define GPIO Pins
#define NC_LATCH_PIN                0
#define NC_CLOCK_PIN                1
#define NC_DATA_PIN                 4

// Constants
#define LATCH_TIME_US               12
#define POST_LATCH_WAIT_TIME_US     6
#define CLOCK_DUTY_TIME_US          6

void nesControllerInit();
uint8_t nesControllerRead();