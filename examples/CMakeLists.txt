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


set(CMAKE_CONFIGURATION_TYPES "Release;Debug")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_EXTENSIONS OFF)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)





function(CONFIGURE_EXAMPLE IN_TEST_DIR BOARD CORE )	

	get_filename_component(STEP_NAME ${IN_TEST_DIR} NAME)
	file(GLOB 	s_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR}/${IN_TEST_DIR}/BOARD ${IN_TEST_DIR}/*.S)
	file(GLOB 	cpp_files RELATIVE ${CMAKE_CURRENT_LIST_DIR}/${IN_TEST_DIR}/BOARD ${IN_TEST_DIR}/*.cpp)
	file(GLOB 	c_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR}/${IN_TEST_DIR}/BOARD ${IN_TEST_DIR}/*.c)
	
	list(APPEND SRC_LIST ${s_files})
	list(APPEND SRC_LIST ${cpp_files})
	list(APPEND SRC_LIST ${c_files})
	
	list(LENGTH SRC_LIST SRC_COUNT)
	if (NOT SRC_COUNT  )
		return()
	endif()	
	
	list(JOIN SRC_LIST " " SRC_FILES) # SRC_FILES is @ argument for .in
	
	set(OUT_TEST_DIR examples/${IN_TEST_DIR})
	
	# getting abs path of example and then relative path from example to root
	get_filename_component(ABS_IN_TEST_DIR ${IN_TEST_DIR}  REALPATH BASE_DIR "${CMAKE_CURRENT_LIST_DIR}")
	file(RELATIVE_PATH NMPP "${ABS_IN_TEST_DIR}/${BOARD}" "${CMAKE_SOURCE_DIR}")
	set(ENVS "NMPP ?= ${NMPP}")
	
	#string(REPLACE " " ";" LIBS_LIST ${LIBS})
	
	file(COPY ${IN_TEST_DIR} DESTINATION ${OUT_TEST_DIR}/..) # copy main.cpp & co
	
        MESSAGE("### CONFIGURE_EXAMPLE :${OUT_TEST_DIR} ")
	
	configure_file ("./templates/.vscode/launch.json"  "${OUT_TEST_DIR}/.vscode/launch.json" @ONLY )
	configure_file ("./templates/.vscode/tasks.json"   "${OUT_TEST_DIR}/.vscode/tasks.json" @ONLY )


        set(example_sources
            ${OUT_TEST_DIR}/.vscode/launch.json
            ${OUT_TEST_DIR}/.vscode/tasks.json)

		
	if (NOT BOARD STREQUAL "x64")
		#string(TOUPPER ${BOARD} BSP) 	# BSP is @ argument for .in
		set(TARGET test)				# TARGET is @ argument for .in
	
		configure_file ("./templates/Makefile.in"  				"${OUT_TEST_DIR}/${BOARD}/Makefile" )
		configure_file ("./templates/${LDS}" 					"${OUT_TEST_DIR}/${BOARD}/${LDS}" )
		
		#if (CMAKE_HOST_WIN32)
		#	configure_file ("./templates/build.bat.in" 			"${OUT_TEST_DIR}/build.bat" )
		#	configure_file ("./templates/run.bat.in"   			"${OUT_TEST_DIR}/run.bat" )
		#else()
		#	configure_file ("./templates/build.sh.in"  			"${OUT_TEST_DIR}/build.sh" )
		#	configure_file ("./templates/run.sh.in"   			"${OUT_TEST_DIR}/run.sh" )
		#endif()
                list(APPEND example_sources ${OUT_TEST_DIR}/${BOARD}/Makefile ${OUT_TEST_DIR}/${BOARD}/${LDS})
	else()
		configure_file ("./templates/x64-gcc/Makefile.in"  		"${OUT_TEST_DIR}/x64-gcc/Makefile" )
                configure_file ("./templates/x64-cl/Makefile.in"  		"${OUT_TEST_DIR}/x64-cl/Makefile" )
                list(APPEND example_sources x64-gcc/Makefile x64-cl/Makefile)
        endif()

        cmake_path(GET OUT_TEST_DIR FILENAME EXAMPLE_NAME)
        add_custom_target(${BOARD}-${EXAMPLE_NAME}
            COMMAND make
            SOURCES ${example_sources}
            )
	
endfunction()
function(CONFIGURE_TEST_NMC IN_TEST_DIR BOARD CORE )
	if (NMC_TOOLCHAIN)

		get_filename_component(STEP_NAME ${IN_TEST_DIR} NAME)
		
		set(TEST_NAME cexamples-${BOARD}${CORE}-${STEP_NAME})
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
		
		#string(TOUPPER ${BOARD} BSP)
		
		add_executable(${TEST_NAME}  ${SRC_LIST})
		add_dependencies(${TEST_NAME} ${PROJECT}-${ARCH})
		string(REPLACE " " ";" LIBS_LIST ${LIBS})
		target_link_directories   (${TEST_NAME} PUBLIC	$ENV{${BSP}}/lib ../lib)
		target_link_libraries     (${TEST_NAME} ${LIBS_LIST})
		target_include_directories(${TEST_NAME} PUBLIC $ENV{BSP}/include ../include)
		
		set_target_properties(${TEST_NAME} PROPERTIES LINKER_LANGUAGE CXX)

		target_link_options   (${TEST_NAME} PUBLIC -T${CMAKE_CURRENT_SOURCE_DIR}/templates/${LDS}  ) # -v 
		target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:C,CXX>:-m${NMC_ARCH};-O2>)	
		target_compile_options(${TEST_NAME} PUBLIC $<$<COMPILE_LANGUAGE:ASM>:-m${NMC_ARCH};-Werror>)	

	
		#MESSAGE("RUNOPT=" ${RUNOPT})
		#string(REPLACE "-v" "" CRUNOPT ${RUNOPT})
		#string(REPLACE " " ";" OPTS ${CRUNOPT})
		#SPLIT_CMD_ARGS(${RUNNER} RUNNER_EXE RUNNER_ARGS)
		# split RUNNER into EXE ans ARGS
		#string(REPLACE " " ";" RUNNER_ARGS ${RUNNER})
		#list(POP_FRONT RUNNER_ARGS RUNNER_EXE)
		#list(APPEND OPTS ${RUNNER_ARGS})
		#MESSAGE ("========== ${RUNNER} => ${RUNNER_EXE}  = ${OPTS}")
		#exit()
		add_test(NAME ${TEST_NAME} COMMAND ${RUNNER_EXE} $<TARGET_FILE:${TEST_NAME}> ${OPTS} )
	else()
		MESSAGE("WARNING: CONFIGURE_TEST_NMC SKIPPED DUE NMC_TOOLCHAIN IS ${NMC_TOOLCHAIN}")
                message(FATAL_ERROR aaaaaaaa)
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






#set(EXTRA_TARGETS "")

if (ARCH STREQUAL nm6406)		
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_fixed} )
	
	if ( MC5103_BUILD )
		set(BOARD "mc5103")
		set(CXXFLAGS  " -O2 -Wall -mnmc3 -g")
		set(CXXFLAGSD " -O0 -Wall -mnmc3 -g")
		set(LDS 	"${BOARD}.lds")
		set(LIBS  	"-lnmpp-nm6406  -Wl,--whole-archive -lmc5103lib -Wl,--no-whole-archive")
		set(LIBSD 	"-lnmpp-nm6406d -Wl,--whole-archive -lmc5103lib -Wl,--no-whole-archive")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(RUNNER "${BOARD}run")
		set(RUNOPT  " ")
		set(RUNOPTD " ")
		foreach(dir ${dir_list})
			CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		endforeach()
	endif()	

	if ( MB7707_BUILD)
		set(BOARD mb7707)
		set(CXXFLAGS  " -O2 -Wall -mnmc3 -g")
		set(CXXFLAGSD " -O0 -Wall -mnmc3 -g")
		set(LIBS  	"-lnmpp-nm6406  -Wl,--whole-archive -lmb7707lib -Wl,--no-whole-archive")
		set(LIBSD 	"-lnmpp-nm6406d -Wl,--whole-archive -lmb7707lib -Wl,--no-whole-archive")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}.lds")
		set(RUNNER  "${BOARD}run")
		set(RUNOPT  "-a${MAC} ")
		set(RUNOPTD "-a${MAC} ")
		foreach(dir ${dir_list})
			CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		endforeach()
	endif()	
endif()		

if (ARCH STREQUAL nm6407f)
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_float} )
	set(BSP MC12101)
	if (MC12101_BUILD)
		MESSAGE("====================== MC12101_BUILD ======================")
		set(BOARD mc12101)
		set(CXXFLAGS  " -O2 -Wall -mnmc4-float -g")
		set(CXXFLAGSD " -O0 -Wall -mnmc4-float -g")
		set(LIBS  	" -lnmpp-nm6407f -lnm6407int -Wl,--whole-archive -lnm6407_io_nmc -lmc12101load_nm -Wl,--no-whole-archive")
		set(LIBSD 	" -lnmpp-nm6407fd 			 -Wl,--whole-archive -lnm6407_io_nmc -lmc12101_stub_nmc4_float -lmc12101load_nm -Wl,--no-whole-archive")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include -I$(NMPP)/libs/printx/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}f.lds")
		set(RUN		"run:  $(TARGET) \n\tmc12101run -p -R -a0 -v $(TARGET)" )
		set(RUND 	"rund: $(TARGETD)\n\tmc12101run -p -R -a0 -v $(TARGETD)" )
		set(MONITOR "monitor:\n\tmc12101_gdb_monitor 0 0 5555")
		set(GDB		"gdb:\n\tnmc-gdb -ex \"target remote :5555\" $(TARGETD)")
                message(STATUS ${dir_list})
		foreach(dir ${dir_list})
                        #CONFIGURE_TEST_NMC(${dir} ${BOARD}f "-nmpu0" )
			CONFIGURE_EXAMPLE (${dir} ${BOARD}f "")
		endforeach()
	endif()
	if ( QEMU_BUILD )
		set(BOARD qemu)
		MESSAGE("====================== MC12101_BUILD/QEMU_BUILD ======================")
		#set(CXXFLAGS  " -O2 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
		set(LIBS  	"-lnmpp-${ARCH}  -lc")
		set(LIBSD 	"-lnmpp-${ARCH}d -lc")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUN		"run:  $(TARGET) \n\tnmc-qemu -tick $(TARGET)" )
		set(RUND 	"rund: $(TARGETD)\n\tnmc-qemu -g 10000 $(TARGETD)" )
		set(MONITOR "")
		set(GDB		"gdb:\n\tnmc-gdb -iex \"set tcp connect-timeout 30\"  -ex \"target remote :10000\" $(TARGETD)")
		foreach(dir ${dir_list})
			#CONFIGURE_TEST_NMC(${dir} ${BOARD}-${ARCH} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD}-${ARCH} "")
		endforeach()
	endif()
endif()
	
if (ARCH STREQUAL nm6407i)
	SET_NMC_ARCH(${ARCH})
	set(BSP MC12101)
	set(dir_list ${examples_risc} ${examples_fixed} )
	if (MC12101_BUILD)
		set(BOARD mc12101)
		set(CXXFLAGS  " -O2 -Wall -mnmc4-fixed -g")
		set(CXXFLAGSD " -O0 -Wall -mnmc4-fixed -g")
		set(LIBS  	" -lnmpp-nm6407i  -lnm6407int -Wl,--whole-archive -lnm6407_io_nmc -lmc12101load_nm -Wl,--no-whole-archive")
		set(LIBSD 	" -lnmpp-nm6407id -Wl,--whole-archive -lnm6407_io_nmc -lmc12101_stub_nmc4_fixed -lmc12101load_nm -Wl,--no-whole-archive")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}i.lds")
		set(RUN		"run:  $(TARGET) \n\tmc12101run -p -R -a1 -v $(TARGET)" )
		set(RUND 	"rund: $(TARGETD)\n\tmc12101run -p -R -a1 -v $(TARGETD)" )
		set(MONITOR "monitor:\n\tmc12101_gdb_monitor 0 0 5556")
		set(GDB		"gdb:\n\tnmc-gdb -ex \"target remote :5556\" $(TARGETD)")
		foreach(dir ${dir_list})
			#CONFIGURE_TEST_NMC(${dir} ${BOARD}i "-nmpu1")
			CONFIGURE_EXAMPLE (${dir} ${BOARD}i "")
		endforeach()
	endif()
	
	if ( QEMU_BUILD )
		set(BOARD qemu)
		MESSAGE("##############")
		#set(CXXFLAGS  " -O2 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
		set(LIBS  	"-lnmpp-${ARCH}  -lc")
		set(LIBSD 	"-lnmpp-${ARCH}d -lc")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUN		"run:  $(TARGET) \n\tnmc-qemu -tick $(TARGET)" )
		set(RUND 	"rund: $(TARGETD)\n\tnmc-qemu -g 10000 $(TARGETD)" )
		set(MONITOR "")
		set(GDB		"gdb:\n\tnmc-gdb -iex \"set tcp connect-timeout 30\"  -ex \"target remote :10000\" $(TARGETD)")
		foreach(dir ${dir_list})
			#CONFIGURE_TEST_NMC(${dir} ${BOARD}-${ARCH} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD}-${ARCH} "")
		endforeach()
	endif()
endif()	

if (ARCH STREQUAL nm6476f)	
	SET_NMC_ARCH(${ARCH})
	set(BSP   MC11101)
	if (MC11101_BUILD)
		set(BOARD mc11101)
		set(dir_list ${examples_risc} ${examples_float} )
		set(CXXFLAGS  " -O2 -Wall -mnmc4-float -g")
		set(CXXFLAGSD " -O0 -Wall -mnmc4-float -g")
		set(LIBS  	" -lnmpp-nm6476f  -lnm6476int -Wl,--whole-archive -lnm6407_io_nmc -lmc11101load_nm -Wl,--no-whole-archive")
		set(LIBSD 	" -lnmpp-nm6476fd -lnm6476int -Wl,--whole-archive -lnm6407_io_nmc -lmc11101load_nm -Wl,--no-whole-archive")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}.lds")
		set(RUN		"run:  $(TARGET) \n\tmc11101run -p -R -v $(TARGET)" )
		set(RUND 	"rund: $(TARGETD)\n\tmc11101run -p -R -v $(TARGETD)" )
		foreach(dir ${dir_list})
			CONFIGURE_TEST_NMC(${dir} ${BOARD} "" )
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		endforeach()	
	endif()
	if ( QEMU_BUILD )
		set(BOARD qemu)
		set(LIBS  	"-lnmpp-${ARCH}  -lc")
		set(LIBSD 	"-lnmpp-${ARCH}d -lc")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUN		"run:  $(TARGET) \n\tnmc-qemu -tick $(TARGET)" )
		set(RUND 	"rund: $(TARGETD)\n\tnmc-qemu -g 10000 $(TARGETD)" )
		set(MONITOR "")
		foreach(dir ${dir_list})
			#CONFIGURE_TEST_NMC(${dir} ${BOARD}-${ARCH} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD}-${ARCH} "")
		endforeach()
	endif()
endif()	

if (ARCH STREQUAL nm6476i)	
	SET_NMC_ARCH(${ARCH})
	set(BSP   MC11101)
	if (MC11102_BUILD)	
		set(BOARD mc11102)
		set(dir_list ${examples_risc} ${examples_fixed} )
		set(CXXFLAGS  " -O2 -Wall -mnmc4-fixed -g")
		set(CXXFLAGSD " -O0 -Wall -mnmc4-fixed -g")
		set(LIBS  	" -lnmpp-nm6476i  -lnm6476int -Wl,--whole-archive -lnm6407_io_nmc -lmc11101load_nm -Wl,--no-whole-archive")
		set(LIBSD 	" -lnmpp-nm6476id -lnm6476int -Wl,--whole-archive -lnm6407_io_nmc -lmc11101load_nm -Wl,--no-whole-archive")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}.lds")
		set(RUN		"run:  $(TARGET) \n\tmc11102run -p -R -v $(TARGET)" )
		set(RUND 	"rund: $(TARGETD)\n\tmc11102run -p -R -v $(TARGETD)" )
		set(MONITOR "nmc-monitor")
		foreach(dir ${dir_list})
			#CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		endforeach()
	endif()		
	
	if ( QEMU_BUILD )
		set(BOARD qemu)
		MESSAGE("##############")
		set(LIBS  	"-lnmpp-${ARCH}  -lc")
		set(LIBSD 	"-lnmpp-${ARCH}d -lc")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUNNER 	"nmc-qemu")
		set(RUN		"run:  $(TARGET) \n\tnmc-qemu -tick $(TARGET)" )
		set(RUND 	"rund: $(TARGETD)\n\tnmc-qemu -g 10000 $(TARGETD)" )
		set(MONITOR "")
		foreach(dir ${dir_list})
			#CONFIGURE_TEST_NMC(${dir} ${BOARD}-${ARCH} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD}-${ARCH} "")
		endforeach()
	endif()
endif()	


if (ARCH STREQUAL nm6408)
	SET_NMC_ARCH(${ARCH})
	set(dir_list ${examples_risc} ${examples_float} )
	if (MC12705_BUILD)
		MESSAGE("====================== MC12705_BUILD ======================")
		set(BOARD "mc12705")
		set(BSP   MC12705)
		set(CXXFLAGS  " -O2 -Wall -mnmc4-float -g")
		set(CXXFLAGSD " -O0 -Wall -mnmc4-float -g")
		set(LIBS  	"-lnmpp-nm6408  -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -Wl,--no-whole-archive")
		set(LIBSD 	"-lnmpp-nm6408d -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -lnm6408_stub -Wl,--no-whole-archive")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}.lds")
		set(RUN 	"run: \n\tmc12705run -c0 -n0 -v $(TARGET)")
		set(RUND    "rund:\n\tmc12705run -c0 -n0 -v $(TARGETD)")
		set(MONITOR "nmc-monitor")
		foreach(dir ${dir_list})
			#CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		endforeach()
	endif()

	if (NM_CARD_BUILD)
		set(BOARD "nm_card")
		set(BSP   NM_CARD)
		set(CXXFLAGS  " -O2 -Wall -mnmc4-float -g -include nmc_printf.h")
		set(CXXFLAGSD " -O0 -Wall -mnmc4-float -g -include nmc_printf.h")
		set(LIBS  	"-lnmpp-nm6408  -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -Wl,--no-whole-archive")
		set(LIBSD 	"-lnmpp-nm6408d -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -lnm6408_stub -Wl,--no-whole-archive")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}.lds")
		set(RUN 	"run: \n\tnm_card_run -c0 -n0 -v $(TARGET)")
		set(RUND    "rund:\n\tnm_card_run -c0 -n0 -v $(TARGETD)")
		set(MONITOR "nm_gdb_monitor_nm_card")
		foreach(dir ${dir_list})
			#CONFIGURE_TEST_NMC(${dir} ${BOARD} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD} "")
		endforeach()
	endif()
	
	if ( QEMU_BUILD )
		set(BOARD qemu)
		set(BSP   NM_CARD)
		set(CXXFLAGS  " -O2 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
		set(CXXFLAGSD " -O0 -Wall -m${NMC_ARCH} -g -I$(NMPP)/include -L$(NMPP)/lib")
		set(LIBS  	"-lnmpp-${ARCH}  -lc")
		set(LIBSD 	"-lnmpp-${ARCH}d -lc")
		set(INC_DIRS " -I$(${BSP})/include -I$(NMPP)/include")
		set(LIB_DIRS " -L$(${BSP})/lib -L$(NMPP)/lib")
		set(LDS 	"${BOARD}-${ARCH}.lds")
		set(RUN		"run:  $(TARGET) \n\tnmc-qemu -tick $(TARGET)" )
		set(RUND 	"rund: $(TARGETD)\n\tnmc-qemu -g 10000 $(TARGETD)" )
		set(MONITOR "")
		foreach(dir ${dir_list})
			#CONFIGURE_TEST_NMC(${dir} ${BOARD}-${ARCH} "")
			CONFIGURE_EXAMPLE (${dir} ${BOARD}-${ARCH} "")
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
	set(INC_DIRS " -I$(NMPP)/include")
	set(LIB_DIRS " -L$(NMPP)/lib")
			
	#set(RUNNER  "${BOARD}run")
	#set(LDS 	"qemu.lds")
	#set(RUNNER 	"nmc-qemu")
	#set(RUNOPT 	" ")
	#set(RUNOPTD "-g 5555")
	#set(MONITOR "")
	foreach(dir ${dir_list})
		MESSAGE("EXAMPLE ######## x64 ###### ${dir}")
		CONFIGURE_TEST_X64(${dir} x64 "")
		CONFIGURE_EXAMPLE (${dir} x64 "")
    endforeach()
	
	#file(COPY ./templates/CMakeLists.txt DESTINATION examples-x64) # copy main.cpp & co
	set (ROOT "\$ENV\{NMPP\}")
	configure_file ("./templates/CMakeLists.txt.in"  "examples/CMakeLists.txt" @ONLY )
	configure_file ("./templates/configure_vs17.bat" "examples/configure_vs17.bat" @ONLY )
	configure_file ("./templates/configure_vs19.bat" "examples/configure_vs19.bat" @ONLY )
	
endif()	
	



#string(SUBSTRING ${ARCH} 2 4 NMC_CORE_VERSION )			 

#set_source_files_properties( ${nmc4f_asm_files} ${nmc4i_asm_files} ${nmc4r_asm_files}
#			 PROPERTY
#			 COMPILE_FLAGS " -mmas -Wa,-split_sir -Wa,-W-111"
#			 )
#
#set_source_files_properties( ${s_files} 
#			 PROPERTY
#			 COMPILE_FLAGS "-mgas -DNMC_CORE_VERSION=${NMC_CORE_VERSION}"
#			 )
	




#enable_testing()
#add_subdirectory(app/test)
					
#add_subdirectory(test/context)

#add_subdirectory(monitor)
#add_subdirectory(examples/2nmc-demo-gcc/make_mc12101)


macro (SPLIT_CMD_ARGS cmd_args cmd args)
	#message ("----------  ${cmd_args}------------")
	string(REPLACE " " ";" cmd_list ${cmd_args})
	#message ("----------  ${cmd_list}------------")
	list(POP_FRONT cmd_list ${cmd})
	#message ("----------  ${cmd_list}------------")
	string(JOIN " " ${args} ${cmd_list})
	#message ("----------  ${${cmd}}+ ${${args}}------------")
endmacro()
