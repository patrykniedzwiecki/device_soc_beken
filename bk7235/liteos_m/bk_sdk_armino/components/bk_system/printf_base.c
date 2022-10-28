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

#include <stdarg.h>
#include <driver/uart.h>
#include "bk_uart.h"
#include <common/sys_config.h>
#include <os/mem.h>
#include "printf_impl.h"


void bk_set_printf_port(uint8_t port_num);
int bk_get_printf_port(void);

static bool s_printf_init = false;
static uint8_t s_print_port = CONFIG_UART_PRINT_PORT;

bool printf_is_init(void)
{
	return s_printf_init;
}

bk_err_t bk_printf_deinit(void)
{
        s_printf_init = false;
#if (!CONFIG_SLAVE_CORE)
	bk_uart_deinit(bk_get_printf_port());
#endif
	printf_lock_deinit();
	return BK_OK;
}

bk_err_t bk_printf_init(void)
{
	int ret;

#if (!CONFIG_SLAVE_CORE)
        const uart_config_t config = {
                .baud_rate = UART_BAUD_RATE,
                .data_bits = UART_DATA_8_BITS,
                .parity = UART_PARITY_NONE,
                .stop_bits = UART_STOP_BITS_1,
                .flow_ctrl = UART_FLOWCTRL_DISABLE,
                .src_clk = UART_SCLK_XTAL_26M
        };
#endif

	ret = printf_lock_init();
        if (BK_OK != ret) {
                return ret;
        }

#if (!CONFIG_SLAVE_CORE)
        ret = bk_uart_init(bk_get_printf_port(), &config);
        if (BK_OK != ret)
		goto _bk_printf_init_fail;

#endif
	s_printf_init = true;

	return BK_OK;

#if (!CONFIG_SLAVE_CORE)
_bk_printf_init_fail:
	bk_printf_deinit();
	return ret;
#endif
}

void bk_null_printf(const char *fmt, ...)
{
}

int bk_get_printf_port(void) {
        return s_print_port;
}

void bk_set_printf_port(uint8_t port_num) {
#if (!CONFIG_SLAVE_CORE)
        if (s_print_port != port_num && port_num < UART_ID_MAX) {
                bk_printf_deinit();
                s_print_port = port_num;
                bk_printf_init();
        }
#endif
}
