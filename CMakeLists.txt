cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)


#set(CMAKE_USE_RELATIVE_PATHS ON)
#string(REGEX MATCH NM(d+). ARCH_VERSION ${ARCH})

#MESSAGE("######## ${ARCH} ARCH_VERSION ${ARCH_VERSION} ############")
#return()

if (CMAKE_HOST_WIN32 AND CMAKE_GENERATOR MATCHES "Ninja")
    file(
        WRITE "${CMAKE_BINARY_DIR}/GNUMakeRulesOverwrite.cmake" 
            "STRING(REPLACE \"-MD\" \"-MMD\" CMAKE_DEPFILE_FLAGS_C \"\${CMAKE_DEPFILE_FLAGS_C}\")\n"
            "STRING(REPLACE \"-MD\" \"-MMD\" CMAKE_DEPFILE_FLAGS_CXX \"\${CMAKE_DEPFILE_FLAGS_CXX}\")\n"
    )
    set(CMAKE_USER_MAKE_RULES_OVERRIDE "${CMAKE_BINARY_DIR}/GNUMakeRulesOverwrite.cmake" CACHE INTERNAL "")
endif()

option(TESTS  "Build tests" ON)
option(EXAMPLES  "Build examples " ON)
	
set(CMAKE_DEBUG_POSTFIX d)

include(cmake/cmake-variables.cmake)

#set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/nmc-gcc-compile.cmake")
#set(CMAKE_TOOLCHAIN_FILE "nmc-gcc-compile.cmake")

#LIST(APPEND CMAKE_PROGRAM_PATH  $ENV{NMC_GCC_TOOLPATH} )


#add_custom_target(nmc4cmd	COMMAND )
#execute_process(
#    COMMAND bash "-c" $ENV{NMC_GCC_TOOLPATH}/nmc4cmd.bat
#    OUTPUT_VARIABLE FOO
#)
	
set(CMAKE_CONFIGURATION_TYPES "Release;Debug")
#set(CMAKE_CONFIGURATION_TYPES "Release;Debug;MinSizeRel")

set(PROJECT nmpp)


#option (NMC_TOOLCHAIN "Default toolchain is NMC " ON)
option (X64_BUILD "Default toolchain is X64 " OFF)

#option (PACK_SUFFIX "package suffix" "---")

if (X64_BUILD)
	MESSAGE("########## X64 BUILD ########### with ${CMAKE_TOOLCHAIN_FILE}")
	project(${PROJECT} VERSION 2.1.5 LANGUAGES CXX C)
else()
	set(CMAKE_TOOLCHAIN_FILE "cmake/nmc-gcc-compile.cmake")
	MESSAGE("########## NMC BUILD ########### with ${CMAKE_TOOLCHAIN_FILE}")
	project(${PROJECT} VERSION 2.1.5 LANGUAGES CXX C ASM)
endif()
	

MESSAGE("!!!!!!!!! CMAKE_TOOLCHAIN_FILE= ${CMAKE_TOOLCHAIN_FILE}")
MESSAGE("!!!!!!!!! CMAKE_CXX_COMPILER_ID= ${CMAKE_CXX_COMPILER_ID}")





#-G ${nm_generator}
#if (NMC_TOOLCHAIN)
#execute_process(
#		COMMAND ${CMAKE_COMMAND} 
#		-B ${CMAKE_CURRENT_BINARY_DIR}/build_x64 -D ARCH=x64 -D X64_BUILD=ON -D NMC_TOOLCHAIN=OFF  -G "Visual Studio 15 2017 Win64"
#		${CMAKE_CURRENT_LIST_DIR}
#		COMMENT "Building x64")
#
#	if(WIN32)
#		add_custom_target(nmpp_x64_build 
#			ALL 
#			COMMAND $ENV{NMC_GCC_TOOLPATH}/nmc4cmd.bat
#			COMMAND ${CMAKE_COMMAND} --build ${CMAKE_CURRENT_BINARY_DIR}/build_x64 )
#	else()
#		add_custom_target(nmpp_x64_build 
#			ALL 
#			COMMAND ${CMAKE_COMMAND} --build ${CMAKE_CURRENT_BINARY_DIR}/build_x64 )
#	endif()
#endif()	

#set(CMAKE_BUILD_TYPE "Release")


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)

#file(GLOB_RECURSE public_headers RELATIVE ${CMAKE_CURRENT_LIST_DIR} include/*.h)

#MESSAGE("HHH=${public_headers}")
#return()

set(X64_DIRS
	src/risc/init/pc 
	src/risc/init/common 
	src/risc/linear/common 
	src/risc/metric/pc 
	src/risc/metric/common 
	src/risc/support/pc 
	src/risc/support/common 
	
	src/fixed/image/Arithmetics/pc 
	src/fixed/image/Convert/pc 
	src/fixed/image/Convert/common 
	src/fixed/image/Filtration/pc
	src/fixed/image/Filtration/common
	src/fixed/image/Floodfill/pc 
	src/fixed/image/Floodfill/common 
	src/fixed/image/Init/common 
	src/fixed/image/Plessy 
	src/fixed/image/Print/pc
	src/fixed/image/Reodering/pc
	src/fixed/image/Resample/pc
	src/fixed/image/Resample/common
	src/fixed/image/Select/pc
	src/fixed/image/Support/common
	
	src/fixed/matrix/core/pc 
	src/fixed/matrix/init/pc 
	src/fixed/matrix/init/common 
	src/fixed/matrix/linear/pc 
	src/fixed/matrix/metric/common
	
	src/fixed/signal/arithmetic/pc 
	src/fixed/signal/arithmetic/common
	src/fixed/signal/conditional/pc 
	src/fixed/signal/conditional/common 
	src/fixed/signal/core/pc 
	src/fixed/signal/correlation/pc
	src/fixed/signal/filtering/pc 
	src/fixed/signal/filtering/common 
	src/fixed/signal/init/pc 
	src/fixed/signal/init/common 
	src/fixed/signal/logical/pc 
	src/fixed/signal/reordering/pc
	src/fixed/signal/reordering/common
	src/fixed/signal/sampling/pc 
	src/fixed/signal/sampling/common 
	src/fixed/signal/statistical/pc 
	src/fixed/signal/statistical/common 
	
	src/float
	src/float/core/pc
	src/float/arithmetic/pc
	src/float/arithmetic/common
	src/float/conditional/pc
	src/float/init/common
	src/float/init/pc
	src/float/linear
	src/float/metric/common 
	src/float/metric/pc 
	src/float/nmblas/core/pc 
	src/float/nmblas/level1/pc 
	src/float/nmblas/level2/pc 
	#src/float/statistical/Norm/pc
	src/float/statistical/NormDiff/common
	src/float/nmpps/sqrt/pc
	
	
	src/float/transform/fft/common
	src/float/transform/fft/FFTFree/common
	src/float/transform/fft/DFT0008/pc
	src/float/transform/fft/FFT0016/pc
	src/float/transform/fft/FFT0032/pc
	src/float/transform/fft/IFFT0032/pc
	src/float/transform/fft/FFT0064/pc
	src/float/transform/fft/IFFT0064/pc
	src/float/transform/fft/FFT0128/pc
	src/float/transform/fft/IFFT0128/pc
	src/float/transform/fft/FFT0256/pc
	src/float/transform/fft/IFFT0256/pc
	src/float/transform/fft/FFT0512/pc
	src/float/transform/fft/IFFT0512/pc
	src/float/transform/fft/FFT1024/pc
	src/float/transform/fft/IFFT1024/pc
	src/float/transform/fft/FFT2048/pc
	src/float/transform/fft/IFFT2048/pc
	src/float/transform/fft/FFT4096/pc
	src/float/transform/fft/IFFT4096/pc
	
	
	src/float/pcpps/sqrt
	src/float/pcpps/div
	src/float/pcpps/atan
	
)
# [R]ISC source directories
set(NMC4R_DIRS
	#src/risc/fixpoint32/nm
	#src/risc/fixpoint64/nm 
	src/risc/init/nm 
	src/risc/init/common 
	src/risc/linear/common 
	src/risc/metric/nm 
	src/risc/metric/common 
	src/risc/support/nm 
	src/risc/support/common 
	src/risc/tables/nm
)

# [I]nteger math source directories
set(NMC4I_DIRS
	
	src/fixed/image/Arithmetics/nm 
	src/fixed/image/Convert/nm 
	src/fixed/image/Convert/common 
	src/fixed/image/Filtration/nm
	src/fixed/image/Filtration/common
	src/fixed/image/Floodfill/nm 
	src/fixed/image/Floodfill/common 
	src/fixed/image/Init/common 
	src/fixed/image/Plessy 
	src/fixed/image/Print/nm
	src/fixed/image/Reodering/nm
	src/fixed/image/Resample/nm
	src/fixed/image/Resample/common
	src/fixed/image/Select/nm
	src/fixed/image/Support/common
	
	src/fixed/matrix/core/nm 
	src/fixed/matrix/init/nm 
	src/fixed/matrix/init/common 
	src/fixed/matrix/linear/nm 
	src/fixed/matrix/metric/common
	
	src/fixed/signal/arithmetic/nm 
	src/fixed/signal/arithmetic/common
	src/fixed/signal/conditional/nm 
	src/fixed/signal/conditional/common 
	src/fixed/signal/core/nm 
	src/fixed/signal/correlation/nm
	src/fixed/signal/filtering/nm 
	src/fixed/signal/filtering/common 
	src/fixed/signal/init/nm 
	src/fixed/signal/init/common 
	src/fixed/signal/logical/nm 
	src/fixed/signal/reordering/nm
	src/fixed/signal/reordering/common
	src/fixed/signal/sampling/nm 
	src/fixed/signal/sampling/common 
	src/fixed/signal/statistical/nm 
	src/fixed/signal/statistical/common 
	#src/fixed/signal/transform/fft/common
	#src/fixed/signal/transform/fft/FFT0016/nm 
	#src/fixed/signal/transform/fft/FFT0016/common 
	#src/fixed/signal/transform/fft/FFT0032/nm 
	#src/fixed/signal/transform/fft/FFT0032/common 
	#src/fixed/signal/transform/fft/FFT0064/nm 
	#src/fixed/signal/transform/fft/FFT0064/common 
	#src/fixed/signal/transform/fft/FFT0128/nm 
	#src/fixed/signal/transform/fft/FFT0256/nm 
	#src/fixed/signal/transform/fft/FFT0256/common 
	#src/fixed/signal/transform/fft/FFT0512/nm 
	#src/fixed/signal/transform/fft/FFT0512/common 
	#src/fixed/signal/transform/fft/FFT1024/nm
	#src/fixed/signal/transform/fft/FFT1024/common
	#src/fixed/signal/transform/fft/FFT2048/nm 
	#src/fixed/signal/transform/fft/FFT2048/common 
	#src/fixed/signal/transform/fft/FFT4096/nm 
	#src/fixed/signal/transform/fft/FFT4096/common 
	#src/fixed/signal/transform/fft/FFT8192/nm 
	#src/fixed/signal/transform/fft/FFT8192/common 
	#src/fixed/signal/transform/fft/IFFT0256/nm 
	#src/fixed/signal/transform/fft/IFFT0256/common 
	#src/fixed/signal/transform/fft/IFFT0512/nm 
	#src/fixed/signal/transform/fft/IFFT0512/common 
	#src/fixed/signal/transform/fft/IFFT1024/nm 
	#src/fixed/signal/transform/fft/IFFT1024/common 
	#src/fixed/signal/transform/fft/IFFT2048/nm 
	#src/fixed/signal/transform/fft/IFFT4096/common 
	#src/fixed/signal/transform/fft/IFFT8192/nm 
	#src/fixed/signal/transform/fft/FFTFree/common 

	)

# [F]loat point math source directories
set(NMC4F_DIRS
	src/float
	src/float/core/nm
	src/float/arithmetic/nm
	src/float/arithmetic/common
	src/float/conditional/nm
	src/float/init/common
	src/float/init/nm
	src/float/linear
	src/float/metric/common 
	src/float/metric/nm 
	src/float/nmblas/core/nm 
	src/float/nmblas/level1/nm 
	src/float/nmblas/level2/nm 
	#src/float/statistical/Norm/nm
	src/float/statistical/NormDiff/common
	src/float/nmpps/sqrt/nm
	
	
	src/float/transform/fft/common
	src/float/transform/fft/FFTFree/common
	src/float/transform/fft/FFT0032/nm
	src/float/transform/fft/IFFT0032/nm
	src/float/transform/fft/FFT0064/nm
	src/float/transform/fft/IFFT0064/nm
	src/float/transform/fft/FFT0128/nm
	src/float/transform/fft/IFFT0128/nm
	src/float/transform/fft/FFT0256/nm
	src/float/transform/fft/IFFT0256/nm
	src/float/transform/fft/FFT0512/nm
	src/float/transform/fft/IFFT0512/nm
	src/float/transform/fft/FFT1024/nm
	src/float/transform/fft/IFFT1024/nm
	src/float/transform/fft/FFT2048/nm
	src/float/transform/fft/IFFT2048/nm
	src/float/transform/fft/FFT4096/nm
	src/float/transform/fft/IFFT4096/nm
	
	
	src/float/nmpps/sqrt
	src/float/nmpps/div
	src/float/nmpps/atan
)


foreach(dir ${X64_DIRS})
	file(GLOB 	cpp_files 	${dir}/*.cpp)
	file(GLOB 	c_files 	${dir}/*.c)
	list(APPEND x64_cpp_files ${cpp_files})
	list(APPEND x64_c_files 	${c_files})
endforeach()

foreach(dir ${NMC4F_DIRS})
	file(GLOB 	cpp_files 	${dir}/*.cpp)
	file(GLOB 	asm_files 	${dir}/*.asm)	
	file(GLOB 	c_files 	${dir}/*.c)
	file(GLOB 	s_files 	${dir}/*.s)
	file(GLOB 	S_files 	${dir}/*.S)
	list(APPEND nmc4f_cpp_files ${cpp_files})
	list(APPEND nmc4f_asm_files ${asm_files})	
	list(APPEND nmc4f_c_files 	${c_files})
	list(APPEND nmc4f_s_files 	${s_files})
	list(APPEND nmc4f_s_files 	${S_files})
endforeach()

foreach(dir ${NMC4I_DIRS})
	file(GLOB 	cpp_files 	${dir}/*.cpp)
	file(GLOB 	asm_files 	${dir}/*.asm)	
	file(GLOB 	c_files 	${dir}/*.c)
	file(GLOB 	s_files 	${dir}/*.s)
	file(GLOB 	S_files 	${dir}/*.S)
	list(APPEND nmc4i_cpp_files ${cpp_files})
	list(APPEND nmc4i_asm_files ${asm_files})	
	list(APPEND nmc4i_c_files 	${c_files})
	list(APPEND nmc4i_s_files 	${s_files})
	list(APPEND nmc4i_s_files 	${S_files})
endforeach()

foreach(dir ${NMC4R_DIRS})
	file(GLOB 	cpp_files 	${dir}/*.cpp)
	file(GLOB 	asm_files 	${dir}/*.asm)	
	file(GLOB 	c_files 	${dir}/*.c)
	file(GLOB 	s_files 	${dir}/*.s)
	file(GLOB 	S_files 	${dir}/*.S)
	list(APPEND nmc4r_cpp_files ${cpp_files})
	list(APPEND nmc4r_asm_files ${asm_files})	
	list(APPEND nmc4r_c_files 	${c_files})
	list(APPEND nmc4r_s_files 	${s_files})
	list(APPEND nmc4r_s_files 	${S_files})
endforeach()


# ${nmc4r_s_files}
if (ARCH STREQUAL "nm6406")
	MESSAGE("######## ARCH ${ARCH} ############")
	add_library(${PROJECT}-${ARCH} STATIC  ${nmc4i_cpp_files} ${nmc4i_c_files} ${nmc4i_asm_files}  ${nmc4i_s_files}
										   ${nmc4r_cpp_files} ${nmc4r_c_files} ${nmc4r_asm_files} ${nmc4r_s_files}
										)
										
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc3;-O2>)	
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc3;-Werror>)	
	
	target_include_directories(${PROJECT}-${ARCH} 
		PUBLIC 
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/nmpps>"
			"$<INSTALL_INTERFACE:include>" 
			"$<INSTALL_INTERFACE:include/nmpps>" 
			)
	export(TARGETS ${PROJECT}-${ARCH}
		FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}-${ARCH}-targets.cmake
		NAMESPACE nmpp::)		
endif()

if ( ARCH STREQUAL "nm6407i" OR ARCH STREQUAL "nm6476i" )
	MESSAGE("######## ARCH ${ARCH} ############")
	add_library(${PROJECT}-${ARCH} STATIC  ${nmc4i_cpp_files} ${nmc4i_c_files} ${nmc4i_asm_files} ${nmc4i_s_files}
										   ${nmc4r_cpp_files} ${nmc4r_c_files} ${nmc4r_asm_files} ${nmc4r_s_files}
										)
	
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc4-fixed;-O2>)	
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc4-fixed;-Werror>)	
	
	target_include_directories(${PROJECT}-${ARCH} 
		PUBLIC 
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/nmpps>"
			"$<INSTALL_INTERFACE:include>" 
			"$<INSTALL_INTERFACE:include/nmpps>" 
			)
	export(TARGETS ${PROJECT}-${ARCH}
		FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}-${ARCH}-targets.cmake
		NAMESPACE nmpp::)

endif()

if ( ARCH STREQUAL "nm6407f" OR ARCH STREQUAL "nm6408" OR ARCH STREQUAL "nm6476f" )
	MESSAGE("######## ARCH ${ARCH} ############")
	add_library(${PROJECT}-${ARCH} STATIC ${nmc4f_cpp_files} ${nmc4f_c_files} ${nmc4f_asm_files} ${nmc4f_s_files}
										  ${nmc4r_cpp_files} ${nmc4r_c_files} ${nmc4r_asm_files} ${nmc4r_s_files}
										)
	
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc4-float;-O2>)	
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc4-float;-Werror>)	
	
	target_include_directories(${PROJECT}-${ARCH} 
		PUBLIC 
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/nmpps>"
			"$<INSTALL_INTERFACE:include>" 
			"$<INSTALL_INTERFACE:include/nmpps>" 
			)
	export(TARGETS ${PROJECT}-${ARCH}
		FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}-${ARCH}-targets.cmake
		NAMESPACE nmpp::)
	
endif()


#-----------
if ( ARCH STREQUAL "nm6407" )
	set(ARCH nm6407i)
	MESSAGE("######## ARCH ${ARCH} ############")
	add_library(${PROJECT}-${ARCH} STATIC  ${nmc4i_cpp_files} ${nmc4i_c_files} ${nmc4i_asm_files} ${nmc4i_s_files}
										    ${nmc4r_cpp_files} ${nmc4r_c_files} ${nmc4r_asm_files} ${nmc4r_s_files}
										)
	
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc4-fixed;-O2>)	
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc4-fixed;-Werror>)	
	
	target_include_directories(${PROJECT}-${ARCH}
		PUBLIC 
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/nmpps>"
			"$<INSTALL_INTERFACE:include>" 
			"$<INSTALL_INTERFACE:include/nmpps>" 
			)
	export(TARGETS ${PROJECT}-${ARCH}
		FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}-${ARCH}-targets.cmake
		NAMESPACE nmpp::)

	set(ARCH nm6407f)
	MESSAGE("######## ARCH ${ARCH} ############")
	add_library(${PROJECT}-${ARCH} STATIC ${nmc4f_cpp_files} ${nmc4f_c_files} ${nmc4f_asm_files} ${nmc4f_s_files}
										  ${nmc4r_cpp_files} ${nmc4r_c_files} ${nmc4r_asm_files} ${nmc4r_s_files}
										)
	
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc4-float;-O2>)	
	target_compile_options(${PROJECT}-${ARCH} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc4-float;-Werror>)	
	
	target_include_directories(${PROJECT}-${ARCH}
		PUBLIC 
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/nmpps>"
			"$<INSTALL_INTERFACE:include>" 
			"$<INSTALL_INTERFACE:include/nmpps>" 
			)
	export(TARGETS ${PROJECT}-${ARCH}
		FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}-${ARCH}-targets.cmake
		NAMESPACE nmpp::)
	set(ARCH nm6407)
endif()
#-----------
	
	
string(SUBSTRING ${ARCH} 2 4 NMC_CORE_VERSION )			 

set_source_files_properties( ${nmc4f_asm_files} ${nmc4i_asm_files} ${nmc4r_asm_files}
			 PROPERTY
			 COMPILE_FLAGS " -mmas -Wa,-split_sir -Wa,-W-111,-W-109"
			 )

set_source_files_properties( ${nmc4f_s_files} ${nmc4i_s_files} ${nmc4r_s_files}
			 PROPERTY
			 COMPILE_FLAGS "-mgas -DNMC_CORE_VERSION=${NMC_CORE_VERSION}"
			 )
			 
if (ARCH STREQUAL "x64")
	add_library(${PROJECT}-${ARCH} STATIC ${x64_cpp_files} ${x64_c_files} )
	target_include_directories(${PROJECT}-${ARCH} 
		PUBLIC 
			"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
			"$<INSTALL_INTERFACE:include>" 
			)
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		target_compile_options(${PROJECT}-${ARCH} PUBLIC -fpermissive)
	endif()
	
	set_target_properties(${PROJECT}-${ARCH}  
	PROPERTIES 
	LINKER_LANGUAGE CXX
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_LIST_DIR}/lib
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_LIST_DIR}/lib
	PUBLIC_HEADER "${public_headers}")
	
	#set( PDB_OUTPUT_DIRECTORY ../lib)
	export(TARGETS ${PROJECT}-${ARCH}
		FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT}-${ARCH}-targets.cmake
		NAMESPACE nmpp::)
		
endif()

if(ARCH STREQUAL nm6407) 
	install(TARGETS ${PROJECT}-${ARCH}i ${PROJECT}-${ARCH}f
		RUNTIME
			DESTINATION bin
		ARCHIVE 
			DESTINATION lib
		PUBLIC_HEADER 
			DESTINATION include
		COMPONENT ${PROJECT}_${ARCH}
		)
else()

	install(TARGETS ${PROJECT}-${ARCH}
		RUNTIME
			DESTINATION bin
		ARCHIVE 
			DESTINATION lib
		PUBLIC_HEADER 
			DESTINATION include
		COMPONENT ${PROJECT}_${ARCH}
		)
endif()	
	install(DIRECTORY include    DESTINATION .)		
	install(DIRECTORY doc        DESTINATION .)		
	install(FILES README.md      DESTINATION .)		
	
	if (MC12101_BUILD)
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-mc12101 DESTINATION examples/examples-${ARCH}) 
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-qemu-i  DESTINATION examples/examples-${ARCH}) 
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-qemu-f  DESTINATION examples/examples-${ARCH}) 
	endif()
	if (MC11101_BUILD)
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-mc11101 DESTINATION examples/examples-${ARCH}) 
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-qemu 	DESTINATION examples/examples-${ARCH}) 
	endif()
	if (MC11102_BUILD)
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-mc11102 DESTINATION examples/examples-${ARCH}) 
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-qemu 	DESTINATION examples/examples-${ARCH})
	endif()
	if (NM_CARD_BUILD)
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-nm_card DESTINATION examples/examples-${ARCH}) 
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-qemu    DESTINATION examples/examples-${ARCH}) 
	endif()
	if (X64_BUILD)
		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-x64 	DESTINATION examples) # copy main.cpp & co
	endif()


	#if (QEMU_BUILD)
	#	if(ARCH STREQUAL nm6407) 
	#		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-qemu-i  DESTINATION examples/examples-${ARCH}) # copy main.cpp & co
	#		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-qemu-f  DESTINATION examples/examples-${ARCH}) # copy main.cpp & co
	#	else()	
	#		install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples/examples-qemu DESTINATION examples/examples-${ARCH}) # copy main.cpp & co
	#	endif()
	#endif()



#add_subdirectory(examples examples-${ARCH})
if (EXAMPLES)
add_subdirectory(examples)
endif()

include(cmake/Packing.cmake)

if(TESTS)
enable_testing()
add_subdirectory(test)
endif()
					
#add_subdirectory(test/context)

#add_subdirectory(monitor)
#add_subdirectory(examples/2nmc-demo-gcc/make_mc12101)
#set(CMAKE_SUPPRESS_REGENERATION ON)