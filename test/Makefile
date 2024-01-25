#export GCC_EXEC_PREFIX=/cygdrive/C/Program Files/Module/NMC-SDK/nmc4-ide/lib/gcc/
#$(info  $(GCC_EXEC_PREFIX))
#PATH:=$(NMC_GCC_TOOLPATH)\nmc4-ide\bin;$(NMC_GCC_TOOLPATH)\nmc4-ide\lib;$(PATH)

#shell=cmd
NMC_TOOLCHAIN = -DCMAKE_TOOLCHAIN_FILE="../cmake/nmc-gcc-toolchain.cmake"

#mc12101:
#	cmake -B build_$@ -G "Unix Makefiles" -DMC12101=ON -DQEMU=ON
#	cmake --build build_$@
#	cmake -B build -G "Unix Makefiles" -D BOARD=mc12101 -D CORE=-nmpu0

#qemu:
#	cmake -B build_$@      -G "Unix Makefiles" -D BOARD=$@
#	cmake --build build_$@
#	cd build_$@ && ctest	

#mc12101: mc12101f mc12101i
	
	
ifeq ($(OS),Windows_NT)
x64:     
	cmake -B 		build/build_$@ . -A x64 -D ARCH=x64 -D X64_BUILD=ON  -D TESTS=ON -D EXAMPLES=ON 					 
	cmake --build 	build/build_$@ --config Release 
	cmake --build 	build/build_$@ --config Debug 
	cmake -B 		build/build_$@_mingw . -D ARCH=x64 -D X64_BUILD=ON  -D TESTS=ON -D EXAMPLES=OFF -G "MinGW Makefiles"	
	cmake --build 	build/build_$@_mingw 
else 
x64:     	
	cmake -B 		build/build_$@ . -D ARCH=x64 -D X64_BUILD=ON  -D TESTS=ON -D EXAMPLES=ON -D CMAKE_BUILD_TYPE=Release 
	cmake --build 	build/build_$@ 
endif

	
nm6407: nm6407f nm6407i

nm6407f:
	cmake -B 		build/build_$@ . -G Ninja -D ARCH=$@ $(NMC_TOOLCHAIN) -D MC12101_BUILD=ON -D QEMU_BUILD=ON -D TESTS=ON -D EXAMPLES=ON
	cmake --build 	build/build_$@
	cd build/build_$@ && ctest

nm6407i:
	cmake -B 		build/build_$@ . -G Ninja -D ARCH=$@ $(NMC_TOOLCHAIN) -D MC12101_BUILD=ON -D QEMU_BUILD=ON -D TESTS=ON -D EXAMPLES=ON 
	cmake --build 	build/build_$@
	cd build/build_$@ && ctest

nm6476f:
	cmake -B 		build/build_$@ . -G Ninja -D ARCH=$@ $(NMC_TOOLCHAIN) -D MC11101_BUILD=ON -D QEMU_BUILD=ON -D TESTS=ON -D EXAMPLES=ON
	cmake --build 	build/build_$@
	cd build/build_$@ && ctest

nm6476i:
	cmake -B 		build/build_$@ . -G Ninja -D ARCH=$@ $(NMC_TOOLCHAIN) -D MC11102_BUILD=ON -D QEMU_BUILD=ON -D TESTS=ON -D EXAMPLES=ON 
	cmake --build 	build/build_$@
	cd build/build_$@ && ctest

nm6408:
	cmake -B 		build/build_$@ . -G Ninja -D ARCH=$@ $(NMC_TOOLCHAIN) -D NM_CARD_BUILD=ON -D NM_MEZZO_BUILD=ON -D NM_QUAD_BUILD=ON -D QEMU_BUILD=ON -D TESTS=ON -D EXAMPLES=ON
	cmake --build 	build/build_$@
#	cd build/build_$@ && ctest

nm6406:
	cmake -B 		build/build_$@ . -G Ninja -D ARCH=$@ $(NMC_TOOLCHAIN) -D MC5103_BUILD=ON -D QEMU_BUILD=ON -D MAC=10-FE-ED-05-D1-F8 -D TESTS=ON -D EXAMPLES=ON
	cmake --build 	build/build_$@
	cd build/build_$@ && ctest
	
nm6407pack: nm6407
	cmake -E remove_directory build-cpack
	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nm6407
	cd build-cpack && cpack -G 7Z -C "Release;Debug" -DPACK_SUFFIX=nm6407

nm6408pack: nm6408
	cmake -E remove_directory build-cpack
	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nm6408
	cd build-cpack && cpack -G 7Z -C "Release;Debug" -DPACK_SUFFIX=nm6408

#x64
nmc4pack:  nm6407 nm6476i nm6476f nm6408
	cmake -E remove_directory build-cpack
	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nmc4
	cd build-cpack && cpack -G 7Z -C "Release;Debug" -DPACK_SUFFIX=nmc4
	
clean:
	rm -rf build*
	
	
	
#test:
#	cd build/build_mc12705 && ctest