cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)



	option(MC12101_BUILD "Build examples for mc12101" OFF)
	option(MB7707_BUILD  "Build examples for mb7707" OFF)
	option(MC5103_BUILD  "Build examples for mc5103" OFF)
	option(MC7601_BUILD  "Build examples for mc7601" OFF)
	option(MC12705_BUILD "Build examples for mc12705" OFF)
	option(NM_CARD_BUILD "Build examples for nm_card" OFF)
	option(QEMU_BUILD    "Build examples for qemu" OFF)
	option(X64_BUILD     "Build examples for x64" OFF)
	
	option(NMC_TOOLCHAIN "Used NMC Toolchin" OFF)
	
if (ARCH STREQUAL nm6406)	
	set(NMC_ARCH nmc3)	
elseif (ARCH STREQUAL nm6407i) 
	set(NMC_ARCH nmc4-fixed)
elseif (ARCH STREQUAL nm6467i)
	set(NMC_ARCH nmc4-fixed)
elseif (ARCH STREQUAL nm6407f)
	set(NMC_ARCH nmc4-float)
elseif (ARCH STREQUAL nm6408)
	set(NMC_ARCH nmc4-float)
elseif (ARCH STREQUAL nm6467f )
	set(NMC_ARCH nmc4-float)
endif()

if (MC12101_BUILD OR MB7707_BUILD OR MC5103_BUILD OR MC7601_BUILD OR MC12705_BUILD OR NM_CARD_BUILD OR QEMU_BUILD)
	set(CMAKE_TOOLCHAIN_FILE "../nmc-gcc-compile.cmake")
	set(NMC_TOOLCHAIN ON)
	project(nmpp-examples VERSION 0.1.0 LANGUAGES CXX C ASM)
	MESSAGE("########## NMC BUILD ########### with ${CMAKE_TOOLCHAIN_FILE}")
else()
	MESSAGE("########## X64 BUILD ########### with ${CMAKE_TOOLCHAIN_FILE}")
	set(NMC_TOOLCHAIN OFF)
	project(nmpp-examples VERSION 0.1.0 LANGUAGES CXX C)
endif()



enable_testing()


if (CMAKE_HOST_WIN32 AND CMAKE_GENERATOR MATCHES "Ninja")
    file(
        WRITE "${CMAKE_BINARY_DIR}/GNUMakeRulesOverwrite.cmake" 
            "STRING(REPLACE \"-MD\" \"-MMD\" CMAKE_DEPFILE_FLAGS_C \"\${CMAKE_DEPFILE_FLAGS_C}\")\n"
            "STRING(REPLACE \"-MD\" \"-MMD\" CMAKE_DEPFILE_FLAGS_CXX \"\${CMAKE_DEPFILE_FLAGS_CXX}\")\n"
    )
    set(CMAKE_USER_MAKE_RULES_OVERRIDE "${CMAKE_BINARY_DIR}/GNUMakeRulesOverwrite.cmake" CACHE INTERNAL "")
endif()


if (CMAKE_HOST_WIN32)
	STRING(REPLACE " " "\\ " NMC_GCC_TOOLPATH_SPACED $ENV{NMC_GCC_TOOLPATH})
	set( SHELL "SHELL=cmd" )
	set( INCLUDE_MK "-include ${NMC_GCC_TOOLPATH_SPACED}\\nmc4-ide\\include\\nmc4vars_win.mk")
	set( OS_RM "del")
else()
 	set( OS_RM " rm -f -r")
endif()
	

#include(../cmake-variables.cmake)

set(CMAKE_CONFIGURATION_TYPES "Release;Debug")

#set(CMAKE_BUILD_TYPE "")
#set(CMAKE_TOOLCHAIN_FILE "nmc-gcc-compile.cmake")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_EXTENSIONS OFF)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)



#list(APPEND nmc4i_s_files 	${s_files})



#message("#######dirs: ${dirs}")
#return ()

#
#function(CONFIGURE_EXAMPLE TEMPL_DIR SRC_DIR DST_DIR BSP CORE LIBS LIBSD LDS RECIPE_RUN RECIPE_RUND RECIPE_EXTRA)	
#
#endfunction()

# esampe of TEST_DIR float/nmblas/nmblas_dcopy
function(CONFIGURE_EXAMPLE IN_TEST_DIR BOARD CORE )	

	get_filename_component(STEP_NAME ${IN_TEST_DIR} NAME)
	file(GLOB 	s_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR}/${IN_TEST_DIR} ${IN_TEST_DIR}/*.S)
	file(GLOB 	cpp_files RELATIVE ${CMAKE_CURRENT_LIST_DIR}/${IN_TEST_DIR} ${IN_TEST_DIR}/*.cpp)
	file(GLOB 	c_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR}/${IN_TEST_DIR} ${IN_TEST_DIR}/*.c)
	
	list(APPEND SRC_LIST ${s_files})
	list(APPEND SRC_LIST ${cpp_files})
	list(APPEND SRC_LIST ${c_files})
	
	list(LENGTH SRC_LIST SRC_COUNT)
	if (NOT SRC_COUNT  )
		return()
	endif()	
	
	#MESSAGE("=== ${SRC_LIST}")	
	#MESSAGE("=== ${IN_TEST_DIR}")	
	#return()
	
	list(JOIN SRC_LIST " " SRC_FILES) # SRC_FILES is @ argument for .in
	
	MESSAGE("### BOARD:${BOARD} core:${CORE} dir:${TEST_DIR} name:${STEP_NAME}") # src: ${SRC_FILES}")	
	
	#set(OUT_TEST_DIR ${BOARD}${CORE}/${IN_TEST_DIR})
	set(OUT_TEST_DIR examples-${BOARD}${CORE}/${IN_TEST_DIR})
	file(COPY ${IN_TEST_DIR} DESTINATION ${OUT_TEST_DIR}/..) # copy main.cpp & co
	
	if (NOT BOARD STREQUAL "x64")
		string(TOUPPER ${BOARD} BSP) 	# BSP is @ argument for .in
		set(TARGET test)				# TARGET is @ argument for .in
	
		set(GCC_EXEC_PREFIX "/cygdrive/$ENV{NMC_GCC_TOOLPATH}/nmc4-ide/lib/gcc/")
		STRING(REPLACE "\\" "/" GCC_EXEC_PREFIX ${GCC_EXEC_PREFIX})
		STRING(REPLACE ":" "" GCC_EXEC_PREFIX ${GCC_EXEC_PREFIX})
		
		configure_file ("./templates/Makefile.in"  				"${OUT_TEST_DIR}/Makefile" )
		configure_file ("./templates/${LDS}" 					"${OUT_TEST_DIR}/${LDS}" )
		
		if (CMAKE_HOST_WIN32)
			configure_file ("./templates/build.bat.in" 			"${OUT_TEST_DIR}/build.bat" )
			configure_file ("./templates/run.bat.in"   			"${OUT_TEST_DIR}/run.bat" )
		else()
			configure_file ("./templates/build.sh.in"  			"${OUT_TEST_DIR}/build.sh" )
			configure_file ("./templates/run.sh.in"   			"${OUT_TEST_DIR}/run.sh" )
		endif()
	endif()
endfunction()

function(CONFIGURE_TEST_NMC IN_TEST_DIR BOARD CORE )	
	#set(ARCH NM6407)
	if (NMC_TOOLCHAIN)
		get_filename_component(STEP_NAME ${IN_TEST_DIR} NAME)
		
		set(TEST_NAME test-${BOARD}${CORE}-${STEP_NAME})
		file(GLOB 	s_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.S)
		file(GLOB 	cpp_files RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.cpp)
		file(GLOB 	c_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.c)
		
		list(APPEND SRC_LIST ${s_files})
		list(APPEND SRC_LIST ${cpp_files})
		list(APPEND SRC_LIST ${c_files})
		list(LENGTH SRC_LIST SRC_COUNT)
		
		#MESSAGE("### BOARD:${BOARD} core:${CORE} dir:${TEST_DIR} name:${STEP_NAME}") # src: ${SRC_FILES}")	

		if (NOT SRC_COUNT  )
			return()
		endif()	
		
		string(TOUPPER ${BOARD} BSP)
		
		add_executable(${TEST_NAME}  ${SRC_LIST})
		#add_dependencies(${TEST_NAME} ${test_lib})
		string(REPLACE " " ";" LIBS_LIST ${LIBS})
		target_link_directories   (${TEST_NAME} PUBLIC	$ENV{${BSP}}/lib ../lib)
		target_link_libraries     (${TEST_NAME} ${LIBS_LIST})
		target_include_directories(${TEST_NAME} PUBLIC $ENV{BSP}/include ../include)
		
		set_target_properties(${TEST_NAME} PROPERTIES LINKER_LANGUAGE CXX)

		if     ( BOARD STREQUAL "mc5103" OR BOARD STREQUAL "mb7707")
			target_link_options(${TEST_NAME} PUBLIC	-T${CMAKE_CURRENT_SOURCE_DIR}/templates/${LDS}  ) # -v 
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc3;-O2>)	
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc3;-Werror>)	
		elseif ( BOARD STREQUAL "mc12101" AND CORE STREQUAL "-nmpu1")
			target_link_options(${TEST_NAME} PUBLIC	-T${CMAKE_CURRENT_SOURCE_DIR}/templates/${LDS}  ) # -v 
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc4-fixed;-O2>)	
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc4-fixed;-Werror>)	
		elseif ( BOARD STREQUAL "mc12101" AND CORE STREQUAL "-nmpu0")
			target_link_options(${TEST_NAME} PUBLIC	-T${CMAKE_CURRENT_SOURCE_DIR}/templates/${LDS}  ) # -v 
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc4-float;-O2>)	
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc4-float;-Werror>)	
		elseif ( BOARD STREQUAL "mc12705")
			target_link_options(${TEST_NAME} PUBLIC	-T${CMAKE_CURRENT_SOURCE_DIR}/templates/${LDS}  ) # -v 
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc4-float;-O2>)	
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc4-float;-Werror>)
		elseif ( BOARD STREQUAL "nm_card")
			target_link_options(${TEST_NAME} PUBLIC	-T${CMAKE_CURRENT_SOURCE_DIR}/templates/${LDS}  ) # -v 
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc4-float;-O2>)	
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc4-float;-Werror>)
		elseif ( BOARD STREQUAL "qemu")
			target_link_options(${TEST_NAME} PUBLIC	-T${CMAKE_CURRENT_SOURCE_DIR}/templates/${LDS}  ) # -v 
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-mnmc4;-O2>)	
			target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-mnmc4;-Werror>)
		endif()
	
		string(REPLACE "-v" "" CRUNOPT ${RUNOPT})
		string(REPLACE " " ";" OPTS ${CRUNOPT})
		add_test(NAME ${TEST_NAME} COMMAND ${RUNNER} $<TARGET_FILE:${TEST_NAME}> ${OPTS})
	else()
		MESSAGE("WARNING: CONFIGURE_TEST_NMC SKIPPED DUE NMC_TOOLCHAIN IS ${NMC_TOOLCHAIN}")
	endif()
endfunction()

function(CONFIGURE_TEST_X64 IN_TEST_DIR BOARD CORE )	
	#set(ARCH NM6407)
	if (NOT NMC_TOOLCHAIN)
		get_filename_component(STEP_NAME ${IN_TEST_DIR} NAME)
		
		set(TEST_NAME test-${BOARD}${CORE}-${STEP_NAME})
		file(GLOB 	s_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.S)
		file(GLOB 	cpp_files RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.cpp)
		file(GLOB 	c_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.c)
		
		list(APPEND SRC_LIST ${s_files})
		list(APPEND SRC_LIST ${cpp_files})
		list(APPEND SRC_LIST ${c_files})
		list(LENGTH SRC_LIST SRC_COUNT)
		
		#MESSAGE("### BOARD:${BOARD} core:${CORE} dir:${TEST_DIR} name:${STEP_NAME}") # src: ${SRC_FILES}")	

		if (NOT SRC_COUNT  )
			return()
		endif()	
		
		string(TOUPPER ${BOARD} BSP)
		
		add_executable(${TEST_NAME}  ${SRC_LIST})
		#add_dependencies(${TEST_NAME} ${test_lib})
		string(REPLACE " " ";" LIBS_LIST ${LIBS})
		target_link_directories   (${TEST_NAME} PUBLIC	$ENV{${BSP}}/lib ../lib)
		target_link_libraries     (${TEST_NAME} ${LIBS_LIST})
		target_include_directories(${TEST_NAME} PUBLIC $ENV{BSP}/include ../include)
		#target_link_options(${TEST_NAME} PUBLIC	-T${CMAKE_CURRENT_SOURCE_DIR}/templates/${LDS}  ) # -v 
		
		
		add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} $<TARGET_FILE:${TEST_NAME}> ${OPTS})
	else()
		MESSAGE("WARNING: CONFIGURE_TEST_X64 SKIPPED DUE NMC_TOOLCHAIN IS ${NMC_TOOLCHAIN}")
	endif()
endfunction()





#set(steps_risc steps_risc/step01 steps_risc/step02 steps_risc/step03 steps_risc/step03a steps_risc/step04 steps_risc/step04a) 
#set(stepis_fixed steps_fixed/stepi05 steps_fixed/stepi06 steps_fixed/stepi06a steps_fixed/stepi06b steps_fixed/stepi07 steps_fixed/stepi08 steps_fixed/stepi09 steps_fixed/stepi10 steps_fixed/stepi11 steps_fixed/stepi12 steps_fixed/stepi13 steps_fixed/stepi13a steps_fixed/stepi14) 
#set(steps_float steps-float/stepf01 steps-float/stepf02 steps-float/stepf02a steps-float/stepf02b) 

#${CMAKE_CURRENT_SOURCE_DIR} 

file(GLOB 	 examples_risc  RELATIVE ${CMAKE_CURRENT_LIST_DIR} risc/*  )
#file(GLOB 	 examples_fixed RELATIVE ${CMAKE_CURRENT_LIST_DIR} fixed/nmpps/* )
file(GLOB 	 examples_float RELATIVE ${CMAKE_CURRENT_LIST_DIR} float/nmblas/* float/fft/* )

#file(GLOB 	 examples_risc  ${CMAKE_CURRENT_LIST_DIR}/examples/risc/*  )
#file(GLOB 	 examples_fixed RELATIVE ${CMAKE_CURRENT_LIST_DIR} fixed/nmpps/* )
#file(GLOB 	 examples_float ${CMAKE_CURRENT_LIST_DIR} float/nmblas/* float/fft/* )

#string(REPLACE )

#MESSAGE(---------${CMAKE_CURRENT_LIST_DIR})
#MESSAGE(---------:: ${examples_float})
#return()
#STRING(REPLACE "${CMAKE_CURRENT_LIST_DIR}/" "" examples_risc  "${examples_risc}")
#STRING(REPLACE "${CMAKE_CURRENT_LIST_DIR}/" "" examples_fixed "${examples_fixed}")
#STRING(REPLACE "${CMAKE_CURRENT_LIST_DIR}/" "" examples_float "${examples_float}")






set(EXTRA_TARGETS "")

		
if ( MC5103_BUILD )
	set(BOARD "mc5103")
	set(dir_list ${examples_fixed} )
	set(CXXFLAGS " -O2 -Wall -mnmc3 -g")
	set(LDS 	"${BOARD}.lds")
	set(LIBS  	"-lnmpp-nm6406 -Wl,--whole-archive -lmc5103lib -Wl,--no-whole-archive")
	set(LIBSD 	"-lnmpp-nm6406 -Wl,--whole-archive -lmc5103lib -Wl,--no-whole-archive")
	set(RUNNER "${BOARD}run")
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE(${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
    endforeach()
endif()	


if ( MB7707_BUILD)
	set(BOARD mb7707)
	set(dir_list ${examples_fixed} )
	set(CXXFLAGS " -O2 -Wall -mnmc3 -g")
	set(LIBS  	"-lnmpp-nm6406 -Wl,--whole-archive -lmb7707lib -Wl,--no-whole-archive")
	set(LIBSD 	"-lnmpp-nm6406 -Wl,--whole-archive -lmb7707lib -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}.lds")
	set(RUNNER  "${BOARD}run")
	set(RUNOPT  "-a${MAC} ")
	set(RUNOPTD "-a${MAC} ")
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE(${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
    endforeach()
endif()	


if (MC12101_BUILD)
	set(BOARD mc12101)
	if (ARCH STREQUAL nm6407f)
		set(dir_list ${examples_risc} ${examples_float} )
		set(CXXFLAGS " -O2 -Wall -mnmc4-float -g")
		set(LIBS  	" -lnmpp-nm6407f -lnm6407int -Wl,--whole-archive -lnm6407_io_nmc -lmc12101load_nm -Wl,--no-whole-archive")
		set(LIBSD 	" -lnmpp-nm6407f -Wl,--whole-archive -lnm6407_io_nmc -lmc12101_stub_nmc4_float -Wl,--no-whole-archive")
		set(LDS 	"${BOARD}-nmpu0.lds")
		set(RUNNER  "${BOARD}run")
		set(RUNOPT	"-p -R -a0 -v" )
		set(RUNOPTD "-p -R -a0 -v" )
		foreach(dir ${dir_list})
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
			CONFIGURE_TEST_NMC(${dir} ${BOARD} "-nmpu0" )
		endforeach()	
	endif()
	
	if (ARCH STREQUAL nm6407i)
		set(dir_list ${examples_risc} ${examples_fixed} )
		set(CXXFLAGS " -O2 -Wall -mnmc4-fixed -g")
		set(LIBS  	" -lnmpp-nm6407i -lnm6407int -Wl,--whole-archive -lnm6407_io_nmc -lmc12101load_nm -Wl,--no-whole-archive")
		set(LIBSD 	" -lnmpp-nm6407i -Wl,--whole-archive -lnm6407_io_nmc -lmc12101_stub_nmc4_fixed -Wl,--no-whole-archive")
		set(LDS 	"${BOARD}-nmpu1.lds")
		set(RUNNER "${BOARD}run")
		set(RUNOPT  "-p -R -a1 -v" )
		set(RUNOPTD "-p -R -a1 -v" )
		set(MONITOR "nmc-monitor")
		
		foreach(dir ${dir_list})
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
			CONFIGURE_TEST_NMC(${dir} ${BOARD} "-nmpu1")
		endforeach()
	endif()
endif()	



if (MC12705_BUILD)
	set(BOARD "mc12705")
	set(dir_list ${examples_risc} ${examples_float} )
	set(CXXFLAGS " -O2 -Wall -mnmc4-float -g")
	set(LIBS  	"-lnmpp-nm6408 -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -Wl,--no-whole-archive")
	set(LIBSD 	"-lnmpp-nm6408 -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -lnm6408_stub -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}.lds")
	set(RUNNER  "${BOARD}run")
	set(RUNOPT 	"-c0 -n0 -v")
	set(RUNOPTD "-c0 -n0 -v")
	set(MONITOR "nmc-monitor")
	
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
    endforeach()
endif()	

if (NM_CARD_BUILD)
	set(BOARD "nm_card")
	set(dir_list ${examples_risc} ${examples_float} )
	set(CXXFLAGS " -O2 -Wall -nmc4-float -g")
	set(LIBS  	"-lnmpp-nm6408 -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -Wl,--no-whole-archive")
	set(LIBSD 	"-lnmpp-nm6408 -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -lnm6408_stub -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}.lds")
	set(RUNNER  "${BOARD}_run")
	set(RUNOPT 	"-c0 -n0 -v")
	set(RUNOPTD "-c0 -n0 -v")
	set(MONITOR "nmc-monitor")
	
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
    endforeach()
endif()	


if ( QEMU_BUILD )
	set(BOARD qemu)
	MESSAGE("##############")
	set(dir_list ${examples_risc} ${examples_fixed} )
	set(CXXFlAGS " -O2 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
	set(LIBS  	"-lnmpp-${ARCH} -lc")
	set(LIBSD 	"-lnmpp-${ARCH} -lc")
	set(LDS 	"${BOARD}-${ARCH}.lds")
	set(RUNNER 	"nmc-qemu")
	set(RUNOPT 	" ")
	set(RUNOPTD "-g 5555")
	set(MONITOR "")
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} qemu "")
	endforeach()


endif()	


if ( X64_BUILD )
	set(BOARD x64)
	MESSAGE("######## x64 ######")
	set(dir_list ${examples_risc} ${examples_fixed} ${examples_float})
	#set(CXXFlAGS " -O2 -Wall -mnmc4 -g -I$(NMPP)/include -L$(NMPP)/lib")
	set(LIBS  	"nmpp-x64")
	set(LIBSD 	"nmpp-x64d")
	#set(RUNNER  "${BOARD}run")
	#set(LDS 	"qemu.lds")
	#set(RUNNER 	"nmc-qemu")
	#set(RUNOPT 	" ")
	#set(RUNOPTD "-g 5555")
	#set(MONITOR "")
	foreach(dir ${dir_list})
		MESSAGE("EXAMPLE ######## x64 ###### ${dir}")
		CONFIGURE_EXAMPLE (${dir} x64 "")
		CONFIGURE_TEST_X64(${dir} x64 "")
    endforeach()
	
	#file(COPY ./templates/CMakeLists.txt DESTINATION examples-x64) # copy main.cpp & co
	set (ROOT "../.." )
	configure_file ("./templates/CMakeLists.txt.in" "examples-x64/CMakeLists.txt" )
	
endif()	
	



#string(SUBSTRING ${ARCH} 2 4 NMC_CORE_VERSION )			 

set_source_files_properties( ${nmc4f_asm_files} ${nmc4i_asm_files} ${nmc4r_asm_files}
			 PROPERTY
			 COMPILE_FLAGS " -mmas -Wa,-split_sir -Wa,-W-111"
			 )

set_source_files_properties( ${s_files} 
			 PROPERTY
			 COMPILE_FLAGS "-mgas -DNMC_CORE_VERSION=${NMC_CORE_VERSION}"
			 )
	




#enable_testing()
#add_subdirectory(app/test)
					
#add_subdirectory(test/context)

#add_subdirectory(monitor)
#add_subdirectory(examples/2nmc-demo-gcc/make_mc12101)
