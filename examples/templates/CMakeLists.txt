cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

project(nmpp-examples-x64 VERSION 0.1.0 LANGUAGES CXX C ASM)


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



function(CONFIGURE_EXAMPLE IN_TEST_DIR)	
	
	get_filename_component(STEP_NAME ${IN_TEST_DIR} NAME)
	
	set(TEST_NAME test-${BOARD}${CORE}-${STEP_NAME})
	file(GLOB 	cpp_files RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.cpp)
	file(GLOB 	c_files   RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${IN_TEST_DIR}/*.c)
	
	list(APPEND SRC_LIST ${cpp_files})
	list(APPEND SRC_LIST ${c_files})
	list(LENGTH SRC_LIST SRC_COUNT)
	
	if (NOT SRC_COUNT  )
		return()
	endif()	
	
	add_executable(${TEST_NAME}  ${SRC_LIST})
	string(REPLACE " " ";" LIBS_LIST ${LIBS})
	target_link_directories   (${TEST_NAME} PUBLIC	@ROOT@/lib)
	target_link_libraries     (${TEST_NAME} ${LIBS_LIST})
	target_include_directories(${TEST_NAME} PUBLIC @ROOT@/include)
	set_target_properties(${TEST_NAME} PROPERTIES LINKER_LANGUAGE CXX)
	
endfunction()


file(GLOB 	 examples_risc  RELATIVE ${CMAKE_CURRENT_LIST_DIR} risc/*  )
file(GLOB 	 examples_fixed RELATIVE ${CMAKE_CURRENT_LIST_DIR} fixed/nmpps/* )
file(GLOB 	 examples_float RELATIVE ${CMAKE_CURRENT_LIST_DIR} float/nmblas/* float/fft/* )


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
	CONFIGURE_EXAMPLE(${dir})
endforeach()
	
