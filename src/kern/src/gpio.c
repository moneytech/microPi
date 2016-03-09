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

#include "../include/gpio.h"
#include "../include/err.h"
#include "../include/mem.h"

#ifdef RPI_1
#define GPIO_GPFSEL0 0
#define GPIO_GPFSEL1 1
#define GPIO_GPFSEL2 2
#define GPIO_GPFSEL3 3
#define GPIO_GPFSEL4 4
#define GPIO_GPFSEL5 5
#define GPIO_GPSET0 7
#define GPIO_GPSET1 8
#define GPIO_GPCLR0 10
#define GPIO_GPCLR1 11
#define GPIO_GPLEV0 13
#define GPIO_GPLEV1 14
#define GPIO_GPEDS0 16
#define GPIO_GPEDS1 17
#define GPIO_GPREN0 19
#define GPIO_GPREN1 20
#define GPIO_GPFEN0 22
#define GPIO_GPFEN1 23
#define GPIO_GPHEN0 25
#define GPIO_GPHEN1 26
#define GPIO_GPLEN0 28
#define GPIO_GPLEN1 29
#define GPIO_GPAREN0 31
#define GPIO_GPAREN1 32
#define GPIO_GPAFEN0 34
#define GPIO_GPAFEN1 35
#define GPIO_GPPUD 37
#define GPIO_GPPUDCLK0 38
#define GPIO_GPPUDCLK1 39
#define GPIO_PIN_MAX 53
#define GPIO_SEL_CAP 10
#define GPIO_SEL_OFF 3
#endif // RPI_1

void 
_gpio_pin_check(
	__in gpio_t *cont,
	__in uint32_t pin,
	__out bool *val
	)
{

	if(!cont || (pin > GPIO_PIN_MAX) || !val) {
		kerrno = KEINVAL;
		goto exit;
	}

#ifdef RPI_1
	if(pin >= WORD_WIDTH) {
		*val = reg_bit_check(cont->base + GPIO_GPLEV1, pin - WORD_WIDTH) 
			? true : false;
	} else {
		*val = reg_bit_check(cont->base + GPIO_GPLEV0, pin) ? true : false;
	}
#else
	*val = false;
#endif // RPI_1

exit:
	return;
}

void 
_gpio_pin_clear(
	__in gpio_t *cont,
	__in uint32_t pin
	)
{

	if(!cont || (pin > GPIO_PIN_MAX)) {
		kerrno = KEINVAL;
		goto exit;
	}

#ifdef RPI_1
	if(pin >= WORD_WIDTH) {
		reg_bit_set(cont->base + GPIO_GPCLR1, pin - WORD_WIDTH);
	} else {
		reg_bit_set(cont->base + GPIO_GPCLR0, pin);
	}
#endif // RPI_1

exit:
	return;
}

void 
_gpio_pin_config(
	__in gpio_t *cont,
	__in uint32_t pin,
	__in gpio_pin_t type
	)
{

	if(!cont || (pin > GPIO_PIN_MAX)) {
		kerrno = KEINVAL;
		goto exit;
	}

#ifdef RPI_1
	if(type == GPIO_PIN_INPUT) {
		reg_bit_clear(cont->base + (pin / GPIO_SEL_CAP), (pin % GPIO_SEL_CAP) * GPIO_SEL_OFF);
	} else {
		reg_bit_set(cont->base + (pin / GPIO_SEL_CAP), (pin % GPIO_SEL_CAP) * GPIO_SEL_OFF);
	}
#endif // RPI_1

exit:
	return;
}

void 
_gpio_pin_set(
	__in gpio_t *cont,
	__in uint32_t pin
	)
{

	if(!cont || (pin > GPIO_PIN_MAX)) {
		kerrno = KEINVAL;
		goto exit;
	}

#ifdef RPI_1
	if(pin >= WORD_WIDTH) {
		reg_bit_set(cont->base + GPIO_GPSET1, pin - WORD_WIDTH);
	} else {
		reg_bit_set(cont->base + GPIO_GPSET0, pin);
	}
#endif // RPI_1

exit:
	return;
}

void 
gpio_init(
	__inout gpio_t *cont,
	__in volatile void *base
	)
{
	volatile uint32_t *addr;

	if(!cont) {
		kerrno = KEINVAL;
		goto exit;
	}

	mem_set(cont, 0, sizeof(gpio_t));
	cont->base = base;

	addr = (volatile uint32_t *) base;
	
#ifdef RPI_1
	reg_write(addr + GPIO_GPFSEL0, 0);
	reg_write(addr + GPIO_GPFSEL1, 0);
	reg_write(addr + GPIO_GPFSEL2, 0);
	reg_write(addr + GPIO_GPFSEL3, 0);
	reg_write(addr + GPIO_GPFSEL4, 0);
	reg_write(addr + GPIO_GPFSEL5, 0);
	reg_write(addr + GPIO_GPSET0, 0);
	reg_write(addr + GPIO_GPSET1, 0);
	reg_write(addr + GPIO_GPCLR0, 0);
	reg_write(addr + GPIO_GPCLR1, 0);
	reg_write(addr + GPIO_GPLEV0, 0);
	reg_write(addr + GPIO_GPLEV1, 0);
	reg_write(addr + GPIO_GPEDS0, 0);
	reg_write(addr + GPIO_GPEDS1, 0);
	reg_write(addr + GPIO_GPREN0, 0);
	reg_write(addr + GPIO_GPREN1, 0);
	reg_write(addr + GPIO_GPFEN0, 0);
	reg_write(addr + GPIO_GPFEN1, 0);
	reg_write(addr + GPIO_GPHEN0, 0);
	reg_write(addr + GPIO_GPHEN1, 0);
	reg_write(addr + GPIO_GPLEN0, 0);
	reg_write(addr + GPIO_GPLEN1, 0);
	reg_write(addr + GPIO_GPAREN0, 0);
	reg_write(addr + GPIO_GPAREN1, 0);
	reg_write(addr + GPIO_GPAFEN0, 0);
	reg_write(addr + GPIO_GPAFEN1, 0);
	reg_write(addr + GPIO_GPPUD, 0);
	reg_write(addr + GPIO_GPPUDCLK0, 0);
	reg_write(addr + GPIO_GPPUDCLK1, 0);
#endif // RPI_1

	cont->init = true;

exit:
	return;
}

void 
gpio_uninit(
	__inout gpio_t *cont
	)
{

	if(!cont) {
		kerrno = KEINVAL;
		goto exit;
	}

	mem_set(cont, 0, sizeof(gpio_t));

exit:
	return;
}
