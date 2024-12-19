#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>

#include "nes_controller.h"


void print_binary(uint8_t value) {
    char bin_str[9] = {0};  // 8 bits + null-terminator

    for (int i = 7; i >= 0; i--) {
        bin_str[7 - i] = (value >> i) & 1 ? '1' : '0';
    }

    ESP_LOGI("NES Controller", "Binary representation: %s", bin_str);
}

void app_main(void)
{

    nesControllerInit();

    while (1)
    { 

        print_binary(nesControllerRead());
        vTaskDelay(2000 / portTICK_PERIOD_MS);

    }

}