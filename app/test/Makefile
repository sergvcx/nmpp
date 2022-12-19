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
