/*
 * main.c
 *
 * SPDX-License-Identifier: Apache-2.0
 * SPDX-FileCopyrightText: 2026 Zeepunt
 */
#include <stdio.h>

#include "nvs_flash.h"

#include "argtable3/argtable3.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_err.h"
#include "esp_log.h"

#include "mod_console.h"
#include "mod_fs.h"

static const char *TAG = "main";

void app_main(void)
{
    esp_err_t err = ESP_OK;

    /* NVS */
    err = nvs_flash_init();
    if ((err == ESP_ERR_NVS_NO_FREE_PAGES) || (err == ESP_ERR_NVS_NEW_VERSION_FOUND)) {
        ESP_LOGW(TAG, "Erase NVS flash");
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();

        if (err != ESP_OK) {
            ESP_LOGE(TAG, "NVS init failed: %s", esp_err_to_name(err));
        }
    }

    mod_fs_init(MOD_FS_SPIFFS);
    mod_console_init();

    // TODO application startup
    ESP_LOGI(TAG, "Application startup");

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
