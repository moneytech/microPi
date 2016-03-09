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

#ifndef MEM_H_
#define MEM_H_

#include "./def.h"
#include "../../lib/include/stdbool.h"
#include "../../lib/include/stddef.h"
#include "../../lib/include/stdint.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifndef __bv
#define __bv(_BIT_) (1 << (_BIT_))
#endif // __bv

#ifndef reg_bit_check
#define reg_bit_check(_ADDR_, _BIT_) _mmio_check(_ADDR_, __bv(_BIT_))
#endif // reg_bit_check

#ifndef reg_bit_clear
#define reg_bit_clear(_ADDR_, _BIT_) _mmio_clear(_ADDR_, __bv(_BIT_))
#endif // reg_bit_clear

#ifndef reg_bit_set
#define reg_bit_set(_ADDR_, _BIT_) _mmio_set(_ADDR_, __bv(_BIT_))
#endif // reg_bit_set

#ifndef reg_bit_toggle
#define reg_bit_toggle(_ADDR_, _BIT_) _mmio_toggle(_ADDR_, __bv(_BIT_))
#endif // reg_bit_toggle

#ifndef reg_read
#define reg_read(_ADDR_) _mmio_read(_ADDR_, _VAL_)
#endif // reg_read

#ifndef reg_write
#define reg_write(_ADDR_, _VAL_) _mmio_write(_ADDR_, _VAL_)
#endif // reg_write

bool _mmio_check(
	__in volatile void *addr,
	__in uint32_t mask
	);

void _mmio_clear(
	__in volatile void *addr,
	__in uint32_t mask
	);

uint32_t _mmio_read(
	__in volatile void *addr
	);

void _mmio_set(
	__in volatile void *addr,
	__in uint32_t mask
	);

void _mmio_toggle(
	__in volatile void *addr,
	__in uint32_t mask
	);

void _mmio_write(
	__in volatile void *addr,
	__in uint32_t val
	);

void mem_copy(
	__inout void *addr0,
	__in const void *addr1,
	__in size_t len
	);

uint8_t mem_read(
	__in const void *addr
	);

void mem_set(
	__inout void *addr,
	__in uint8_t val,
	__in size_t len
	);

void mem_write(
	__in const void *addr,
	__in uint8_t val
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // MEM_H_
