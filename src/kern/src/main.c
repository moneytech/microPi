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
#include "../include/main.h"

const char *KERR[] = {
	"", 
	"Invalid machine type", 
	"Invalid parameter", 
	"Undefined instruction", 
	"Data/perfetch abort",
	};

#define KERR_STR(_TYPE_) ((_TYPE_) > KERR_MAX ? "Undefined" : KERR[_TYPE_])

void 
kern_init(
	__inout kern_t *cont,
	__in uint32_t dev,
	__in uint32_t mach,
	__in volatile void *atags
	)
{

	if(!cont) {
		kerrno = KEINVAL;
		goto exit;
	}

	if(mach != MACH_TYPE) {
		kerrno = KEMACH;
		goto exit;
	}

	mem_set(cont, 0, sizeof(kern_t));
	cont->dev = dev;
	cont->mach = mach;

	atag_init(&cont->atag, atags);
	if(kerrno != KENONE) {
		goto exit;
	}

	gpio_init(&cont->gpio, (void *) GPIO_BASE);
	if(kerrno != KENONE) {
		goto exit;
	}

	uart_init(&cont->uart, &cont->gpio, (void *) UART_BASE);
	if(kerrno != KENONE) {
		goto exit;
	}

exit:
	return;
}

void 
kern_main(
	__in uint32_t dev,
	__in uint32_t mach,
	__in volatile void *atags
	)
{
	kern_t cont;

	kern_init(&cont, dev, mach, atags);
	if(kerrno != KENONE) {
		goto exit;
	}

	kern_proc(&cont);
	if(kerrno != KENONE) {
		goto exit;
	}

	kern_uninit(&cont);
	if(kerrno != KENONE) {
		goto exit;
	}

exit:
	kern_trap(&cont, KERR_STR(kerrno));
}

void 
kern_proc(
	__inout kern_t *cont
	)
{
#ifdef RPI_1
	pin_config(cont, PIN_LED_STAT, GPIO_PIN_OUTPUT);
	pin_clear(cont, PIN_LED_STAT);
#endif // RPI_1

	// TODO
	pin_config(cont, 25, GPIO_PIN_OUTPUT);
	pin_set(cont, 25);
	for(;;);
	// ---

#ifdef RPI_1
	pin_set(cont, PIN_LED_STAT);
#endif // RPI_1
}

void 
kern_trap(
	__in const kern_t *cont,
	__in const char *msg
	)
{

	if(cont) {

		// TODO
		__ref(msg);
		// ---
	}

	for(;;);
}

void 
kern_uninit(
	__inout kern_t *cont
	)
{

	if(!cont) {
		kerrno = KEINVAL;
		goto exit;
	}

	uart_uninit(&cont->uart);
	if(kerrno != KENONE) {
		goto exit;
	}

	gpio_uninit(&cont->gpio);
	if(kerrno != KENONE) {
		goto exit;
	}

	atag_uninit(&cont->atag);
	if(kerrno != KENONE) {
		goto exit;
	}

	mem_set(cont, 0, sizeof(kern_t));

exit:
	return;
}
