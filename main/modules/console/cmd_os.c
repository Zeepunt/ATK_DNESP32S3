/*
 * cmd_os.c
 *
 * SPDX-License-Identifier: Apache-2.0
 * SPDX-FileCopyrightText: 2026 Zeepunt
 */
#include "esp_err.h"
#include "esp_log.h"
#include "esp_heap_caps.h"
#include "esp_console.h"

static const char *TAG = "cmd_os";

static int priv_free_cmd(int argc, char **argv)
{
    (void)(argc);
    (void)(argv);

    uint32_t caps = MALLOC_CAP_DEFAULT | MALLOC_CAP_INTERNAL;
    printf("[SRAM] size:%zu, free: %zu, min free: %zu\n", heap_caps_get_total_size(caps), heap_caps_get_free_size(caps), heap_caps_get_minimum_free_size(caps));

#if CONFIG_SPIRAM
    caps = MALLOC_CAP_DEFAULT | MALLOC_CAP_SPIRAM;
    printf("[PSRAM] size:%zu, free: %zu, min free: %zu\n", heap_caps_get_total_size(caps), heap_caps_get_free_size(caps), heap_caps_get_minimum_free_size(caps));
#endif

    /* 返回 0 表示执行成功 */
    return 0;
}

static const esp_console_cmd_t s_os_cmd[] = {
    {
        .command = "free",
        .help = "Print Memory Information",
        .hint = NULL,
        .func = priv_free_cmd,
    },
};

void cmd_os_init(void)
{
    esp_err_t err = ESP_OK;

    for (size_t i = 0; i < sizeof(s_os_cmd) / sizeof(s_os_cmd[0]); i++) {
        err = esp_console_cmd_register(&s_os_cmd[i]);
        if (err != ESP_OK) {
            ESP_LOGE(TAG, "%s register failed: %s", s_os_cmd[i].command, esp_err_to_name(err));
        }
    }
}
