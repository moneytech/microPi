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

#ifndef STDBOOL_H_
#define STDBOOL_H_

#ifndef __cplusplus

#ifndef __BOOL
#define __BOOL

#ifndef __bool_true_false_are_defined
#define __bool_true_false_are_defined 1
#endif // __bool_true_false_are_defined

#ifndef false
#define false ((bool) 0)
#endif // false

#ifndef true
#define true ((bool) 1)
#endif // true

typedef unsigned char bool;

#endif // __BOOL
#endif // __cplusplus

#endif // STDBOOL_H_
