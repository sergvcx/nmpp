

ifeq ($(OS),Windows_NT)
SHELL=cmd
-include nmc4vars_win.mk
endif
-include $(ROOT)/clean.mk
NMPP?=$(ROOT)
.SUFFIXES:

BOARD = mc12101
BSP = $(MC12101)
ifndef MC12101
$(warning *** WARNING: 'MC12101' environment variable is not defined! Board SDK might not have installed correctly. )
endif 

PROJECT  = main
TARGET   = $(PROJECT)

CC       = nmc-g++
AS       = nmc-gcc
CXXFLAGS = -std=c++11 -O2 -Wall -mnmc4 -g
LIBS     = -lnmpp-nmc4 -ltimes -lint     -Wl,--whole-archive -lnm6407_io_nmc -l$(BOARD)load_nm -Wl,--no-whole-archive  
CFG      = $(BOARD)-nmpu1.lds
MAP      = $(PROJECT).map
LDFLAGS  = -Wl,-Map=$(MAP) -Wl,-T$(CFG) 


INC_DIRS = -I"$(BSP)/include" -I"$(NMPP)/include" 
LIB_DIRS = -L"$(BSP)/lib" -L"$(NMPP)/lib"    -L"$(NMCGCC)/lib" -L.
SRC_DIRS = ..
SRC_CPP  = $(wildcard $(addsuffix /*.cpp,$(SRC_DIRS)))
SRC_ASM  = $(wildcard $(addsuffix /*.asm,$(SRC_DIRS)))
SRC_C    = $(wildcard $(addsuffix /*.c,$(SRC_DIRS)))
SRC_ALL  = $(SRC_CPP) $(SRC_ASM) $(SRC_C)

.DEFAULT_GOAL := $(TARGET)

$(TARGET): $(SRC_ALL) Makefile $(NMPP)/lib/libnmpp-nmc4.a
	$(CC)  -o$(TARGET) $(CXXFLAGS) $(LDFLAGS) $(SRC_ALL) $(INC_DIRS) $(LIB_DIRS) $(LIBS)

#PATH:=$(BSP)/bin;$(PATH)

run: .exitcode
	
.exitcode: 	$(TARGET)
	$(BOARD)run -p -v $(TARGET) -R -a1 & exitcode

qemu:	
	nmc-qemu $(TARGET)

gdb :	
	nmc-gdb  $(TARGET)

$(MAKE) LIBS="-lnmpp-nmc4 -lc " -B TARGET=$(TARGET)_qemu

	
nmc4vars_win.mk:
	copy "$(NMC_GCC_TOOLPATH)\nmc4-ide\include\nmc4vars_win.mk" nmc4vars_win.mk
	
vs2015:
	premake5 vs2015
	
vs2008:
	premake5 vs2008		
	
