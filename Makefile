export GCC_EXEC_PREFIX=/cygdrive/C/Program Files/Module/NMC-SDK/nmc4-ide/lib/gcc/
$(info  $(GCC_EXEC_PREFIX))
PATH:=$(NMC_GCC_TOOLPATH)\nmc4-ide\bin;$(NMC_GCC_TOOLPATH)\nmc4-ide\lib;$(PATH)


#all: nm6406 nm6407i nm6407f nm6408 nm6476i nm6476f x64

conf: 
	cmake -B build . -D ARCH=nm6408 -G Ninja -D NM_CARD_BUILD=ON -D QEMU_BUILD=ON 

mk:
	cmake --build build
	
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
	cmake -B build_$@ . -D ARCH="$@"  -G Ninja -D NM_CARD_BUILD=ON -D QEMU_BUILD=ON  -D X64_BUILD=ON 
	
r:
	cmake --build build_nm6408 --config Release --verbose

d:
	cmake --build build_nm6408 --config Debug --verbose
	
nm6476i:
	cmake -B build_$@ . -D ARCH="$@"  -G Ninja
	cmake --build build_$@ --verbose

nm6476f:
	cmake -B build_$@ . -D ARCH="$@"  -G Ninja
	cmake --build build_$@ --verbose

x64:
	cmake -B build_$@ . -D ARCH="$@" -G "Visual Studio 15 2017 Win64"
	cmake --build build_$@
	
nm:	
	cmake -B build_nmc_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release  -D ARCH=nm6408 -D NMC_TOOLCHAIN=ON	
	cmake --build build_nmc_release
	
#	cmake -B build_x64_debug . 		-G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Debug 	-D X64_BUILD=ON -D ARCH=x64 -D NMC_TOOLCHAIN=OFF
#	cmake --build build_x64_debug --config Debug
dep:
	cmake -B build_x64 . 	-G "Visual Studio 15 2017 Win64" -D X64_BUILD=ON -D ARCH=x64 -D NMC_TOOLCHAIN=OFF
	cmake -B build_nmc_debug . 		-G Ninja -DCMAKE_BUILD_TYPE=Debug 	 -D ARCH=nm6408 -D NMC_TOOLCHAIN=ON
	cmake -B build_nmc_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release  -D ARCH=nm6408 -D NMC_TOOLCHAIN=ON
	
	cmake --build build_x64 --config Release
	cmake --build build_x64 --config Debug
	cmake --build build_nmc_debug
	cmake --build build_nmc_release
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release"

	
#cmake -B build_pc . -G Ninja