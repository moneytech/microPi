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

#include "../include/err.h"
#include "../include/gpio.h"
#include "../include/mem.h"
#include "../include/uart.h"

#ifdef RPI_1
#define UART_DR 0
#define UART_RSRECR 1
#define UART_FR 6
#define UART_ILPR 8
#define UART_IBRD 9
#define UART_FBRD 10
#define UART_LCRH 11
#define UART_CR 12
#define UART_IFLS 13
#define UART_IMSC 14
#define UART_RIS 15
#define UART_MIS 16
#define UART_ICR 17
#define UART_DMACR 18
#define UART_ITCR 32
#define UART_ITIP 33
#define UART_ITOP 34
#define UART_TDR 35
#define UART_PIN_RX 15
#define UART_PIN_TX 14
#endif // RPI_1

uint8_t 
_uart_read(
	__in const uart_t *cont
	)
{
	uint8_t res = 0;

	if(!cont) {
		kerrno = KEINVAL;
		goto exit;
	}

	// TODO

exit:
	return res;
}

void 
_uart_write(
	__in const uart_t *cont,
	__in uint8_t val
	)
{

	if(!cont) {
		kerrno = KEINVAL;
		goto exit;
	}

	// TODO
	__ref(val);
	// ---

exit:
	return;
}

void 
_uart_write_mul(
	__in const uart_t *cont,
	__in const uint8_t *val,
	__in size_t len
	)
{

	if(!cont || !val || !len) {
		kerrno = KEINVAL;
		goto exit;
	}

	// TODO
	__ref(val);
	__ref(len);
	// ---

exit:
	return;
}

void 
uart_init(
	__inout uart_t *cont,
	__in const void *gpio,
	__in volatile void *base
	)
{

	if(!cont || !gpio) {
		kerrno = KEINVAL;
		goto exit;
	}

	mem_set(cont, 0, sizeof(uart_t));
	cont->base = base;

#ifdef RPI_1
	// TODO
#endif // RPI_1	

exit:
	return;
}

void 
uart_uninit(
	__inout uart_t *cont
	)
{

	if(!cont) {
		kerrno = KEINVAL;
		goto exit;
	}

	mem_set(cont, 0, sizeof(uart_t));

exit:
	return;
}
