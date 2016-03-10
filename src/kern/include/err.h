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

#ifndef ERR_H_
#define ERR_H_

typedef enum {
	KENONE = 0,
	KEMACH, // invalid machine type
	KEINVAL, // invalid parameter
	KEUNDEF, // undefined instruction
	KEFAULT, // data/prefetch abort
} kerr_t;

#define KERR_MAX KEFAULT

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifndef __KERRNO
#define __KERRNO
static kerr_t kerrno = KENONE;
#endif // __KERRNO

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ERR_H_
