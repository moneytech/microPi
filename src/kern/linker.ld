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

ENTRY(_entry)

SECTIONS
{
	. = 0x8000;
	__start = .;

		/* text section */
		__text_begin = .;
			.text :
			{
				KEEP(*(.text.load))
				*(.text)
			} . = ALIGN(4096);
		__text_end = .;

		/* rodata section */
		__rodata_begin = .;
			.rodata :
			{
				*(.rodata)
			} . = ALIGN(4096);
		__rodata_end = .;

		/* data section */
		__data_begin = .;
			.data :
			{
				*(.data)
			} . = ALIGN(4096);
		__data_end = .;

		/* bss section */
		__bss_begin = .;
			.bss :
			{
				bss = .;
				*(.bss)
			} . = ALIGN(4096);
		__bss_end = .;
	__end = .;
}
