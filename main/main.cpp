#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "lib/ds18b20/ds18b20.h"

extern "C"
{
    void mainTask(void *pvParameters)
    {
        ds18b20_init(4);
        while(1)
        {
            printf("Temp: %0.1f\n", ds18b20_get_temp());
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }

    void app_main(void)
    {
        xTaskCreatePinnedToCore(&mainTask, "mainTask", 2048, NULL, 5, NULL, 0);        
    }
}
