export GCC_EXEC_PREFIX=/cygdrive/C/Program Files/Module/NMC-SDK/nmc4-ide/lib/gcc/
$(info  $(GCC_EXEC_PREFIX))
PATH:=$(NMC_GCC_TOOLPATH)\nmc4-ide\bin;$(NMC_GCC_TOOLPATH)\nmc4-ide\lib;$(PATH)


all: nm6406 nm6407i nm6407f nm6408 nm6476i nm6476f x64
	
	
nm6406:
	cmake -B build_$@ . -D ARCH="$@"  -G Ninja
	cmake --build build_$@

nm6407i:
	cmake -B build_$@ . -D ARCH="$@"  -G Ninja
	cmake --build build_$@ --verbose

nm6407f:
	cmake -B build_$@ . -D ARCH="$@"  -G Ninja
	cmake --build build_$@ --verbose

nm6408:
	cmake -B build_$@ . -D ARCH="$@"  -G Ninja
	cmake --build build_$@
	
nm6476i:
	cmake -B build_$@ . -D ARCH="$@"  -G Ninja
	cmake --build build_$@ --verbose

nm6476f:
	cmake -B build_$@ . -D ARCH="$@"  -G Ninja
	cmake --build build_$@ --verbose


x64:
	cmake -B build_$@ . -D ARCH="$@" -G "Visual Studio 15 2017 Win64"
	cmake --build build_$@
	
#cmake -B build_pc . -G Ninja