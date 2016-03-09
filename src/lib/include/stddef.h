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

#ifndef STDDEF_H_
#define STDDEF_H_

#ifndef NULL
#define NULL ((void *) 0)
#endif // NULL

#ifndef __OFFSETOF
#define __OFFSETOF
#define offsetof(_TYPE_, _MEM_) ((size_t) &((_TYPE_ *) 0)->_MEM_)
#endif // __OFFSETOF

#ifndef __PTRDIFF_T
#define __PTRDIFF_T
typedef signed int ptrdiff_t;
#endif // __PTRDIFF_T

#ifndef __SIZE_T
#define __SIZE_T
typedef unsigned long long size_t;
#endif // __SIZE_T

#ifndef __WCHAR_T
#define __WCHAR_T
typedef unsigned char wchar_t;
#endif // __WCHAR_T

#endif // STDDEF_H_
