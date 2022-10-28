// Copyright (C) 2022 Beken Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <common/bk_include.h>

#ifdef __cplusplus
extern "C" {
#endif

#if (!CONFIG_FLASH_ORIGIN_API)
#define PAR_OPT_READ_POS      (0)
#define PAR_OPT_WRITE_POS     (1)

#define PAR_OPT_READ_DIS      (0x0u << PAR_OPT_READ_POS)
#define PAR_OPT_READ_EN       (0x1u << PAR_OPT_READ_POS)
#define PAR_OPT_WRITE_DIS     (0x0u << PAR_OPT_WRITE_POS)
#define PAR_OPT_WRITE_EN      (0x1u << PAR_OPT_WRITE_POS)
#endif

typedef enum
{
	BK_FLASH_EMBEDDED,
	BK_FLASH_SPI,
	BK_FLASH_MAX,
	BK_FLASH_NONE,
} bk_flash_t;

typedef enum
{
	BK_PARTITION_BOOTLOADER = 0,
	BK_PARTITION_APPLICATION,
	BK_PARTITION_OTA,
#if (CONFIG_SOC_BK7256XX)
	BK_PARTITION_APPLICATION1,
#endif
	BK_PARTITION_MATTER_FLASH,
	BK_PARTITION_RF_FIRMWARE,
	BK_PARTITION_NET_PARAM,
	BK_PARTITION_USR_CONFIG,
	BK_PARTITION_MAX,
} bk_partition_t;

typedef struct
{
	bk_flash_t partition_owner;        /**< flash partition owners */
	const char *partition_description; /**< flash partition description */
	uint32_t partition_start_addr;     /**< flash partition start address */
	uint32_t partition_length;         /**< flash partition length */
	uint32_t partition_options;        /**< flash partition options */
} bk_logic_partition_t;

/**
 * @brief   Get the infomation of the specified flash area
 *
 * @param partition:  The target flash logical partition
 *
 * @return bk flash logic partition struct
 */
bk_logic_partition_t *bk_flash_partition_get_info(bk_partition_t partition);

/**
 * @brief   Erase an area on a Flash logical partition
 *
 * @note    Erase on an address will erase all data on a sector that the
 *          address is belonged to, this function does not save data that
 *          beyond the address area but in the affected sector, the data
 *          will be lost.
 *
 * @param  partition: The target flash logical partition which should be erased
 * @param  offset: Start address of the erased flash area
 * @param  size: Size of the erased flash area
 *
 * @return
 *    - BK_OK: succeed
 *    - others: other errors
 */
bk_err_t bk_flash_partition_erase(bk_partition_t partition, uint32_t offset, uint32_t size);

/**
 * @brief  Write data to an area on a Flash logical partition
 *
 * @param  partition: The target flash logical partition which should be written
 * @param  buffer: Pointer to the data buffer that will be written to flash
 * @param  off_set: The offset of write address
 * @param  buffer_len: The length of the buffer
 *
 * @return
 *    - BK_OK: succeed
 *    - others: other errors
 */
bk_err_t bk_flash_partition_write(bk_partition_t partition, const uint8_t *buffer, uint32_t offset, uint32_t buffer_len);

/**
 * @brief    Read data from an area on a Flash to data buffer in RAM
 *
 * @param    partition: The target flash logical partition which should be read
 * @param    out_buffer: Pointer to the data buffer that stores the data read from flash
 * @param    offsets: The offset of read address
 * @param    buffer_len: The length of the buffer
 *
 * @return
 *    - BK_OK: succeed
 *    - others: other errors
 */
bk_err_t bk_flash_partition_read(bk_partition_t partition, uint8_t *out_buffer, uint32_t offset, uint32_t buffer_len);

#ifdef __cplusplus
}
#endif

