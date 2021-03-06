/**
 * @file    swd_host_mulit.h
 * @brief   Host driver for accessing the DAP
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2019, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _SWD_HOST_MULTI_H
#define _SWD_HOST_MULTI_H

#include "flash_blob.h"
#include "target_reset.h"
#ifdef TARGET_MCU_CORTEX_A
#include "debug_ca.h"
#else
#include "debug_cm.h"
#endif

#include "swd_host.h"

#ifdef __cplusplus
extern "C" {
#endif

//typedef enum {
//    CONNECT_NORMAL,
//    CONNECT_UNDER_RESET,
//} SWD_CONNECT_TYPE;



uint8_t MUL_swd_init(void);
uint8_t MUL_swd_off(void);
uint8_t MUL_swd_init_debug(void);
uint8_t MUL_MUL_swd_clear_errors(void);
uint8_t *MUL_swd_read_dp(uint8_t adr, uint32_t *val);
uint8_t MUL_swd_write_dp(uint8_t adr, uint32_t val);
uint8_t MUL_swd_read_ap(uint32_t adr, uint32_t *val);
uint8_t MUL_swd_write_ap(uint32_t adr, uint32_t val);
uint8_t MUL_swd_read_word(uint32_t addr, uint32_t *val);
uint8_t MUL_swd_write_word(uint32_t addr, uint32_t val);
uint8_t MUL_swd_read_byte(uint32_t addr, uint8_t *val);
uint8_t MUL_swd_write_byte(uint32_t addr, uint8_t val);
uint8_t MUL_swd_read_memory(uint32_t address, uint8_t *data, uint32_t size);
uint8_t MUL_swd_write_memory(uint32_t address, uint8_t *data, uint32_t size);
uint8_t MUL_swd_read_core_register(uint32_t n, uint32_t *val);
uint8_t MUL_swd_write_core_register(uint32_t n, uint32_t val);
uint8_t MUL_swd_flash_syscall_exec(const program_syscall_t *sysCallParam, uint32_t entry, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4);
uint32_t MUL_swd_flash_syscall_exec_ex(const program_syscall_t *sysCallParam, uint32_t entry, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4);
uint8_t MUL_swd_set_target_state_hw(TARGET_RESET_STATE state);
uint8_t MUL_swd_set_target_state_sw(TARGET_RESET_STATE state);
uint8_t *MUL_swd_transfer_retry(uint32_t req, uint32_t *data);
void MUL_int2array(uint8_t *res, uint32_t data, uint8_t len);
void MUL_swd_set_reset_connect(SWD_CONNECT_TYPE type);
void MUL_swd_set_soft_reset(uint32_t soft_reset_type);


uint8_t MUL_swd_read_idcode(uint32_t *id);

#ifdef __cplusplus
}
#endif

#endif
