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

set (NMC_ARCH "nmcxxx")
macro (SET_NMC_ARCH ARCH)
	if (ARCH STREQUAL nm6406)	
		set(NMC_ARCH nmc3)	
	elseif (ARCH STREQUAL nm6407i) 
		set(NMC_ARCH nmc4-fixed)
	elseif (ARCH STREQUAL nm6476i)
		set(NMC_ARCH nmc4-fixed)
	elseif (ARCH STREQUAL nm6407f)
		set(NMC_ARCH nmc4-float)
	elseif (ARCH STREQUAL nm6408)
		set(NMC_ARCH nmc4-float)
	elseif (ARCH STREQUAL nm6476f )
		set(NMC_ARCH nmc4-float)
	endif()
endmacro()	

#if (MC12101_BUILD OR MB7707_BUILD OR MC5103_BUILD OR MC7601_BUILD OR MC12705_BUILD OR NM_CARD_BUILD OR QEMU_BUILD)
if (X64_BUILD)
	MESSAGE("########## X64 BUILD ########### with ${CMAKE_TOOLCHAIN_FILE}")
	set(NMC_TOOLCHAIN OFF)
	project(nmpp-examples VERSION 0.1.0 LANGUAGES CXX C)
else ()
	set(CMAKE_TOOLCHAIN_FILE "../cmake/nmc-gcc-compile.cmake")
	set(NMC_TOOLCHAIN ON)
	project(nmpp-examples VERSION 0.1.0 LANGUAGES CXX C ASM)
	MESSAGE("########## NMC BUILD ########### with ${CMAKE_TOOLCHAIN_FILE}")
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


#if (CMAKE_HOST_WIN32)
#	STRING(REPLACE " " "\\ " NMC_GCC_TOOLPATH_SPACED $ENV{NMC_GCC_TOOLPATH})
#	set( SHELL "SHELL=cmd" )
#	set( INCLUDE_MK "-include ${NMC_GCC_TOOLPATH_SPACED}\\nmc4-ide\\include\\nmc4vars_win.mk")
#	set( OS_RM "del")
#else()
# 	set( OS_RM " rm -f -r")
#endif()
	

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
macro (SPLIT_CMD_ARGS cmd_args cmd args)
	#message ("----------  ${cmd_args}------------")
	string(REPLACE " " ";" cmd_list ${cmd_args})
	#message ("----------  ${cmd_list}------------")
	list(POP_FRONT cmd_list ${cmd})
	#message ("----------  ${cmd_list}------------")
	string(JOIN " " ${args} ${cmd_list})
	#message ("----------  ${${cmd}}+ ${${args}}------------")
endmacro()


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
	
	#BOARD:${BOARD} core:${CORE} dir:${IN_TEST_DIR} name:${STEP_NAME}") # src: ${SRC_FILES}")	
	
	#set(OUT_TEST_DIR ${BOARD}${CORE}/${IN_TEST_DIR})
	set(OUT_TEST_DIR examples-${BOARD}${CORE}/${IN_TEST_DIR})
	file(COPY ${IN_TEST_DIR} DESTINATION ${OUT_TEST_DIR}/..) # copy main.cpp & co
	
	MESSAGE("### CONFIGURE_EXAMPLE :${OUT_TEST_DIR} ")
	if (NOT BOARD STREQUAL "x64")
		string(TOUPPER ${BOARD} BSP) 	# BSP is @ argument for .in
		set(TARGET test)				# TARGET is @ argument for .in
	
		#set(GCC_EXEC_PREFIX "/cygdrive/$ENV{NMC_GCC_TOOLPATH}/nmc4-ide/lib/gcc/")
		#STRING(REPLACE "\\" "/" GCC_EXEC_PREFIX ${GCC_EXEC_PREFIX})
		#STRING(REPLACE ":" "" GCC_EXEC_PREFIX ${GCC_EXEC_PREFIX})
		
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
		
		set(TEST_NAME example-${BOARD}${CORE}-${STEP_NAME})
		file(GLOB 	s_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.S)
		file(GLOB 	cpp_files RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.cpp)
		file(GLOB 	c_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.c)
		
		list(APPEND SRC_LIST ${s_files})
		list(APPEND SRC_LIST ${cpp_files})
		list(APPEND SRC_LIST ${c_files})
		list(LENGTH SRC_LIST SRC_COUNT)
		
		MESSAGE("### CONFIGURE_TEST_NMC:${TEST_NAME}  ")

		### BOARD:${BOARD} core:${CORE} dir:${IN_TEST_DIR} name:${STEP_NAME}") # src: ${SRC_FILES}")	

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

		target_link_options   (${TEST_NAME} PUBLIC -T${CMAKE_CURRENT_SOURCE_DIR}/templates/${LDS}  ) # -v 
		target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-m${NMC_ARCH};-O2>)	
		target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-m${NMC_ARCH};-Werror>)	
	
		#MESSAGE("RUNOPT=" ${RUNOPT})
		string(REPLACE "-v" "" CRUNOPT ${RUNOPT})
		string(REPLACE " " ";" OPTS ${CRUNOPT})
		#SPLIT_CMD_ARGS(${RUNNER} RUNNER_EXE RUNNER_ARGS)
		# split RUNNER into EXE ans ARGS
		string(REPLACE " " ";" RUNNER_ARGS ${RUNNER})
		list(POP_FRONT RUNNER_ARGS RUNNER_EXE)
		list(APPEND OPTS ${RUNNER_ARGS})
		#MESSAGE ("========== ${RUNNER} => ${RUNNER_EXE}  = ${OPTS}")
		#exit()
		add_test(NAME ${TEST_NAME} COMMAND ${RUNNER_EXE} $<TARGET_FILE:${TEST_NAME}> ${OPTS} )
	else()
		MESSAGE("WARNING: CONFIGURE_TEST_NMC SKIPPED DUE NMC_TOOLCHAIN IS ${NMC_TOOLCHAIN}")
	endif()
endfunction()

function(CONFIGURE_TEST_X64 IN_TEST_DIR BOARD CORE )	
	#set(ARCH NM6407)
	if (NOT NMC_TOOLCHAIN)
		get_filename_component(STEP_NAME ${IN_TEST_DIR} NAME)
		
		set(TEST_NAME example-${BOARD}${CORE}-${STEP_NAME})
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
		exit()
	endif()
endfunction()





#set(steps_risc steps_risc/step01 steps_risc/step02 steps_risc/step03 steps_risc/step03a steps_risc/step04 steps_risc/step04a) 
#set(stepis_fixed steps_fixed/stepi05 steps_fixed/stepi06 steps_fixed/stepi06a steps_fixed/stepi06b steps_fixed/stepi07 steps_fixed/stepi08 steps_fixed/stepi09 steps_fixed/stepi10 steps_fixed/stepi11 steps_fixed/stepi12 steps_fixed/stepi13 steps_fixed/stepi13a steps_fixed/stepi14) 
#set(steps_float steps-float/stepf01 steps-float/stepf02 steps-float/stepf02a steps-float/stepf02b) 

#${CMAKE_CURRENT_SOURCE_DIR} 

file(GLOB 	 examples_risc  RELATIVE ${CMAKE_CURRENT_LIST_DIR} risc/*  )
file(GLOB 	 examples_fixed RELATIVE ${CMAKE_CURRENT_LIST_DIR} fixed/nmpps/* )
file(GLOB 	 examples_float RELATIVE ${CMAKE_CURRENT_LIST_DIR} float/nmblas/* float/fft/* )

#MESSAGE (=========== ${examples_fixed})

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
	set(ARCH nm6406)
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_fixed} )
	set(CXXFLAGS  " -O2 -Wall -mnmc3 -g")
	set(CXXFLAGSD " -O0 -Wall -mnmc3 -g")
	set(LDS 	"${BOARD}.lds")
	set(LIBS  	"-lnmpp-nm6406 -Wl,--whole-archive -lmc5103lib -Wl,--no-whole-archive")
	set(LIBSD 	"-lnmpp-nm6406 -Wl,--whole-archive -lmc5103lib -Wl,--no-whole-archive")
	set(RUNNER "${BOARD}run")
	set(RUNOPT  " ")
	set(RUNOPTD " ")
	foreach(dir ${dir_list})
		#CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
    endforeach()
endif()	


if ( MB7707_BUILD)
	set(BOARD mb7707)
	set(ARCH nm6406)
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_fixed} )
	set(CXXFLAGS  " -O2 -Wall -mnmc3 -g")
	set(CXXFLAGSD " -O0 -Wall -mnmc3 -g")
	set(LIBS  	"-lnmpp-nm6406 -Wl,--whole-archive -lmb7707lib -Wl,--no-whole-archive")
	set(LIBSD 	"-lnmpp-nm6406 -Wl,--whole-archive -lmb7707lib -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}.lds")
	set(RUNNER  "${BOARD}run")
	set(RUNOPT  "-a${MAC} ")
	set(RUNOPTD "-a${MAC} ")
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
    endforeach()
endif()	


if (MC12101_BUILD)
	MESSAGE("====================== MC12101_BUILD ======================")
	set(BOARD mc12101)
	#if (ARCH STREQUAL nm6407f)
	set (ARCH nm6407f)
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_float} )
	set(CXXFLAGS  " -O2 -Wall -mnmc4-float -g")
	set(CXXFLAGSD " -O0 -Wall -mnmc4-float -g")
	set(LIBS  	" -lnmpp-nm6407f -lnm6407int -Wl,--whole-archive -lnm6407_io_nmc -lmc12101load_nm -Wl,--no-whole-archive")
	set(LIBSD 	" -lnmpp-nm6407f -Wl,--whole-archive -lnm6407_io_nmc -lmc12101_stub_nmc4_float -lmc12101load_nm -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}-nmpu0.lds")
	if (DEFINED MC12101_RUNNER)
		set(RUNNER  "${MC12101_RUNNER}")
	else()
		set(RUNNER  "${BOARD}run")
	endif()
	set(RUNOPT	"-p -R -a0 -v" )
	set(RUNOPTD "-p -R -a0 -v" )
	set(MONITOR "nm_gdb_monitor_mc12101")
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "-nmpu0" )
	endforeach()



	if ( QEMU_BUILD )
		set(BOARD qemu)
		MESSAGE("====================== MC12101_BUILD/QEMU_BUILD ======================")
		#set(CXXFLAGS  " -O2 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
		set(LIBS  	"-lnmpp-${ARCH} -lc")
		set(LIBSD 	"-lnmpp-${ARCH} -lc")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUNOPT 	" ")
		set(RUNOPTD " ")
		set(MONITOR "")
		foreach(dir ${dir_list})
			CONFIGURE_EXAMPLE (${dir} ${BOARD}-f "")
			CONFIGURE_TEST_NMC(${dir} qemu-f "")
		endforeach()
	endif()
	
	#endif()
	
	#if (ARCH STREQUAL nm6407i)
	set(ARCH nm6407i)	
	set(BOARD mc12101)
	
	
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_fixed} )
	set(CXXFLAGS  " -O2 -Wall -mnmc4-fixed -g")
	set(CXXFLAGSD " -O0 -Wall -mnmc4-fixed -g")
	set(LIBS  	" -lnmpp-nm6407i -lnm6407int -Wl,--whole-archive -lnm6407_io_nmc -lmc12101load_nm -Wl,--no-whole-archive")
	set(LIBSD 	" -lnmpp-nm6407i -Wl,--whole-archive -lnm6407_io_nmc -lmc12101_stub_nmc4_fixed -lmc12101load_nm -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}-nmpu1.lds")
	if (DEFINED MC12101_RUNNER)
		set(RUNNER  "${MC12101_RUNNER}")
	else()
		set(RUNNER  "${BOARD}run")
	endif()
	set(RUNOPT  "-p -R -a1 -v" )
	set(RUNOPTD "-p -R -a1 -v" )
	set(MONITOR "nm_gdb_monitor_mc12101")
	
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "-nmpu1")
	endforeach()
	#endif()
	
	if ( QEMU_BUILD )
		set(BOARD qemu)
		MESSAGE("##############")
		#set(CXXFLAGS  " -O2 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
		set(LIBS  	"-lnmpp-${ARCH} -lc")
		set(LIBSD 	"-lnmpp-${ARCH} -lc")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUNOPT 	" ")
		set(RUNOPTD " ")
		set(MONITOR "")
		foreach(dir ${dir_list})
			CONFIGURE_EXAMPLE (${dir} ${BOARD}-i "")
			CONFIGURE_TEST_NMC(${dir} qemu-i "")
		endforeach()
	endif()
endif()	

if (MC11101_BUILD)
	set(BOARD mc11101)
	set(ARCH  nm6476f)
	SET_NMC_ARCH(${ARCH})
	
	set(dir_list ${examples_risc} ${examples_float} )
	set(CXXFLAGS  " -O2 -Wall -mnmc4-float -g")
	set(CXXFLAGSD " -O0 -Wall -mnmc4-float -g")
	set(LIBS  	" -lnmpp-nm6476f -lnm6476int -Wl,--whole-archive -lnm6407_io_nmc -lmc11101load_nm -Wl,--no-whole-archive")
	set(LIBSD 	" -lnmpp-nm6476f -lnm6476int -Wl,--whole-archive -lnm6407_io_nmc -lmc11101load_nm -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}.lds")
	set(RUNNER  "${BOARD}run")
	set(RUNOPT	"-p -R -v" )
	set(RUNOPTD "-p -R -v" )
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "" )
		
		#MESSAGE("UPS")
		#return()
	endforeach()	
	
	if ( QEMU_BUILD )
		set(BOARD qemu)
		MESSAGE("##############")
		set(LIBS  	"-lnmpp-${ARCH} -lc")
		set(LIBSD 	"-lnmpp-${ARCH} -lc")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUNOPT 	" ")
		set(RUNOPTD " ")
		set(MONITOR "")
		foreach(dir ${dir_list})
			CONFIGURE_EXAMPLE (${dir} qemu "")
			CONFIGURE_TEST_NMC(${dir} qemu "")
		endforeach()
	endif()
	
endif()
	
if (MC11102_BUILD)	
	set(BOARD mc11102)
	set(ARCH nm6476i)
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_fixed} )
	set(CXXFLAGS  " -O2 -Wall -mnmc4-fixed -g")
	set(CXXFLAGSD " -O0 -Wall -mnmc4-fixed -g")
	set(LIBS  	" -lnmpp-nm6476i -lnm6476int -Wl,--whole-archive -lnm6407_io_nmc -lmc11101load_nm -Wl,--no-whole-archive")
	set(LIBSD 	" -lnmpp-nm6476i -lnm6476int -Wl,--whole-archive -lnm6407_io_nmc -lmc11101load_nm -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}.lds")
	set(RUNNER "${BOARD}run")
	set(RUNOPT  "-p -R -v" )
	set(RUNOPTD "-p -R -v" )
	set(MONITOR "nmc-monitor")
	
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
	endforeach()
	
	
	if ( QEMU_BUILD )
		set(BOARD qemu)
		MESSAGE("##############")
		set(LIBS  	"-lnmpp-${ARCH} -lc")
		set(LIBSD 	"-lnmpp-${ARCH} -lc")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUNOPT 	" ")
		set(RUNOPTD "-g $(P)")
		set(MONITOR "")
		foreach(dir ${dir_list})
			CONFIGURE_EXAMPLE (${dir} qemu "")
			CONFIGURE_TEST_NMC(${dir} qemu "")
		endforeach()
	endif()
endif()	



if (MC12705_BUILD)
	MESSAGE("====================== MC12705_BUILD ======================")
	set(BOARD "mc12705")
	set(ARCH nm6408)
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_float} )
	set(CXXFLAGS  " -O2 -Wall -mnmc4-float -g")
	set(CXXFLAGSD " -O0 -Wall -mnmc4-float -g")
	set(LIBS  	"-lnmpp-nm6408 -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -Wl,--no-whole-archive")
	set(LIBSD 	"-lnmpp-nm6408 -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -lnm6408_stub -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}.lds")
	set(RUNNER  "${BOARD}run")
	set(RUNOPT 	"-c0 -n0 -v -p")
	set(RUNOPTD "-c0 -n0 -v -p")
	set(MONITOR "nmc-monitor")
	
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
    endforeach()
	
	if ( QEMU_BUILD )
		set(BOARD qemu)
		MESSAGE("##############")
		set(dir_list ${examples_risc} ${examples_float} )
		set(CXXFLAGS  " -O2 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
		set(LIBS  	"-lnmpp-${ARCH} -lc")
		set(LIBSD 	"-lnmpp-${ARCH} -lc")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUNOPT 	" ")
		set(RUNOPTD "-g $(P)")
		set(MONITOR "")
		foreach(dir ${dir_list})
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
			CONFIGURE_TEST_NMC(${dir} qemu "")
		endforeach()
	endif()	

endif()	

if (NM_CARD_BUILD)
	set(BOARD "nm_card")
	set(ARCH nm6408)
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_float} )
	set(CXXFLAGS  " -O2 -Wall -mnmc4-float -g -include nmc_printf.h")
	set(CXXFLAGSD " -O0 -Wall -mnmc4-float -g -include nmc_printf.h")
	set(LIBS  	"-lnmpp-nm6408 -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -Wl,--no-whole-archive")
	set(LIBSD 	"-lnmpp-nm6408 -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -lnm6408_stub -Wl,--no-whole-archive")
	set(LDS 	"${BOARD}.lds")
	set(RUNNER  "${BOARD}_run")
	set(RUNOPT 	"-c0 -n0 -v -p")
	set(RUNOPTD "-c0 -n0 -v -p")
	set(MONITOR "nm_gdb_monitor_nm_card")
	
	foreach(dir ${dir_list})
		CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
    endforeach()
	
	if ( QEMU_BUILD )
		set(BOARD qemu)
		set(dir_list ${examples_risc} ${examples_float} )
		set(CXXFLAGS  " -O2 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
		set(CXXFLAGSD " -O0 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
		
		set(LIBS  	"-lnmpp-${ARCH} -lc")
		set(LIBSD 	"-lnmpp-${ARCH} -lc")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUNOPT 	" ")
		set(RUNOPTD "-g $(P)")
		set(MONITOR "")
		foreach(dir ${dir_list})
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
			CONFIGURE_TEST_NMC(${dir} qemu "")
		endforeach()
	endif()	
	
endif()	




if ( X64_BUILD )
	set(BOARD x64)
	MESSAGE("######## x64 ######")
	
	set(dir_list ${examples_risc} ${examples_fixed} ${examples_float})
	#set(CXXFLAGS  " -O2 -Wall -mnmc4 -g -I$(NMPP)/include -L$(NMPP)/lib")
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
	set (ROOT "\$ENV\{NMPP\}")
	configure_file ("./templates/CMakeLists.txt.in"  "examples-x64/CMakeLists.txt" @ONLY )
	configure_file ("./templates/configure_vs17.bat" "examples-x64/configure_vs17.bat" @ONLY )
	
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
