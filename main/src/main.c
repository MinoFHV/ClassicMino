#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>

#include "nes_controller.h"
#include "tetris.h"
#include "utils.h"


void app_main(void)
{

    nesControllerInit();

    while (1)
    { 

        printNESButtonBinary(nesControllerRead());
        vTaskDelay(2000 / portTICK_PERIOD_MS);

    }

}