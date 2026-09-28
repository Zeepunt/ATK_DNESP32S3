/*
 * mod_console.h
 *
 * SPDX-License-Identifier: Apache-2.0
 * SPDX-FileCopyrightText: 2026 Zeepunt
 */
#ifndef __MOD_CONSOLE_H__
#define __MOD_CONSOLE_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize Console Module
 * @return
 *  - 0: success
 *  - -1: failure
 */
int mod_console_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __MOD_CONSOLE_H__ */
