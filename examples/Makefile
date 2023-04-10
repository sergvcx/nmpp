ifeq ($(OS),Windows_NT)
SHELL=cmd
space := $(subst ,, )
NMC_TOOLPATH=$(subst $(space),\$(space),$(NMC_GCC_TOOLPATH))
-include $(NMC_TOOLPATH)\nmc4-ide\include\nmc4vars_win.mk
OS_RM    = del 
else 
OS_RM    = rm -f -r
endif


all: mc11101 mc11102 mc12101

#	cmake -B build_$@ -G "Unix Makefiles" -D MC12101_BUILD=ON -D NM_CARD_BUILD=ON
#	cmake --build build_$@ -v
#	cd build && ctest


qemu:
	cmake -B build_$@      -G "Unix Makefiles" -D QEMU_BUILD=ON
	cmake --build build_$@
	cd build_$@ && ctest	

qemu1:
	cmake -B build_qemu      -G "Unix Makefiles" -D BOARD=qemu

qemu2:	
	cmake --build build_qemu -v

qemu3:	
	cd build_qemu && ctest	

mc11101:
	cmake -B build_$@ -G "Unix Makefiles" -D MC11101_BUILD=ON -D QEMU_BUILD=ON
	cmake --build build_$@ 
	cd build_$@ && ctest 

mc11102:
	cmake -B build_$@ -G "Unix Makefiles" -D MC11101_BUILD=ON -D QEMU_BUILD=ON
	cmake --build build_$@ 
	cd build_$@ && ctest

mc12101:
	cmake -B build_$@ -G "Unix Makefiles" -D MC12101_BUILD=ON -D QEMU_BUILD=ON
	cmake --build build_$@ 
	cd build_$@ && ctest

#mc12101i:
#	cmake -B build_$@ -G "Unix Makefiles" -D MC12101_BUILD=ON -D ARCH=nm6407i
#	cmake --build build_$@
#	cd build_$@ && ctest

mc12705:
	cmake -B build_$@   -G "Unix Makefiles" -D MC12705_BUILD=ON
	cmake --build build_$@

nm_card:
	cmake -B build   -G "Unix Makefiles" -D NM_CARD_BUILD=ON -D QEMU_BUILD=ON 
	cmake --build build

mc5103:
	cmake -B build_$@    -G "Unix Makefiles" -D BOARD=$@
	cmake --build build_$@
	cd build_$@ && ctest
	
mb7707:
	cmake -B build_$@ -G "Unix Makefiles" -D BOARD=$@ -D MAC=10-FE-ED-05-D1-F8
	cmake --build build_$@
	cd build_$@ && ctest

x64:
	cmake -B build_$@ -G "Visual Studio 15 2017 Win64" -D X64_BUILD=ON
	cmake --build build_$@
	cd build_$@ && ctest -C Debug
	
test:
	cd build_mc12705 && ctest -C Debug
	
	