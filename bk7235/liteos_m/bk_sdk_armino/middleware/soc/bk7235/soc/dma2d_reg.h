/*
 * Copyright (C) 2022 Beken Corporation
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef __cplusplus
 extern "C" {
#endif


 /******************************************************************************/
 /*                                                                            */
 /*                         AHB Master DMA2D Controller (DMA2D)               */
 /*                                                                            */
 /******************************************************************************/

 /********************  Bit definition for DMA2D_CR register  ******************/

#include <stdint.h>


/* REG_0x00 */
#define DMA2D_DMA2D_CONTROL_REG_ADDR  (DMA2D_LL_REG_BASE  + 0x0)
#define DMA2D_DMA2D_CONTROL_REG_TRAN_START_POS (0)
#define DMA2D_DMA2D_CONTROL_REG_TRAN_START_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_TRAN_SUSPEND_POS (1)
#define DMA2D_DMA2D_CONTROL_REG_TRAN_SUSPEND_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_TRAN_ABORT_POS (2)
#define DMA2D_DMA2D_CONTROL_REG_TRAN_ABORT_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_RESERVED_POS (3)
#define DMA2D_DMA2D_CONTROL_REG_RESERVED_MASK (0x7)

#define DMA2D_DMA2D_CONTROL_REG_LINE_OFFSET_MODE_POS (6)
#define DMA2D_DMA2D_CONTROL_REG_LINE_OFFSET_MODE_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_RESERVED_POS (7)
#define DMA2D_DMA2D_CONTROL_REG_RESERVED_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_ERROR_INT_EN_POS (8)
#define DMA2D_DMA2D_CONTROL_REG_ERROR_INT_EN_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_COMPLETE_INT_EN_POS (9)
#define DMA2D_DMA2D_CONTROL_REG_COMPLETE_INT_EN_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_WATERM_INT_EN_POS (10)
#define DMA2D_DMA2D_CONTROL_REG_WATERM_INT_EN_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_CLUT_ERROR_INT_EN_POS (11)
#define DMA2D_DMA2D_CONTROL_REG_CLUT_ERROR_INT_EN_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_CLUT_CMPLT_INT_EN_POS (12)
#define DMA2D_DMA2D_CONTROL_REG_CLUT_CMPLT_INT_EN_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_CONFIG_ERROR_INT_EN_POS (13)
#define DMA2D_DMA2D_CONTROL_REG_CONFIG_ERROR_INT_EN_MASK (0x1)

#define DMA2D_DMA2D_CONTROL_REG_RESERVED_POS (14)
#define DMA2D_DMA2D_CONTROL_REG_RESERVED_MASK (0x3)

#define DMA2D_DMA2D_CONTROL_REG_MODE_POS (16)
#define DMA2D_DMA2D_CONTROL_REG_MODE_MASK (0x7)

#define DMA2D_DMA2D_CONTROL_REG_RESERVED_POS (19)
#define DMA2D_DMA2D_CONTROL_REG_RESERVED_MASK (0x1FFF)

/* REG_0x01 */
#define DMA2D_DMA2D_INT_STATUS_ADDR  (DMA2D_LL_REG_BASE  + 0x1)
#define DMA2D_DMA2D_INT_STATUS_ERROR_INT_POS (0)
#define DMA2D_DMA2D_INT_STATUS_ERROR_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_STATUS_COMPLETE_INT_POS (1)
#define DMA2D_DMA2D_INT_STATUS_COMPLETE_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_STATUS_WATERM_INT_POS (2)
#define DMA2D_DMA2D_INT_STATUS_WATERM_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_STATUS_CLUT_ERROR_INT_POS (3)
#define DMA2D_DMA2D_INT_STATUS_CLUT_ERROR_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_STATUS_CLUT_CMPLT_INT_POS (4)
#define DMA2D_DMA2D_INT_STATUS_CLUT_CMPLT_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_STATUS_CONFIG_ERROR_INT_POS (5)
#define DMA2D_DMA2D_INT_STATUS_CONFIG_ERROR_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_STATUS_RESERVED_POS (6)
#define DMA2D_DMA2D_INT_STATUS_RESERVED_MASK (0x3FFFFFF)

/* REG_0x02 */
#define DMA2D_DMA2D_INT_CLEAR_ADDR  (DMA2D_LL_REG_BASE  + 0x2)
#define DMA2D_DMA2D_INT_CLEAR_CLR_ERROR_INT_POS (0)
#define DMA2D_DMA2D_INT_CLEAR_CLR_ERROR_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_CLEAR_CLR_COMPLETE_INT_POS (1)
#define DMA2D_DMA2D_INT_CLEAR_CLR_COMPLETE_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_CLEAR_CLR_WATERM_INT_POS (2)
#define DMA2D_DMA2D_INT_CLEAR_CLR_WATERM_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_CLEAR_CLR_CLUT_ERROR_INT_POS (3)
#define DMA2D_DMA2D_INT_CLEAR_CLR_CLUT_ERROR_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_CLEAR_CLR_CLUT_CMPLT_INT_POS (4)
#define DMA2D_DMA2D_INT_CLEAR_CLR_CLUT_CMPLT_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_CLEAR_CLR_CONFIG_ERROR_INT_POS (5)
#define DMA2D_DMA2D_INT_CLEAR_CLR_CONFIG_ERROR_INT_MASK (0x1)

#define DMA2D_DMA2D_INT_CLEAR_RESERVED_POS (6)
#define DMA2D_DMA2D_INT_CLEAR_RESERVED_MASK (0x3FFFFFF)

/* REG_0x03 */
#define DMA2D_DMA2D_FG_ADDRESS_ADDR  (DMA2D_LL_REG_BASE  + 0x3)
#define DMA2D_DMA2D_FG_ADDRESS_FG_ADDRESS_POS (0)
#define DMA2D_DMA2D_FG_ADDRESS_FG_ADDRESS_MASK (0xFFFFFFFF)

/* REG_0x04 */
#define DMA2D_DMA2D_FG_OFFSET_ADDR  (DMA2D_LL_REG_BASE  + 0x4)
#define DMA2D_DMA2D_FG_OFFSET_FG_LINE_OFFSET_POS (0)
#define DMA2D_DMA2D_FG_OFFSET_FG_LINE_OFFSET_MASK (0xFFFF)

#define DMA2D_DMA2D_FG_OFFSET_RESERVED_POS (16)
#define DMA2D_DMA2D_FG_OFFSET_RESERVED_MASK (0xFFFF)

/* REG_0x05 */
#define DMA2D_DMA2D_BG_ADDRESS_ADDR  (DMA2D_LL_REG_BASE  + 0x5)
#define DMA2D_DMA2D_BG_ADDRESS_BG_ADDRESS_POS (0)
#define DMA2D_DMA2D_BG_ADDRESS_BG_ADDRESS_MASK (0xFFFFFFFF)

/* REG_0x06 */
#define DMA2D_DMA2D_BG_OFFSET_ADDR  (DMA2D_LL_REG_BASE  + 0x6)
#define DMA2D_DMA2D_BG_OFFSET_BG_LINE_OFFSET_POS (0)
#define DMA2D_DMA2D_BG_OFFSET_BG_LINE_OFFSET_MASK (0xFFFF)

#define DMA2D_DMA2D_BG_OFFSET_RESERVED_POS (16)
#define DMA2D_DMA2D_BG_OFFSET_RESERVED_MASK (0xFFFF)

/* REG_0x07 */
#define DMA2D_DMA2D_FG_PFC_CTRL_ADDR  (DMA2D_LL_REG_BASE  + 0x7)
#define DMA2D_DMA2D_FG_PFC_CTRL_FG_COLOR_MODE_POS (0)
#define DMA2D_DMA2D_FG_PFC_CTRL_FG_COLOR_MODE_MASK (0xF)

#define DMA2D_DMA2D_FG_PFC_CTRL_FG_CLUT_COLOR_MODE_POS (4)
#define DMA2D_DMA2D_FG_PFC_CTRL_FG_CLUT_COLOR_MODE_MASK (0x1)

#define DMA2D_DMA2D_FG_PFC_CTRL_FG_START_CLUT_POS (5)
#define DMA2D_DMA2D_FG_PFC_CTRL_FG_START_CLUT_MASK (0x1)

#define DMA2D_DMA2D_FG_PFC_CTRL_RESERVED_POS (6)
#define DMA2D_DMA2D_FG_PFC_CTRL_RESERVED_MASK (0x3)

#define DMA2D_DMA2D_FG_PFC_CTRL_FG_CLUT_SIZE_POS (8)
#define DMA2D_DMA2D_FG_PFC_CTRL_FG_CLUT_SIZE_MASK (0xFF)

#define DMA2D_DMA2D_FG_PFC_CTRL_FG_ALPHA_MODE_POS (16)
#define DMA2D_DMA2D_FG_PFC_CTRL_FG_ALPHA_MODE_MASK (0x3)

#define DMA2D_DMA2D_FG_PFC_CTRL_RESERVED_POS (18)
#define DMA2D_DMA2D_FG_PFC_CTRL_RESERVED_MASK (0x3)

#define DMA2D_DMA2D_FG_PFC_CTRL_ALPHA_INVERT_POS (20)
#define DMA2D_DMA2D_FG_PFC_CTRL_ALPHA_INVERT_MASK (0x1)

#define DMA2D_DMA2D_FG_PFC_CTRL_FG_RB_SWAP_POS (21)
#define DMA2D_DMA2D_FG_PFC_CTRL_FG_RB_SWAP_MASK (0x1)

#define DMA2D_DMA2D_FG_PFC_CTRL_RESERVED_POS (22)
#define DMA2D_DMA2D_FG_PFC_CTRL_RESERVED_MASK (0x3)

#define DMA2D_DMA2D_FG_PFC_CTRL_FG_ALPHA_POS (24)
#define DMA2D_DMA2D_FG_PFC_CTRL_FG_ALPHA_MASK (0xFF)

/* REG_0x08 */
#define DMA2D_DMA2D_FG_COLOR_REG_ADDR  (DMA2D_LL_REG_BASE  + 0x8)
#define DMA2D_DMA2D_FG_COLOR_REG_BLUE_VALUE_POS (0)
#define DMA2D_DMA2D_FG_COLOR_REG_BLUE_VALUE_MASK (0xFF)

#define DMA2D_DMA2D_FG_COLOR_REG_GREEN_VALUE_POS (8)
#define DMA2D_DMA2D_FG_COLOR_REG_GREEN_VALUE_MASK (0xFF)

#define DMA2D_DMA2D_FG_COLOR_REG_RED_VALUE_POS (16)
#define DMA2D_DMA2D_FG_COLOR_REG_RED_VALUE_MASK (0xFF)

#define DMA2D_DMA2D_FG_COLOR_REG_RESERVED_POS (24)
#define DMA2D_DMA2D_FG_COLOR_REG_RESERVED_MASK (0xFF)

/* REG_0x09 */
#define DMA2D_DMA2D_BG_PFC_CTRL_ADDR  (DMA2D_LL_REG_BASE  + 0x9)
#define DMA2D_DMA2D_BG_PFC_CTRL_BG_COLOR_MODE_POS (0)
#define DMA2D_DMA2D_BG_PFC_CTRL_BG_COLOR_MODE_MASK (0xF)

#define DMA2D_DMA2D_BG_PFC_CTRL_BG_CLUT_COLOR_MODE_POS (4)
#define DMA2D_DMA2D_BG_PFC_CTRL_BG_CLUT_COLOR_MODE_MASK (0x1)

#define DMA2D_DMA2D_BG_PFC_CTRL_BG_START_CLUT_POS (5)
#define DMA2D_DMA2D_BG_PFC_CTRL_BG_START_CLUT_MASK (0x1)

#define DMA2D_DMA2D_BG_PFC_CTRL_RESERVED_POS (6)
#define DMA2D_DMA2D_BG_PFC_CTRL_RESERVED_MASK (0x3)

#define DMA2D_DMA2D_BG_PFC_CTRL_BG_CLUT_SIZE_POS (8)
#define DMA2D_DMA2D_BG_PFC_CTRL_BG_CLUT_SIZE_MASK (0xFF)

#define DMA2D_DMA2D_BG_PFC_CTRL_BG_ALPHA_MODE_POS (16)
#define DMA2D_DMA2D_BG_PFC_CTRL_BG_ALPHA_MODE_MASK (0x3)

#define DMA2D_DMA2D_BG_PFC_CTRL_RESERVED_POS (18)
#define DMA2D_DMA2D_BG_PFC_CTRL_RESERVED_MASK (0x3)

#define DMA2D_DMA2D_BG_PFC_CTRL_ALPHA_INVERT_POS (20)
#define DMA2D_DMA2D_BG_PFC_CTRL_ALPHA_INVERT_MASK (0x1)

#define DMA2D_DMA2D_BG_PFC_CTRL_BG_RB_SWAP_POS (21)
#define DMA2D_DMA2D_BG_PFC_CTRL_BG_RB_SWAP_MASK (0x1)

#define DMA2D_DMA2D_BG_PFC_CTRL_RESERVED_POS (22)
#define DMA2D_DMA2D_BG_PFC_CTRL_RESERVED_MASK (0x3)

#define DMA2D_DMA2D_BG_PFC_CTRL_BG_ALPHA_POS (24)
#define DMA2D_DMA2D_BG_PFC_CTRL_BG_ALPHA_MASK (0xFF)

/* REG_0x0A */
#define DMA2D_DMA2D_BG_COLOR_REG_ADDR  (DMA2D_LL_REG_BASE  + 0xA)
#define DMA2D_DMA2D_BG_COLOR_REG_BLUE_VALUE_POS (0)
#define DMA2D_DMA2D_BG_COLOR_REG_BLUE_VALUE_MASK (0xFF)

#define DMA2D_DMA2D_BG_COLOR_REG_GREEN_VALUE_POS (8)
#define DMA2D_DMA2D_BG_COLOR_REG_GREEN_VALUE_MASK (0xFF)

#define DMA2D_DMA2D_BG_COLOR_REG_RED_VALUE_POS (16)
#define DMA2D_DMA2D_BG_COLOR_REG_RED_VALUE_MASK (0xFF)

#define DMA2D_DMA2D_BG_COLOR_REG_RESERVED_POS (24)
#define DMA2D_DMA2D_BG_COLOR_REG_RESERVED_MASK (0xFF)

/* REG_0x0B */
#define DMA2D_FG_CLUT_MEM_ADDRESS_ADDR  (DMA2D_LL_REG_BASE  + 0xB)
#define DMA2D_FG_CLUT_MEM_ADDRESS_FG_CLUT_ADDRESS_POS (0)
#define DMA2D_FG_CLUT_MEM_ADDRESS_FG_CLUT_ADDRESS_MASK (0xFFFFFFFF)

/* REG_0x0C */
#define DMA2D_BG_CLUT_MEM_ADDRESS_ADDR  (DMA2D_LL_REG_BASE  + 0xC)
#define DMA2D_BG_CLUT_MEM_ADDRESS_BG_CLUT_ADDRESS_POS (0)
#define DMA2D_BG_CLUT_MEM_ADDRESS_BG_CLUT_ADDRESS_MASK (0xFFFFFFFF)

/* REG_0x0D */
#define DMA2D_OUT_PFC_CONTRL_ADDR  (DMA2D_LL_REG_BASE  + 0xD)
#define DMA2D_OUT_PFC_CONTRL_OUT_COLOR_MODE_POS (0)
#define DMA2D_OUT_PFC_CONTRL_OUT_COLOR_MODE_MASK (0x7)

#define DMA2D_OUT_PFC_CONTRL_RESERVED_POS (3)
#define DMA2D_OUT_PFC_CONTRL_RESERVED_MASK (0x3F)

#define DMA2D_OUT_PFC_CONTRL_OUT_SWAP_BYTES_POS (9)
#define DMA2D_OUT_PFC_CONTRL_OUT_SWAP_BYTES_MASK (0x1)

#define DMA2D_OUT_PFC_CONTRL_RESERVED_POS (10)
#define DMA2D_OUT_PFC_CONTRL_RESERVED_MASK (0x3FF)

#define DMA2D_OUT_PFC_CONTRL_OUT_ALPHA_INVERT._POS (20)
#define DMA2D_OUT_PFC_CONTRL_OUT_ALPHA_INVERT._MASK (0x1)

#define DMA2D_OUT_PFC_CONTRL_OUT_RB_SWAP_POS (21)
#define DMA2D_OUT_PFC_CONTRL_OUT_RB_SWAP_MASK (0x1)

#define DMA2D_OUT_PFC_CONTRL_RESERVED_POS (22)
#define DMA2D_OUT_PFC_CONTRL_RESERVED_MASK (0x3FF)

/* REG_0x0E */
#define DMA2D_OUT_COLOR_REG_ADDR  (DMA2D_LL_REG_BASE  + 0xE)
#define DMA2D_OUT_COLOR_REG_OUTPUT_CLOR_REG_POS (0)
#define DMA2D_OUT_COLOR_REG_OUTPUT_CLOR_REG_MASK (0xFFFFFFFF)

/* REG_0x0F */
#define DMA2D_DMA2D_OUT_MEM_ADDRESS_ADDR  (DMA2D_LL_REG_BASE  + 0xF)
#define DMA2D_DMA2D_OUT_MEM_ADDRESS_OUT_MEM_ADDRESS_POS (0)
#define DMA2D_DMA2D_OUT_MEM_ADDRESS_OUT_MEM_ADDRESS_MASK (0xFFFFFFFF)

/* REG_0x10 */
#define DMA2D_OUTPUT_OFFSET_ADDR  (DMA2D_LL_REG_BASE  + 0x10)
#define DMA2D_OUTPUT_OFFSET_OUT_LINE_OFFSET_POS (0)
#define DMA2D_OUTPUT_OFFSET_OUT_LINE_OFFSET_MASK (0xFFFF)

#define DMA2D_OUTPUT_OFFSET_RESERVED_POS (16)
#define DMA2D_OUTPUT_OFFSET_RESERVED_MASK (0xFFFF)

/* REG_0x11 */
#define DMA2D_DMA2D_NUMBER_OF_LINE_ADDR  (DMA2D_LL_REG_BASE  + 0x11)
#define DMA2D_DMA2D_NUMBER_OF_LINE_NUMBER_LINE_POS (0)
#define DMA2D_DMA2D_NUMBER_OF_LINE_NUMBER_LINE_MASK (0xFFFF)

#define DMA2D_DMA2D_NUMBER_OF_LINE_PEXEL_LINE_POS (16)
#define DMA2D_DMA2D_NUMBER_OF_LINE_PEXEL_LINE_MASK (0x3FFF)

#define DMA2D_DMA2D_NUMBER_OF_LINE_RESERVED_POS (30)
#define DMA2D_DMA2D_NUMBER_OF_LINE_RESERVED_MASK (0x3)

/* REG_0x12 */
#define DMA2D_DMA2D_LINE_WATERMARK_ADDR  (DMA2D_LL_REG_BASE  + 0x12)
#define DMA2D_DMA2D_LINE_WATERMARK_LINE_WATERMARK_POS (0)
#define DMA2D_DMA2D_LINE_WATERMARK_LINE_WATERMARK_MASK (0xFFFF)

#define DMA2D_DMA2D_LINE_WATERMARK_RESERVED_POS (16)
#define DMA2D_DMA2D_LINE_WATERMARK_RESERVED_MASK (0xFFFF)

/* REG_0x18 */
#define DMA2D_DMA2D_MASTER_TIME_CONFIG_ADDR  (DMA2D_LL_REG_BASE  + 0x18)
#define DMA2D_DMA2D_MASTER_TIME_CONFIG_MASTER_TIME_ENA_POS (0)
#define DMA2D_DMA2D_MASTER_TIME_CONFIG_MASTER_TIME_ENA_MASK (0x1)

#define DMA2D_DMA2D_MASTER_TIME_CONFIG_RESERVED_POS (1)
#define DMA2D_DMA2D_MASTER_TIME_CONFIG_RESERVED_MASK (0x7F)

#define DMA2D_DMA2D_MASTER_TIME_CONFIG_DEAD_TIME_POS (8)
#define DMA2D_DMA2D_MASTER_TIME_CONFIG_DEAD_TIME_MASK (0xFF)

#define DMA2D_DMA2D_MASTER_TIME_CONFIG_RESERVED_POS (16)
#define DMA2D_DMA2D_MASTER_TIME_CONFIG_RESERVED_MASK (0xFFFF)

/* REG_0x100 */
#define DMA2D_DMA2D_FG_CLUT0_ADDR  (DMA2D_LL_REG_BASE  + 0x100)
#define DMA2D_DMA2D_FG_CLUT0_BLUE_POS (0)
#define DMA2D_DMA2D_FG_CLUT0_BLUE_MASK (0x1)

#define DMA2D_DMA2D_FG_CLUT0_GREEN_POS (0)
#define DMA2D_DMA2D_FG_CLUT0_GREEN_MASK (0x1)

#define DMA2D_DMA2D_FG_CLUT0_RED_POS (0)
#define DMA2D_DMA2D_FG_CLUT0_RED_MASK (0x1)

#define DMA2D_DMA2D_FG_CLUT0_ALPHA_POS (0)
#define DMA2D_DMA2D_FG_CLUT0_ALPHA_MASK (0x1)

/* REG_0x200 */
#define DMA2D_DMA2D_BG_CLUT0_ADDR  (DMA2D_LL_REG_BASE  + 0x200)
#define DMA2D_DMA2D_BG_CLUT0_BLUE_POS (0)
#define DMA2D_DMA2D_BG_CLUT0_BLUE_MASK (0x1)

#define DMA2D_DMA2D_BG_CLUT0_GREEN_POS (0)
#define DMA2D_DMA2D_BG_CLUT0_GREEN_MASK (0x1)

#define DMA2D_DMA2D_BG_CLUT0_RED_POS (0)
#define DMA2D_DMA2D_BG_CLUT0_RED_MASK (0x1)

#define DMA2D_DMA2D_BG_CLUT0_ALPHA_POS (0)
#define DMA2D_DMA2D_BG_CLUT0_ALPHA_MASK (0x1)

#ifdef __cplusplus
}
#endif

