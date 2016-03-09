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

#include "../include/mem.h"

bool 
_mmio_check(
	__in volatile void *addr,
	__in uint32_t mask
	)
{
	return (*((volatile uint32_t *) addr) & mask) ? true : false;
}

void 
_mmio_clear(
	__in volatile void *addr,
	__in uint32_t mask
	)
{
	*((volatile uint32_t *) addr) &= ~mask;
}

uint32_t 
_mmio_read(
	__in volatile void *addr
	)
{
	return *((volatile uint32_t *) addr);
}

void 
_mmio_set(
	__in volatile void *addr,
	__in uint32_t mask
	)
{
	*((volatile uint32_t *) addr) |= mask;
}

void 
_mmio_toggle(
	__in volatile void *addr,
	__in uint32_t mask
	)
{
	*((volatile uint32_t *) addr) ^= mask;
}

void 
_mmio_write(
	__in volatile void *addr,
	__in uint32_t val
	)
{
	*((volatile uint32_t *) addr) = val;
}

void 
mem_copy(
	__inout void *addr0,
	__in const void *addr1,
	__in size_t len
	)
{
	size_t iter = 0;
	volatile uint8_t *maddr0 = (volatile uint8_t *) addr0,
		*maddr1 = (volatile uint8_t *) addr1;

	for(; iter < len; ++iter) {
		maddr0[iter] = maddr1[iter];
	}
}

uint8_t 
mem_read(
	__in const void *addr
	)
{
	return *((volatile uint8_t *) addr);
}

void 
mem_set(
	__inout void *addr,
	__in uint8_t val,
	__in size_t len
	)
{
	size_t iter = 0;
	volatile uint8_t *maddr = (volatile uint8_t *) addr;

	for(; iter < len; ++iter) {
		maddr[iter] = val;
	}
}

void 
mem_write(
	__in const void *addr,
	__in uint8_t val
	)
{
	*((volatile uint8_t *) addr) = val;
}
