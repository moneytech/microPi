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

JOB_SLOTS=4
DIR_BIN=./bin/
DIR_BUILD=./build/
DIR_KERN=./src/kern/
DIR_LIB=./src/lib/
DIR_LOG=./log/
DIR_SRC=./src/
LOG_MEM=val_err.log
LOG_STAT=stat_err.log
LOG_CLOC=cloc_stat.log

all: kern

clean:
	rm -rf $(DIR_BIN)
	rm -rf $(DIR_BUILD)
	rm -rf $(DIR_LOG)

init:
	mkdir $(DIR_BIN)
	mkdir $(DIR_BUILD)
	mkdir $(DIR_LOG)

### BUILD ###

kern: clean init lib_build kern_build

kern_build:
	@echo ''
	@echo '============================================'
	@echo 'BUILDING KERNEL IMAGE'
	@echo '============================================'
	cd $(DIR_KERN) && make || (echo "*** KERNEL IMAGE FAILED: $$? ***"; exit 1)

lib: clean init lib_build

lib_build:
	@echo ''
	@echo '============================================'
	@echo 'BUILDING LIBRARIES'
	@echo '============================================'
	cd $(DIR_LIB) && make || (echo "*** LIBRARY BUILD FAILED: $$? ***"; exit 1)

### STATISTICS ###

stat: lines

lines:
	@echo ''
	@echo '============================================'
	@echo 'CALCULATING LINE COUNT'
	@echo '============================================'
	cloc $(DIR_SRC) > $(DIR_LOG)$(LOG_CLOC) || (echo "*** LINE COUNT FAILED: $$? ***"; exit 1)

### TESTING ###

test: test_stat test_mem

test_mem:
	@echo ''
	@echo '============================================'
	@echo 'RUNNING MEMORY TEST'
	@echo '============================================'
	valgrind $(DIR_BIN)$(EXE) --leak-check=full --verbose 2> $(DIR_LOG)$(LOG_MEM) || (echo "*** MEMORY TEST FAILED: $$? ***"; exit 1)

test_stat:
	@echo ''
	@echo '============================================'
	@echo 'RUNNING STATIC ANALYSIS'
	@echo '============================================'
	cppcheck --enable=all --std=c99 $(DIR_SRC) 2> $(DIR_LOG)$(LOG_STAT) || (echo "*** STATIC ANALYSIS FAILED: $$? ***"; exit 1)

