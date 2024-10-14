/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "esp_chip_info.h"
#include "esp_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "iot_button.h"
#include "led.h"
#include "sdkconfig.h"
#include <inttypes.h>
#include <stdio.h>

void app_main(void) {
  led_init();

  while (1) {
    led_blink();
  }
}
