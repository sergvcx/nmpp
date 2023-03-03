ifeq ($(OS),Windows_NT)
SHELL=cmd
space := $(subst ,, )
NMC_TOOLPATH=$(subst $(space),\$(space),$(NMC_GCC_TOOLPATH))
-include $(NMC_TOOLPATH)\nmc4-ide\include\nmc4vars_win.mk
OS_RM    = del 
else 
OS_RM    = rm -f -r
endif


x64:
	cmake -B build_$@ -G "Visual Studio 15 2017 Win64" -D X64_BUILD=ON
	cmake --build build_$@ -v
	cd build_$@ && ctest -v

mc12101f:
	cmake -B build_$@ -G "Unix Makefiles" -D MC12101_BUILD=ON
	cmake --build build_$@ -v
	cd build_$@ && ctest -v

mk:
	cmake --build build_mc12101f -v
	
test:
	cd build_mc12101f && ctest -v


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
