cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

include(${CMAKE_CURRENT_LIST_DIR}/../../cmake-variables.cmake)
   
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

if(BOARD STREQUAL "MC12101")
GENERATE_TESTS_MC12101("${listdir_fixed}" mc12101_fixed ${CMAKE_CURRENT_LIST_DIR}/mc12101-nmpu1.lds 1 nmpp-nmc4 )
GENERATE_TESTS_MC12101("${listdir_float}" mc12101_float ${CMAKE_CURRENT_LIST_DIR}/mc12101-nmpu0.lds 0 nmpp-nmc4f )
endif()

if(BOARD STREQUAL "MC11101")
GENERATE_TESTS_MC11101("${listdir}" mc11101_float ${CMAKE_CURRENT_LIST_DIR}/mc11101_flt.lds 0 nmpp-nmc4f )
endif()

if(BOARD STREQUAL "NM_CARD")
GENERATE_TESTS_NM_CARD("${listdir}" nm_card_float ${CMAKE_CURRENT_LIST_DIR}/nm_card.lds 0 0 nmpp-nmc4f )
endif()

#GENERATE_TESTS(${CMAKE_CURRENT_LIST_DIR}/level2 level2 ${CMAKE_CURRENT_LIST_DIR}/mc12101-nmpu0.lds 0 nmpp-nmc4f )




