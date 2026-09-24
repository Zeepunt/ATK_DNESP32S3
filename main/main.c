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
#include "esp_console.h"

#define CMD_PROMPT "cmd>"

static const char *TAG = "main";

static esp_console_repl_t *s_repl = NULL;

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

    /* Console */
    esp_console_repl_config_t repl_config = ESP_CONSOLE_REPL_CONFIG_DEFAULT();
    repl_config.task_stack_size = 4 * 1024;
    repl_config.prompt = CMD_PROMPT;

    esp_console_dev_uart_config_t uart_config = ESP_CONSOLE_DEV_UART_CONFIG_DEFAULT();

    err = esp_console_new_repl_uart(&uart_config, &repl_config, &s_repl);
    if (err == ESP_OK) {
        err = esp_console_start_repl(s_repl);
        if (err != ESP_OK) {
            ESP_LOGE(TAG, "Console start repl failed: %s", esp_err_to_name(err));
        }
    }

    // TODO application startup
    ESP_LOGI(TAG, "Application startup");

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
