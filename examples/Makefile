export GCC_EXEC_PREFIX=/cygdrive/C/Program Files/Module/NMC-SDK/nmc4-ide/lib/gcc/
$(info  $(GCC_EXEC_PREFIX))
PATH:=$(NMC_GCC_TOOLPATH)\nmc4-ide\bin;$(NMC_GCC_TOOLPATH)\nmc4-ide\lib;$(PATH)

shell=cmd

qemu:
	cmake -B build_$@      -G "Unix Makefiles" -D BOARD=$@
	cmake --build build_$@
	cd build_$@ && ctest	

qemu1:
	cmake -B build_qemu      -G "Unix Makefiles" -D BOARD=qemu

qemu2:	
	cmake --build build_qemu -v

qemu3:	
	cd build_qemu && ctest	

mc12101f:
	cmake -B build_$@ -G "Unix Makefiles" -D BOARD=mc12101 -D CORE=-nmpu0
	cmake --build build_$@ -v
	cd build_$@ && ctest

mc12101i:
	cmake -B build_$@ -G "Unix Makefiles" -D BOARD=mc12101 -D CORE=-nmpu0  
	cmake --build build_$@
	cd build_$@ && ctest

mc12705:
	cmake -B build_$@   -G "Unix Makefiles" -D BOARD=$@ -D RUNNER=mc12101run 
	cmake --build build_$@


mc5103:
	cmake -B build_$@    -G "Unix Makefiles" -D BOARD=$@
	cmake --build build_$@
	cd build_$@ && ctest
	
mb7707:
	cmake -B build_$@ -G "Unix Makefiles" -D BOARD=$@ -D MAC=10-FE-ED-05-D1-F8
	cmake --build build_$@
	cd build_$@ && ctest

test:
	cd build_mc12705 && ctest