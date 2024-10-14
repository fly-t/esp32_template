#include "driver/gpio.h"
#include "led.h"
#include "esp_log.h"


// 成对使用, 且顺序一定!!!
// 成对使用, 且顺序一定!!!
// 成对使用, 且顺序一定!!!
#include "freertos/FreeRTOS.h"  
#include "freertos/task.h"

static const char *TAG = "blink";

#define BLINK_GPIO 14

static uint8_t s_led_state = 0;

static void update_led(void)
{
    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(BLINK_GPIO, s_led_state);
}


void led_init(void)
{
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}
void led_on(void)
{
    s_led_state = 1;
    update_led();
}

void led_off(void)
{
    s_led_state = 0;
    update_led();
}

void led_blink(void){
        /* Toggle the LED state */
        update_led();
        s_led_state = !s_led_state;
        vTaskDelay(500/portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "s_led_state:%d",s_led_state);
}