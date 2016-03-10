# μPi
# Copyright (C) 2016 David Jolly
# ----------------------
#
# μPi is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# μPi is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

AR=ar
AR_FLAGS=rcs
CC=arm-none-eabi-gcc
CC_FLAGS_LINK=-ffreestanding -O2 -nostdlib
CC_FLAGS_BOOT=-mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -fpic -ffreestanding
CC_FLAGS_KERN=-mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -Ofast -Wall -Wextra
CC_LINK=arm-none-eabi-objcopy
DIR_BIN=./../../bin/
DIR_BUILD=./../../build/
DIR_BOOT=./boot/
DIR_INC=./include/
DIR_ROOT=./
DIR_SRC=./src/

all: build

arch:
	@echo ''
	@echo '--------------------------------------------'
	@echo 'ARCHIVING BOOT/KERNEL OBJECTS'
	@echo '--------------------------------------------'
	$(AR) $(AR_FLAGS) $(DIR_BUILD)kern.a $(DIR_BUILD)boot.o $(DIR_BUILD)atag.o $(DIR_BUILD)delay.o $(DIR_BUILD)gpio.o $(DIR_BUILD)main.o \
		$(DIR_BUILD)mem.o $(DIR_BUILD)uart.o

build: build_boot boot.o build_kern atag.o delay.o gpio.o main.o mem.o uart.o arch link

build_boot:
	@echo ''
	@echo '--------------------------------------------'
	@echo 'BUILDING BOOT OBJECTS'
	@echo '--------------------------------------------'

build_kern:
	@echo ''
	@echo '--------------------------------------------'
	@echo 'BUILDING KERNEL OBJECTS'
	@echo '--------------------------------------------'

link:
	@echo ''
	@echo '--------------------------------------------'
	@echo 'LINKING KERNEL OBJECTS'
	@echo '--------------------------------------------'
	$(CC) $(CC_FLAGS_LINK) -T $(DIR_ROOT)linker.ld -o $(DIR_BUILD)kern.elf $(DIR_BUILD)kern.a $(DIR_BUILD)kernc.a \
		|| (echo "*** KERNEL LINKING FAILED: $$? ***"; exit 1)
	$(CC_LINK) $(DIR_BUILD)kern.elf -O binary $(DIR_BIN)kernel.img

### BOOT ###

boot.o: $(DIR_BOOT)boot.s
	$(CC) $(CC_FLAGS_BOOT) -c $(DIR_BOOT)boot.s -o $(DIR_BUILD)boot.o

### KERNEL ###

atag.o: $(DIR_SRC)atag.c $(DIR_INC)atag.h
	$(CC) $(CC_FLAGS_KERN) -c $(DIR_SRC)atag.c -o $(DIR_BUILD)atag.o

delay.o: $(DIR_SRC)delay.c $(DIR_INC)delay.h
	$(CC) $(CC_FLAGS_KERN) -c $(DIR_SRC)delay.c -o $(DIR_BUILD)delay.o

gpio.o: $(DIR_SRC)gpio.c $(DIR_INC)gpio.h
	$(CC) $(CC_FLAGS_KERN) -c $(DIR_SRC)gpio.c -o $(DIR_BUILD)gpio.o

main.o: $(DIR_SRC)main.c $(DIR_INC)main.h
	$(CC) $(CC_FLAGS_KERN) -c $(DIR_SRC)main.c -o $(DIR_BUILD)main.o

mem.o: $(DIR_SRC)mem.c $(DIR_INC)mem.h
	$(CC) $(CC_FLAGS_KERN) -c $(DIR_SRC)mem.c -o $(DIR_BUILD)mem.o

uart.o: $(DIR_SRC)uart.c $(DIR_INC)uart.h
	$(CC) $(CC_FLAGS_KERN) -c $(DIR_SRC)uart.c -o $(DIR_BUILD)uart.o
