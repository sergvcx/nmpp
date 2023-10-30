
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

rls =Release
dbg =Debug
NMC_TOOLCHAIN = -DCMAKE_TOOLCHAIN_FILE="./cmake/nmc-gcc-toolchain.cmake"
all: nm6406 nm6407 nm6408 nm6476i nm6476f x64

all_pack: nm6407pack nm6408pack nm6476ipack nm6476fpack 

setenv:
	setx NMPP "%CD%"
	
nm6406:
	cmake -B 		build/build_$@_release . -G Ninja -DCMAKE_BUILD_TYPE=Release -D ARCH=$@ $(NMC_TOOLCHAIN) -D TESTS=OFF -D EXAMPLES=ON -D MC5103_BUILD=ON -D QEMU_BUILD=ON	 
	cmake -B 		build/build_$@_debug .   -G Ninja -DCMAKE_BUILD_TYPE=Debug 	 -D ARCH=$@ $(NMC_TOOLCHAIN)    
	cmake --build 	build/build_$@_release
	cmake --build 	build/build_$@_debug 
						  
nm6407_:
	cmake -B 		build/build_$@_release . -G Ninja -DCMAKE_BUILD_TYPE=Release -D ARCH=$@ $(NMC_TOOLCHAIN) -D TESTS=ON -D EXAMPLES=ON -D MC12101_BUILD=ON -D QEMU_BUILD=ON -DMC12101_RUNNER=mc12101run
	cmake -B 		build/build_$@_debug . 	 -G Ninja -DCMAKE_BUILD_TYPE=Debug 	 -D ARCH=$@ $(NMC_TOOLCHAIN)
	cmake --build 	build/build_$@_release 
	cmake --build 	build/build_$@_debug 
						  
nm6407: nm6407i nm6407f
						  
nm6407i:                  
	cmake -B 		build/build_$@_release . -G Ninja -DCMAKE_BUILD_TYPE=Release -D ARCH=$@ $(NMC_TOOLCHAIN) -D TESTS=ON -D EXAMPLES=ON -D MC12101_BUILD=ON -D QEMU_BUILD=ON -DMC12101_RUNNER="hal-run --server_ip=proton --server_port=5557" 
	cmake -B 		build/build_$@_debug   . -G Ninja -DCMAKE_BUILD_TYPE=Debug 	 -D ARCH=$@ $(NMC_TOOLCHAIN) 
	cmake --build 	build/build_$@_release                                                        
	cmake --build 	build/build_$@_debug 
						  
nm6407f:                  
	cmake -B 		build/build_$@_release . -G Ninja -DCMAKE_BUILD_TYPE=Release -D ARCH=$@ $(NMC_TOOLCHAIN) -D TESTS=ON -D EXAMPLES=ON -D MC12101_BUILD=ON -D QEMU_BUILD=ON  -DMC12101_RUNNER=mc12101run
	cmake -B 		build/build_$@_debug   . -G Ninja -DCMAKE_BUILD_TYPE=Debug 	 -D ARCH=$@ $(NMC_TOOLCHAIN)  
	cmake --build 	build/build_$@_release                                                                  
	cmake --build 	build/build_$@_debug                                                                    
																											
nm6408:                                                                                                     
	cmake -B 		build/build_$@_release . -G Ninja -DCMAKE_BUILD_TYPE=Release -D ARCH=$@ $(NMC_TOOLCHAIN) -D TESTS=ON -D EXAMPLES=ON -D MC12705_BUILD=ON -D NM_CARD_BUILD=ON -D QEMU_BUILD=ON 
	cmake -B 		build/build_$@_debug   . -G Ninja -DCMAKE_BUILD_TYPE=Debug 	 -D ARCH=$@ $(NMC_TOOLCHAIN)  -D EXAMPLES=OFF
	cmake --build 	build/build_$@_release
	cmake --build 	build/build_$@_debug 
						  
nm6476: nm6476i nm6476f

nm6476i:                  
	cmake -B 		build/build_$@_release . -G Ninja -DCMAKE_BUILD_TYPE=Release -D ARCH=$@ $(NMC_TOOLCHAIN) -D MC11102_BUILD=ON -D QEMU_BUILD=ON -D EXAMPLES=ON
	cmake -B 		build/build_$@_debug   . -G Ninja -DCMAKE_BUILD_TYPE=Debug 	 -D ARCH=$@ $(NMC_TOOLCHAIN)    
	cmake --build 	build/build_$@_release
	cmake --build 	build/build_$@_debug 
						 
nm6476f:                 
	echo "============= config nm6476f release"
	cmake -B 		build/build_$@_release . -G Ninja -DCMAKE_BUILD_TYPE=Release -D ARCH=$@ $(NMC_TOOLCHAIN) -D MC11101_BUILD=ON -D QEMU_BUILD=ON -D EXAMPLES=ON
	echo "============= config nm6476f debug"
	cmake -B 		build/build_$@_debug   . -G Ninja -DCMAKE_BUILD_TYPE=Debug 	 -D ARCH=$@ $(NMC_TOOLCHAIN)
	echo "============= build  nm6476f release"
	cmake --build 	build/build_$@_release
	echo "============= build  nm6476f debug "
	cmake --build 	build/build_$@_debug 
						 

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

	
nmc4pack: x64 nm6407 nm6408 nm6476
	cmake -E remove_directory build-cpack
	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nmc4
	cd build-cpack && cpack -G 7Z -C Release;Debug -DPACK_SUFFIX=nmc4
	
nm6407pack: x64 nm6407
	cmake -E remove_directory build-cpack
	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nm6407
	cd build-cpack && cpack -G 7Z -C Release;Debug -DPACK_SUFFIX=nm6407

nm6408pack: x64 nm6408
	cmake -E remove_directory build-cpack
	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nm6408
	cd build-cpack && cpack -G 7Z -C Release;Debug -DPACK_SUFFIX=nm6408

nm6476ipack: x64 nm6476i
	cmake -E remove_directory build-cpack
	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nm6476i
	cd build-cpack && cpack -G 7Z -C Release;Debug -DPACK_SUFFIX=nm6476i

nm6476fpack: x64 nm6476f
	cmake -E remove_directory build-cpack
	cmake -B build-cpack . -DUSE_CPACK=ON -DPACK_SUFFIX=nm6476f
	cd build-cpack && cpack -G 7Z -C Release;Debug -DPACK_SUFFIX=nm6476f

nm6408pack_old: 
	cmake -E remove_directory build-cpack
	cmake -D PACK_SUFFIX:STRING=nm6408 build/build_x64
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release"  


#	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release"  
#	rd /S /Y build-cpack


nm6406_pack: x64 nm6406
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




nm6476i_pack: x64 nm6476i 
	cmake -D PACK_SUFFIX:STRING=nm6476i build/build_x64
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release" 

nm6476f_pack: x64 nm6476f 
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
