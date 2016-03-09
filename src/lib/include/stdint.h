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

#ifndef STDINT_H_
#define STDINT_H_

#ifndef INT8_MIN
#define INT8_MIN -(INT8_MAX - 1)
#endif // INT8_MIN

#ifndef INT8_MAX
#define INT8_MAX 0x7f
#endif // INT8_MAX

#ifndef UINT8_MAX
#define UINT8_MAX 0xffU
#endif // UINT8_MAX

#ifndef INT16_MIN
#define INT16_MIN -(INT16_MAX - 1)
#endif // INT16_MIN

#ifndef INT16_MAX
#define INT16_MAX 0x7fff
#endif // INT16_MAX

#ifndef UINT16_MAX
#define UINT16_MAX 0xffffU
#endif // UINT16_MAX

#ifndef INT32_MIN
#define INT32_MIN -(INT32_MAX - 1)
#endif // INT32_MIN

#ifndef INT32_MAX
#define INT32_MAX 0x7fffffffL
#endif // INT32_MAX

#ifndef UINT32_MAX
#define UINT32_MAX 0xffffffffUL
#endif // UINT32_MAX

#ifndef INT64_MIN
#define INT64_MIN -(INT64_MAX - 1)
#endif // INT64_MIN

#ifndef INT64_MAX
#define INT64_MAX 0x7fffffffffffffffLL
#endif // INT64_MAX

#ifndef UINT64_MAX
#define UINT64_MAX 0xffffffffffffffffULL
#endif // UINT64_MAX

#ifndef INT_LEAST8_MIN
#define INT_LEAST8_MIN INT8_MIN
#endif // INT_LEAST8_MIN

#ifndef INT_LEAST8_MAX
#define INT_LEAST8_MAX INT8_MAX
#endif // INT_LEAST8_MAX

#ifndef UINT_LEAST8_MAX
#define UINT_LEAST8_MAX UINT8_MAX
#endif // UINT_LEAST8_MAX

#ifndef INT_LEAST16_MIN
#define INT_LEAST16_MIN INT16_MIN
#endif // INT_LEAST16_MIN

#ifndef INT_LEAST16_MAX
#define INT_LEAST16_MAX INT16_MAX
#endif // INT_LEAST16_MAX

#ifndef UINT_LEAST16_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#endif // UINT_LEAST16_MAX

#ifndef INT_LEAST32_MIN
#define INT_LEAST32_MIN INT32_MIN
#endif // INT_LEAST32_MIN

#ifndef INT_LEAST32_MAX
#define INT_LEAST32_MAX INT32_MAX
#endif // INT_LEAST32_MAX

#ifndef UINT_LEAST32_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#endif // UINT_LEAST32_MAX

#ifndef INT_LEAST64_MIN
#define INT_LEAST64_MIN INT64_MIN
#endif // INT_LEAST64_MIN

#ifndef INT_LEAST64_MAX
#define INT_LEAST64_MAX INT32_MAX
#endif // INT_LEAST64_MAX

#ifndef UINT_LEAST64_MAX
#define UINT_LEAST64_MAX UINT64_MAX
#endif // UINT_LEAST64_MAX

#ifndef INT_FAST8_MIN
#define INT_FAST8_MIN INT8_MIN
#endif // INT_FAST8_MIN

#ifndef INT_FAST8_MAX
#define INT_FAST8_MAX INT8_MAX
#endif // INT_FAST8_MAX

#ifndef UINT_FAST8_MAX
#define UINT_FAST8_MAX UINT8_MAX
#endif // UINT_FAST8_MAX

#ifndef INT_FAST16_MIN
#define INT_FAST16_MIN INT16_MIN
#endif // INT_FAST16_MIN

#ifndef INT_FAST16_MAX
#define INT_FAST16_MAX INT16_MAX
#endif // INT_FAST16_MAX

#ifndef UINT_FAST16_MAX
#define UINT_FAST16_MAX UINT16_MAX
#endif // UINT_FAST16_MAX

#ifndef INT_FAST32_MIN
#define INT_FAST32_MIN INT32_MIN
#endif // INT_FAST32_MIN

#ifndef INT_FAST32_MAX
#define INT_FAST32_MAX INT32_MAX
#endif // INT_FAST32_MAX

#ifndef UINT_FAST32_MAX
#define UINT_FAST32_MAX UINT32_MAX
#endif // UINT_FAST32_MAX

#ifndef INT_FAST64_MIN
#define INT_FAST64_MIN INT64_MIN
#endif // INT_FAST64_MIN

#ifndef INT_FAST64_MAX
#define INT_FAST64_MAX INT32_MAX
#endif // INT_FAST64_MAX

#ifndef UINT_FAST64_MAX
#define UINT_FAST64_MAX UINT64_MAX
#endif // UINT_FAST64_MAX

#ifndef INTMAX_MIN
#define INTMAX_MIN INT64_MIN
#endif // INTMAX_MIN

#ifndef INTMAX_MAX
#define INTMAX_MAX INT64_MAX
#endif // INTMAX_MAX

#ifndef UINTMAX_MAX
#define UINTMAX_MAX UINT64_MAX
#endif // UINTMAX_MAX

#ifndef SIZE_MAX
#define SIZE_MAX UINT_LEAST64_MAX
#endif // SIZE_MAX

#ifndef PTRDIFF_MIN
#define PTRDIFF_MIN INT_LEAST32_MIN
#endif // PTRDIFF_MIN

#ifndef PTRDIFF_MAX
#define PTRDIFF_MAX INT_LEAST32_MAX
#endif // PTRDIFF_MAX

#ifndef WCHAR_MIN
#define WCHAR_MIN 0
#endif // WCHAR_MIN

#ifndef WCHAR_MAX
#define WCHAR_MAX UINT_LEAST8_MAX
#endif // WCHAR_MAX

#ifndef INT8_C
#define INT8_C(_VAL_) ((int_least8_t) _VAL_)
#endif // INT8_C

#ifndef UINT8_C
#define UINT8_C(_VAL_) ((uint_least8_t) _VAL_)
#endif // UINT8_C

#ifndef INT16_C
#define INT16_C(_VAL_) ((int_least16_t) _VAL_)
#endif // INT16_C

#ifndef UINT16_C
#define UINT16_C(_VAL_) ((uint_least16_t) _VAL_)
#endif // UINT16_C

#ifndef INT32_C
#define INT32_C(_VAL_) ((int_least32_t) _VAL_)
#endif // INT32_C

#ifndef UINT32_C
#define UINT32_C(_VAL_) ((uint_least32_t) _VAL_)
#endif // UINT32_C

#ifndef INT64_C
#define INT64_C(_VAL_) ((int_least64_t) _VAL_)
#endif // INT64_C

#ifndef UINT64_C
#define UINT64_C(_VAL_) ((uint_least64_t) _VAL_)
#endif // UINT64_C

#ifndef INTMAX_C
#define INTMAX_C(_VAL_) ((intmax_t) _VAL_)
#endif // INTMAX_C

#ifndef UINTMAX_C
#define UINTMAX_C(_VAL_) ((uintmax_t) _VAL_)
#endif // UINTMAX_C

#ifndef __INT8_T
#define __INT8_T
typedef signed char int8_t;
#endif // __INT8_T

#ifndef __INT16_T
#define __INT16_T
typedef signed short int16_t;
#endif // __INT16_T

#ifndef __INT32_T
#define __INT32_T
typedef signed long int32_t;
#endif // __INT32_T

#ifndef __INT64_T
#define __INT64_T
typedef signed long long int64_t;
#endif // __INT64_T

#ifndef __UINT8_T
#define __UINT8_T
typedef unsigned char uint8_t;
#endif // __UINT8_T

#ifndef __UINT16_T
#define __UINT16_T
typedef unsigned short uint16_t;
#endif // __UINT16_T

#ifndef __UINT32_T
#define __UINT32_T
typedef unsigned long uint32_t;
#endif // __UINT32_T

#ifndef __UINT64_T
#define __UINT64_T
typedef unsigned long long uint64_t;
#endif // __UINT64_T

#ifndef __INT_LEAST8_T
#define __INT_LEAST8_T
typedef int8_t int_least8_t;
#endif // __INT_LEAST8_T

#ifndef __INT_LEAST16_T
#define __INT_LEAST16_T
typedef int16_t int_least16_t;
#endif // __INT_LEAST16_T

#ifndef __INT_LEAST32_T
#define __INT_LEAST32_T
typedef int32_t int_least32_t;
#endif // __INT_LEAST32_T

#ifndef __INT_LEAST64_T
#define __INT_LEAST64_T
typedef int64_t int_least64_t;
#endif // __INT_LEAST64_T

#ifndef __UINT_LEAST8_T
#define __UINT_LEAST8_T
typedef uint8_t uint_least8_t;
#endif // __UINT_LEAST8_T

#ifndef __UINT_LEAST16_T
#define __UINT_LEAST16_T
typedef uint16_t uint_least16_t;
#endif // __UINT_LEAST16_T

#ifndef __UINT_LEAST32_T
#define __UINT_LEAST32_T
typedef uint32_t uint_least32_t;
#endif // __UINT_LEAST32_T

#ifndef __UINT_LEAST64_T
#define __UINT_LEAST64_T
typedef uint64_t uint_least64_t;
#endif // __UINT_LEAST64_T

#ifndef __INT_FAST8_T
#define __INT_FAST8_T
typedef int8_t int_fast8_t;
#endif // __INT_FAST8_T

#ifndef __INT_FAST16_T
#define __INT_FAST16_T
typedef int16_t int_fast16_t;
#endif // __INT_FAST16_T

#ifndef __INT_FAST32_T
#define __INT_FAST32_T
typedef int32_t int_fast32_t;
#endif // __INT_FAST8_T

#ifndef __INT_FAST64_T
#define __INT_FAST64_T
typedef int64_t int_fast64_t;
#endif // __INT_FAST64_T

#ifndef __UINT_FAST8_T
#define __UINT_FAST8_T
typedef uint8_t uint_fast8_t;
#endif // __UINT_FAST8_T

#ifndef __UINT_FAST16_T
#define __UINT_FAST16_T
typedef uint16_t uint_fast16_t;
#endif // __UINT_FAST16_T

#ifndef __UINT_FAST32_T
#define __UINT_FAST32_T
typedef uint32_t uint_fast32_t;
#endif // __UINT_FAST32_T

#ifndef __UINT_FAST64_T
#define __UINT_FAST64_T
typedef uint64_t uint_fast64_t;
#endif // __UINT_FAST64_T

#ifndef __INTMAX_T
#define __INTMAX_T
typedef int_least64_t intmax_t;
#endif // __INTMAX_T

#ifndef __UINTMAX_T
#define __UINTMAX_T
typedef uint_least64_t uintmax_t;
#endif // __UINTMAX_T

#ifndef __INTPTR_T
#define __INTPTR_T
typedef int_least32_t intptr_t;
#endif // __INTPTR_T

#ifndef __UINTPTR_T
#define __UINTPTR_T
typedef uint_least32_t uintptr_t;
#endif // __UINTPTR_T

#endif // STDINT_H_
