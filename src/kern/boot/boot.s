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

.globl _entry
.section ".text.load"

_entry:
	mov sp, #0x8000
	ldr r4, =__bss_begin
	mov r5, #0
	mov r6, #0
	mov r7, #0
	mov r8, #0
	ldr r9, =__bss_end
	b _loop
_store:
	stmia r4!, {r5 - r8}
_loop:
	cmp r4, r9
	blo _store

	/* call kernel entry */
	ldr r3, =kern_main
	blx r3

_halt:
	wfe
	b _halt
