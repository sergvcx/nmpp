export GCC_EXEC_PREFIX=/cygdrive/C/Program Files/Module/NMC-SDK/nmc4-ide/lib/gcc/
$(info  $(GCC_EXEC_PREFIX))
PATH:=$(NMC_GCC_TOOLPATH)\nmc4-ide\bin;$(NMC_GCC_TOOLPATH)\nmc4-ide\lib;$(PATH)

shell=cmd

mc12101f:
	cmake -B build_$@ -G "Unix Makefiles" -D BOARD=mc12101 -D CORE=-nmpu0
	cmake --build build_$@
	cd build_$@ && ctest


ROOT=../..

ifeq ($(OS),Windows_NT)
	PYTHON = python
else
	PYTHON = python3
endif

TESTER=python $(ROOT)/deeprun/deeprun.py

default: 
	echo OK
	
#	kill configure build run match 

configure:
	$(TESTER) configure 

build:
	$(TESTER) make 
	
kill:
	$(TESTER) kill

killall:
	$(TESTER) killall

run :
	$(TESTER) make run

match:
	$(TESTER) match .exitcode

qemu:
	$(TESTER) make qemu

clean :
	$(TESTER) make clean
