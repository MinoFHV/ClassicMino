#include <driver/gpio.h>
#include <esp_log.h>
#include <esp_rom_sys.h>

#include "nes_controller.h"


// Define GPIO Pins
#define NC_LATCH_PIN        0
#define NC_CLOCK_PIN        1
#define NC_DATA_PIN         4

// Constants
#define LATCH_TIME_US       12
#define CLOCK_DUTY_TIME     6


void nesControllerInit()
{

    // GPIO Config for Latch
    gpio_config_t gpioLatchConfig =
    {
        .pin_bit_mask = (1 << NC_LATCH_PIN),
        .mode = GPIO_MODE_OUTPUT, // from MCU to Controller
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    // GPIO Config for Clock
    gpio_config_t gpioClockConfig =
    {
        .pin_bit_mask = (1 << NC_CLOCK_PIN),
        .mode = GPIO_MODE_OUTPUT, // from MCU to Controller
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    // GPIO Config for Data
    gpio_config_t gpioDataConfig =
    {
        .pin_bit_mask = (1 << NC_DATA_PIN),
        .mode = GPIO_MODE_INPUT, // from Controll (Shift Register) to MCU
        .pull_up_en = GPIO_PULLUP_ENABLE, // Negative True, thus Pullup
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    // Active the GPIO Configurations
    gpio_config(&gpioLatchConfig);
    gpio_config(&gpioClockConfig);
    gpio_config(&gpioDataConfig);

}

uint8_t nesControllerRead()
{

    // Set Latch to HIGH for 12µs
    // Save Button States in Internal Shift Register of NES Controller
    gpio_set_level(NC_LATCH_PIN, 1);
    esp_rom_delay_us(LATCH_TIME_US);
    gpio_set_level(NC_LATCH_PIN, 0);

    uint8_t allButtonStates = 0;

    // Read all 8 bits out for each clock cycle
    for (uint8_t cycle = 0; cycle < 8; ++cycle)
    {
        
        // Set Clock signal to HIGH
        gpio_set_level(NC_CLOCK_PIN, 1);
        allButtonStates |= (gpio_get_level(NC_DATA_PIN) << cycle);
        esp_rom_delay_us(CLOCK_DUTY_TIME);
        gpio_set_level(NC_CLOCK_PIN, 0);
        esp_rom_delay_us(CLOCK_DUTY_TIME);

    }
    
    return ~allButtonStates;

}