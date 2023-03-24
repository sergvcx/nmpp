cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/cmake-variables.cmake)
   
   
   	option(MC12101_BUILD "Build tests for mc12101" OFF)
	option(MB7707_BUILD  "Build tests for mb7707" OFF)
	option(MC5103_BUILD  "Build tests for mc5103" OFF)
	option(MC7601_BUILD  "Build tests for mc7601" OFF)
	option(MC12705_BUILD "Build tests for mc12705" OFF)
	option(NM_CARD_BUILD "Build tests for nm_card" OFF)
	option(QEMU_BUILD    "Build tests for qemu" OFF)
	option(X64_BUILD     "Build tests for x64" OFF)
	
	option(NMC_TOOLCHAIN "Used NMC Toolchin" ON)

#if (NMC_TOOLCHAIN)
if (NOT X64_BUILD)
#if (MC12101_BUILD OR MB7707_BUILD OR MC5103_BUILD OR MC7601_BUILD OR MC12705_BUILD OR NM_CARD_BUILD OR QEMU_BUILD)
	set(CMAKE_TOOLCHAIN_FILE "../../cmake/nmc-gcc-compile.cmake")
	#set(NMC_TOOLCHAIN ON)
	project(nmpp-tests VERSION 0.1.0 LANGUAGES CXX C ASM)
	MESSAGE("########## NMC BUILD ########### with ${CMAKE_TOOLCHAIN_FILE}")
else()
	#set(NMC_TOOLCHAIN OFF)
	project(nmpp-tests VERSION 0.1.0 LANGUAGES CXX C)
endif()



enable_testing()

#SUBDIRLIST(listdir0 ${CMAKE_CURRENT_LIST_DIR}/float/arithmetic)
#SUBDIRLIST(listdir1 ${CMAKE_CURRENT_LIST_DIR}/float/conditional)
#SUBDIRLIST(listdir2 ${CMAKE_CURRENT_LIST_DIR}/float/matrix)
SUBDIRLIST(listdir3 ${CMAKE_CURRENT_LIST_DIR}/float/nmblas/level1)
SUBDIRLIST(listdir4 ${CMAKE_CURRENT_LIST_DIR}/float/nmblas/level2)
#SUBDIRLIST(listdir5 ${CMAKE_CURRENT_LIST_DIR}/float/transform/fft)
#SUBDIRLIST(listdir6 ${CMAKE_CURRENT_LIST_DIR}/float/transform/init)

LIST(APPEND listdir_float ${listdir0} ${listdir1} ${listdir2} ${listdir3} ${listdir4} ${listdir5} ${listdir6})
LIST(REMOVE_ITEM listdir_float ${CMAKE_CURRENT_LIST_DIR}/arithmetic/nmppsMulC_Add_32fcr)



SUB2DIRLIST(listdir0 ${CMAKE_CURRENT_LIST_DIR}/fixed/matrix)
SUB2DIRLIST(listdir1 ${CMAKE_CURRENT_LIST_DIR}/signal/Arithmetics)

LIST(APPEND listdir_fixed ${listdir0} ${listdir1})

REMOVE_DIRS_WITHOUT_MAIN_CPP(listdir_fixed)

MESSAGE("## listdir_fixed 1 =${listdir_fixed} ")
#return()



#MESSAGE("#########")
#MESSAGE(STATUS ${listdir})
#MESSAGE("#########")

#set(BOARD MC11101)
#set(BOARD MC12101)
#set(BOARD NM_CARD)

if(MC12101_BUILD)
	GENERATE_TESTS_MC12101("${listdir_fixed}" mc12101i ${CMAKE_CURRENT_LIST_DIR}/lds/mc12101-nmpu1.lds 1 nmpp-nm6407i )
	#GENERATE_TESTS_MC12101("${listdir_float}" mc12101f ${CMAKE_CURRENT_LIST_DIR}/lds/mc12101-nmpu0.lds 0 nmpp-nm6407f )
endif()

if(MC11101_BUILD)
	GENERATE_TESTS_MC11101("${listdir_float}" mc11101 ${CMAKE_CURRENT_LIST_DIR}/lds/mc11101.lds nmpp-nm6476f )
endif()

if(MC11102_BUILD)
	GENERATE_TESTS_MC11101("${listdir_fixed}" mc11102 ${CMAKE_CURRENT_LIST_DIR}/lds/mc11102.lds nmpp-nm6476i )
endif()

if(MC12705_BUILD)
	GENERATE_TESTS_MC12705("${listdir_float}" mc12705 ${CMAKE_CURRENT_LIST_DIR}/lds/mc12705.lds 0 0 nmpp-nm6408 )
endif()

if(NM_CARD_BUILD)
	GENERATE_TESTS_NM_CARD("${listdir_float}" nm_card ${CMAKE_CURRENT_LIST_DIR}/lds/nm_card.lds 0 0 nmpp-nm6408 )
endif()

if(X64_BUILD)
	GENERATE_TESTS_X64("${listdir_float}" x64 nmpp-x64)
endif()

#${listdir_float}

#GENERATE_TESTS(${CMAKE_CURRENT_LIST_DIR}/level2 level2 ${CMAKE_CURRENT_LIST_DIR}/mc12101-nmpu0.lds 0 nmpp-nmc4f )




