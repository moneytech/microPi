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
CC_FLAGS=-mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -Ofast -Wall -Wextra
DIR_BIN=./../../bin/
DIR_BUILD=./../../build/
DIR_INC=./include/
DIR_SRC=./src/

all: build_pre build arch

arch:
	@echo ''
	@echo '--------------------------------------------'
	@echo 'ARCHIVING LIBRARY OBJECTS'
	@echo '--------------------------------------------'
	$(AR) $(AR_FLAGS) $(DIR_BUILD)kernc.a $(DIR_BUILD)assert.o

build: assert.o

build_pre:
	@echo ''
	@echo '--------------------------------------------'
	@echo 'BUILDING LIBRARY OBJECTS'
	@echo '--------------------------------------------'

### LUNAC ###

assert.o: $(DIR_SRC)assert.c $(DIR_INC)assert.h
	$(CC) $(CC_FLAGS) -c $(DIR_SRC)assert.c -o $(DIR_BUILD)assert.o
