#pragma once

// Define GPIO Pins
#ifndef NC_LATCH_PIN
#define NC_LATCH_PIN                0
#endif

#ifndef NC_CLOCK_PIN
#define NC_CLOCK_PIN                1
#endif

#ifndef NC_DATA_PIN
#define NC_DATA_PIN                 4
#endif

// Constants
#ifndef LATCH_TIME_US
#define LATCH_TIME_US               12
#endif

#ifndef POST_LATCH_WAIT_TIME_US
#define POST_LATCH_WAIT_TIME_US     6
#endif

#ifndef CLOCK_DUTY_TIME_US
#define CLOCK_DUTY_TIME_US          6
#endif

void nesControllerInit();
uint8_t nesControllerRead();