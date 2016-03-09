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

#ifndef GPIO_H_
#define GPIO_H_

#include "./def.h"
#include "../../lib/include/stdbool.h"
#include "../../lib/include/stdint.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifndef pin_check
#define pin_check(_CONT_, _PIN_, _VAL_) _gpio_pin_check(&(_CONT_)->gpio, _PIN_, _VAL_)
#endif // pin_check

#ifndef pin_clear
#define pin_clear(_CONT_, _PIN_) _gpio_pin_clear(&(_CONT_)->gpio, _PIN_)
#endif // pin_clear

#ifndef pin_config
#define pin_config(_CONT_, _PIN_, _TYPE_) _gpio_pin_config(&(_CONT_)->gpio, _PIN_, _TYPE_)
#endif // pin_config

#ifndef pin_set
#define pin_set(_CONT_, _PIN_) _gpio_pin_set(&(_CONT_)->gpio, _PIN_)
#endif // pin_set

typedef enum {
	GPIO_PIN_INPUT = 0,
	GPIO_PIN_OUTPUT,
} gpio_pin_t;

typedef struct {
	bool init;
	volatile uint32_t *base;
} gpio_t;

void _gpio_pin_check(
	__in gpio_t *cont,
	__in uint32_t pin,
	__out bool *val
	);

void _gpio_pin_clear(
	__in gpio_t *cont,
	__in uint32_t pin
	);

void _gpio_pin_config(
	__in gpio_t *cont,
	__in uint32_t pin,
	__in gpio_pin_t type
	);

void _gpio_pin_set(
	__in gpio_t *cont,
	__in uint32_t pin
	);

void gpio_init(
	__inout gpio_t *cont,
	__in volatile void *base
	);

void gpio_uninit(
	__inout gpio_t *cont
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // GPIO_H_
