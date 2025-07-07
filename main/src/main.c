#include <sdkconfig.h>

#include "lcd.h"
#include "nes_controller.h"
#include "utils.h"

#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


#define FREERTOS_INTERVAL_PER_FRAME     ((TickType_t)10)


void app_main(void)
{

    TickType_t last_wake_time = xTaskGetTickCount();

    nesControllerInit();
    uint32_t ticksSinceStart = 0;

    while (1)
    {
        //printNESButtonBinary(nesControllerRead());
        if ((ticksSinceStart % 60) == 0)
        {
            ESP_LOGI("FreeRTOS", "Tick Tack!");
        }

        ++ticksSinceStart;
        vTaskDelayUntil(&last_wake_time, FREERTOS_INTERVAL_PER_FRAME);
    }
}
