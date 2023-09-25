
ifeq ($(OS),Windows_NT)
SHELL=cmd
#space := $(subst ,, )
#NMC_TOOLPATH=$(subst $(space),\$(space),$(NMC_GCC_TOOLPATH))
#-include $(NMC_TOOLPATH)\nmc4-ide\include\nmc4vars_win.mk
#X64_TOOLCHAIN="Visual Studio 15 2017 Win64"
OS_RM    = del 
else 
OS_RM    = rm -f -r
#X64_TOOLCHAIN="Unix Makefiles"
endif


all: nm6406 nm6407i nm6407f nm6408 nm6476i nm6476f x64

setenv:
	setx NMPP "%CD%"
	
nm6406:
	cmake -B 		build/build_$@_release . -G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6406  -D MC5103_BUILD=ON -D QEMU_BUILD=ON	 -D TESTS=ON -D EXAMPLES=OFF
	cmake -B 		build/build_$@_debug .   -G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6406   
	cmake --build 	build/build_$@_release
	cmake --build 	build/build_$@_debug 
						  
nm6407:                   
	cmake -B 		build/build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6407 -D TESTS=ON -D EXAMPLES=ON -D MC12101_BUILD=ON -D QEMU_BUILD=ON -DMC12101_RUNNER=mc12101run  -DCMAKE_TOOLCHAIN_FILE="./cmake/nmc-gcc-toolchain.cmake"
	cmake --build 	build/build_$@_release 
	cmake -B 		build/build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6407   -DCMAKE_TOOLCHAIN_FILE="./cmake/nmc-gcc-toolchain.cmake"
	cmake --build 	build/build_$@_debug 
						  
nm6407i:                  
	cmake -B 		build/build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6407i -D TESTS=ON -D EXAMPLES=ON -D MC12101_BUILD=ON -D QEMU_BUILD=ON -DMC12101_RUNNER="hal-run --server_ip=proton --server_port=5557"
	cmake --build 	build/build_$@_release                                                        
	cmake -B 		build/build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6407i 
	cmake --build 	build/build_$@_debug 
						  
						  
nm6407f:                  
	cmake -B 		build/build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6407f  -D TESTS=ON -D EXAMPLES=ON -D MC12101_BUILD=ON -D QEMU_BUILD=ON  -DMC12101_RUNNER=mc12101run -DCMAKE_TOOLCHAIN_FILE="./cmake/nmc-gcc-toolchain.cmake"
	cmake --build 	build/build_$@_release
	cmake -B 		build/build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6407f  -DCMAKE_TOOLCHAIN_FILE="./cmake/nmc-gcc-toolchain.cmake"
	cmake --build 	build/build_$@_debug 
	
#cmake -B 		build/build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6408  -D NM_CARD_BUILD=ON -D QEMU_BUILD=ON		
	
nm6408:                   
	cmake -B 		build/build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6408  -D TESTS=ON -D EXAMPLES=ON -D MC12705_BUILD=ON -D QEMU_BUILD=ON -DCMAKE_TOOLCHAIN_FILE="./cmake/nmc-gcc-toolchain.cmake"
	cmake --build 	build/build_$@_release
	cmake -B 		build/build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6408  -DCMAKE_TOOLCHAIN_FILE="./cmake/nmc-gcc-toolchain.cmake"
	cmake --build 	build/build_$@_debug 
						  
nm6476i:                  
	cmake -B 		build/build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6476i  -D MC11102_BUILD=ON -D QEMU_BUILD=ON	
	cmake --build 	build/build_$@_release
	cmake -B 		build/build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6476i  
	cmake --build 	build/build_$@_debug 
						 
						 
nm6476f:                 
	cmake -B 		build/build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6476f  -D MC11101_BUILD=ON -D QEMU_BUILD=ON	
	cmake --build 	build/build_$@_release
	cmake -B 		build/build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6476f  
	cmake --build 	build/build_$@_debug 
						 
						 
x64:          
	cmake -B 		build/build_$@ . -A x64 -D ARCH=x64 -D X64_BUILD=ON  -D TESTS=ON -D EXAMPLES=ON 
	cmake --build 	build/build_$@ --config Release 
	cmake --build 	build/build_$@ --config Debug 
	cmake -B 		build/build_$@_mingw . -D ARCH=x64 -D X64_BUILD=ON  -D TESTS=ON -D EXAMPLES=ON -G "MinGW Makefiles"	
	cmake --build 	build/build_$@_mingw 
	
#	cmake -B 		build/build_$@ .  -D ARCH=x64 -D X64_BUILD=ON  -D TESTS=ON -D EXAMPLES=ON -G "MinGW Makefiles"
#	cmake -B 		build/build_$@ .  -D ARCH=x64 -D X64_BUILD=ON  -D TESTS=ON -D EXAMPLES=ON -G "MSYS Makefiles"


	
nm6406pack: x64 nm6406
	cmake -D PACK_SUFFIX=nm6406 build/build_x64
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release" 

#nm6407pack: x64 nm6407
#	cmake -D PACK_SUFFIX=nm6407 build/build_x64
#	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release"  



#x64 nm6407

#nm6407all: 
#	cmake --preset nm6407-release
#	cmake --preset nm6407-debug
#	cmake --preset x64-msvc
#	cmake --preset x64-gcc
#	cmake --build build-nm6407-release
#	cmake --build build-nm6407-debug
#	cmake --build build-x64-msvc
#	cmake --build build-x64-gcc
#	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nm6407
#	cd build-cpack && cpack -G 7Z -C Release;Debug -DPACK_SUFFIX=nm6407

nm6407pack:
	rd /Q /S build-cpack
	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nm6407
	cd build-cpack && cpack -G 7Z -C Release;Debug -DPACK_SUFFIX=nm6407

хотя: 
	rd /Q /S build-cpack
	cmake -D PACK_SUFFIX=nm6408 build/build_x64
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release"  


#	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release"  
#	rd /S /Y build-cpack

nm6476ipack: x64 nm6476i 
	cmake -D PACK_SUFFIX:STRING=nm6476i build/build_x64
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release" 

nm6476fpack: x64 nm6476f 
	cmake -D PACK_SUFFIX:STRING=nm6476f build/build_x64
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release" 

#nm6408pack: x64 nm6408 
#	cmake -B 		build/build_nm6408_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6408  -D TESTS=ON -D EXAMPLES=ON -D NM_CARD_BUILD=ON -D QEMU_BUILD=OFF
#	cmake --build 	build/build_nm6408_release
#	cmake -B 		build/build_nm6408_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6408  
#	cmake --build 	build/build_nm6408_debug 
#	cmake -D PACK_SUFFIX:STRING=nm6408 build/build_x64
#	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release"  

#	rm build-cpack
#
#nm6408pack:
#	rm build-cpack
#	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nm6408
#	cd build-cpack && cpack -G 7Z -C Release;Debug -DPACK_SUFFIX=nm6408


#nm6408pack_mc12705: 
#	cmake -B 		build/build_x64 . -A x64 -D ARCH=x64 -D X64_BUILD=ON  -D TESTS=OFF -D EXAMPLES=ON
#	cmake --build 	build/build_x64 --config Release
#	cmake --build 	build/build_x64 --config Debug
#	
#	cmake -B 		build/build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6408  -D TESTS=OFF -D EXAMPLES=ON -D MC12705_BUILD=ON -D QEMU_BUILD=ON		
#	cmake --build 	build/build_$@_release
#	cmake -B 		build/build_$@_debug .   	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6408  
#	cmake --build 	build/build_$@_debug 
#	cmake -D PACK_SUFFIX:STRING=nm6408 build/build_x64
#	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release"  
	
	
#	cpack -D PACK_SUFFIX:STRING=nm6408 -DCPACK_PACK_SUFFIX=XXX -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release" 

#cmake -D PACK_SUFFIX:STRING=nm6408 build_x64

nm6408preset: x64
#	cmake --list-presets=all .
	cmake --preset nmpp-nm6408
	cmake --build --preset nmpp-nm6408-release
#	ctest --preset nmpp-nm6408


nm6408presetpack:
	cpack --preset nmpp-nm6408
	
x64test:
	cd build_x64 && ctest -C Debug

nm6407ftest:
	cd build_nm6407f && ctest -C Debug
