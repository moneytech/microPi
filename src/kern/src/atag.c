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

#include "../include/atag.h"
#include "../include/err.h"
#include "../include/mem.h"

void 
atag_init(
	__inout atag_t *cont,
	__in volatile void *base
	)
{

	if(!cont) {
		kerrno = KEINVAL;
		goto exit;
	}

	mem_set(cont, 0, sizeof(atag_t));
	cont->base = base;

	// TODO

exit:
	return;
}

void 
atag_uninit(
	__inout atag_t *cont
	)
{

	if(!cont) {
		kerrno = KEINVAL;
		goto exit;
	}

	// TODO

	mem_set(cont, 0, sizeof(atag_t));

exit:
	return;	
}
