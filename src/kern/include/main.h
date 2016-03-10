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

#ifndef MAIN_H_
#define MAIN_H_

#include "./atag.h"
#include "./def.h"
#include "./gpio.h"
#include "./mem.h"
#include "./uart.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct {
	uint32_t dev;
	uint32_t mach;
	atag_t atag;
	gpio_t gpio;
	uart_t uart;
} kern_t;

void kern_init(
	__inout kern_t *cont,
	__in uint32_t dev,
	__in uint32_t mach,
	__in volatile void *atags
	);

void kern_main(
	__in uint32_t dev,
	__in uint32_t mach,
	__in volatile void *atags
	);

void kern_proc(
	__inout kern_t *cont
	);

void kern_trap(
	__in const kern_t *cont,
	__in const char *msg
	);

void kern_uninit(
	__inout kern_t *cont
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // MAIN_H_
