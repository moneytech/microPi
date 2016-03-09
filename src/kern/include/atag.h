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

#ifndef ATAG_H_
#define ATAG_H_

#include "./def.h"
#include "../../lib/include/stdbool.h"
#include "../../lib/include/stdint.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct {
	bool init;
	volatile uint32_t *base;

	// TODO
} atag_t;

void atag_init(
	__inout atag_t *cont,
	__in volatile void *base
	);

void atag_uninit(
	__inout atag_t *cont
	);

// TODO

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ATAG_H_
