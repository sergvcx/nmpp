
ifeq ($(OS),Windows_NT)
SHELL=cmd
space := $(subst ,, )
NMC_TOOLPATH=$(subst $(space),\$(space),$(NMC_GCC_TOOLPATH))
-include $(NMC_TOOLPATH)\nmc4-ide\include\nmc4vars_win.mk
OS_RM    = del 
else 
OS_RM    = rm -f -r
endif


#all: nm6406 nm6407i nm6407f nm6408 nm6476i nm6476f x64

nm6406:
	cmake -B 		build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6406  -D MC5103_BUILD=ON -D QEMU_BUILD=ON	
	cmake --build 	build_$@_release
	cmake -B 		build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6406   
	cmake --build 	build_$@_debug 
	
nm6407i:
	cmake -B 		build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6407i  -D MC12101_BUILD=ON -D QEMU_BUILD=ON	
	cmake --build 	build_$@_release
	cmake -B 		build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6407i  
	cmake --build 	build_$@_debug 
	
	
nm6407f:
	cmake -B 		build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6407f  -D MC12101_BUILD=ON -D QEMU_BUILD=ON	
	cmake --build 	build_$@_release
	cmake -B 		build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6407f  
	cmake --build 	build_$@_debug 

nm6408:
	cmake -B 		build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6408  -D NM_CARD_BUILD=ON -D QEMU_BUILD=ON	
	cmake --build 	build_$@_release
	cmake -B 		build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6408  
	cmake --build 	build_$@_debug 

nm6476i:
	cmake -B 		build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6476i  -D MC11101_BUILD=ON -D QEMU_BUILD=ON	
	cmake --build 	build_$@_release
	cmake -B 		build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6476i  
	cmake --build 	build_$@_debug 
	
	
nm6476f:
	cmake -B 		build_$@_release . 	-G Ninja -DCMAKE_BUILD_TYPE=Release	-D ARCH=nm6476f  -D MC11101_BUILD=ON -D QEMU_BUILD=ON	
	cmake --build 	build_$@_release
	cmake -B 		build_$@_debug . 	-G Ninja -DCMAKE_BUILD_TYPE=Debug 	-D ARCH=nm6476f  
	cmake --build 	build_$@_debug 


x64:
	cmake -B 		build_$@ . -G "Visual Studio 15 2017 Win64" -D ARCH=x64 -D X64_BUILD=ON 
	cmake --build 	build_$@ 
	

nm6406pack: x64 nm6406
	cmake -D PACK_SUFFIX=nm6406 build_x64
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release" 

nm6407pack: x64 nm6407i nm6407f 
	cmake -D PACK_SUFFIX=nm6407 build_x64
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release"  

nm6476pack: x64 nm6476i nm6476f 
	cmake -D PACK_SUFFIX=nm6476 build_x64
	cpack -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release" 

nm6408pack: x64 nm6408 
	cmake -D PACK_SUFFIX=nm6408 build_x64
	cpack -D PACK_SUFFIX:STRING=nm6408 -DCPACK_PACK_SUFFIX=XXX -G 7Z --config cmake/MultiCPackConfig.cmake -C "Debug;Release" 

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
