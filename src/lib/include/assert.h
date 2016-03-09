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

#ifndef ASSERT_H_
#define ASSERT_H_

#include "./def.h"

#ifndef NDEBUG
#define assert(_EXP_) { \
	if(!(_EXP_)) { \
		_assert("Assertion failed: " str(_EXP_) ", file " __FILE__ \
			", line " str(__LINE__)); \
	}}
#else
#define assert(_EXP_) ((void) 0)
#endif // NDEBUG

#ifdef __cplusplus
extern "C"
#endif // __cplusplus

void _assert(
	__in const char *expr
	);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ASSERT_H_
