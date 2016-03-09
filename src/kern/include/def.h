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

#ifndef DEF_H_
#define DEF_H_

#ifndef __in
#define __in
#endif // __in

#ifndef __inout
#define __inout
#endif // __inout

#ifndef __out
#define __out
#endif // __out

#ifndef __ref
#define __ref(_PARAM_) (void) _PARAM_
#endif // __ref

#ifndef __UPI
#define __UPI
#define __UPI_MAJ 1
#define __UPI_MIN 0
#define __UPI_REV 2
#define __UPI_WEEK 1611
#endif // __UPI_STDC

//#define NDEBUG

#define RPI_1
#ifdef RPI_1
#define GPIO_BASE 0x20200000UL
#define MACH_TYPE 0x00000c42UL
#define PIN_LED_STAT 16
#define UART_BASE 0x20201000UL
#define WORD_SIZE sizeof(uint32_t)
#define WORD_WIDTH (WORD_SIZE * 8)
#endif // RPI_1

#endif // DEF_H_
