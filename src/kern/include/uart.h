/**
 * μPi
 * Copyright (C) 2016 David Jolly
 * ----------------------
 *
 * μPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * μPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UART_H_
#define UART_H_

#include "./def.h"
#include "../../lib/include/stdbool.h"
#include "../../lib/include/stdint.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifndef uart_getc
#define uart_getc(_CONT_) _uart_read(_CONT_)
#endif // uart_getc

#ifndef uart_putc
#define uart_putc(_CONT_, _VAL_) _uart_write(_CONT_, _VAL_)
#endif // uart_putc

#ifndef uart_puts
#define uart_puts(_CONT_, _VAL_, _LEN_) _uart_write_mul(_CONT_, _VAL_, _LEN_)
#endif // uart_puts

typedef struct {
	volatile uint32_t *base;
} uart_t;

uint8_t _uart_read(
	__in const uart_t *cont
	);

void _uart_write(
	__in const uart_t *cont,
	__in uint8_t val
	);

void _uart_write_mul(
	__in const uart_t *cont,
	__in const uint8_t *val,
	__in size_t len
	);

void uart_init(
	__inout uart_t *cont,
	__in const void *gpio,
	__in volatile void *base
	);

void uart_uninit(
	__inout uart_t *cont
	);

// TODO

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // UART_H_
