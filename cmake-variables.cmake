
#set(ROOT ${CMAKE_CURRENT_LIST_DIR})

#set(NMPP 	${CMAKE_CURRENT_LIST_DIR}/nmpp)
#set(HAL 	${CMAKE_CURRENT_LIST_DIR}/hal)
set(MC12101 $ENV{MC12101})
set(MC11101 $ENV{MC11101})
set(NM_CARD $ENV{NM_CARD})

MACRO(REMOVE_DIRS_WITHOUT_MAIN_CPP dirlist )
  FOREACH(dir ${${dirlist}})
	#MESSAGE(STATUS "dir== ${dir}")
    IF(NOT EXISTS "${dir}/main.cpp")
	  LIST(REMOVE_ITEM ${dirlist} ${dir})
    ENDIF()
  ENDFOREACH()
ENDMACRO()

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  #MESSAGE(STATUS "${children}")
  #return()
  SET(dir_list "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dir_list ${curdir}/${child})
    ENDIF()
  ENDFOREACH()
  
  
  SET(${result} ${dir_list})
  
  #MESSAGE(STATUS "###########")
  #MESSAGE(STATUS "${dirlist}")
  #return()
  
ENDMACRO()

MACRO(SUB2DIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  #MESSAGE(STATUS "-----${children}-----------")
  #return()
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
	  #MESSAGE(STATUS "  ....${child}.......")
      LIST(APPEND dirlist ${curdir}/${child})
	  #MESSAGE(STATUS "  dirlist  === ${dirlist}")
	  SET(sub2list "")
	  SUBDIRLIST(sub2list ${curdir}/${child})
	  LIST(APPEND dirlist ${sub2list})
	  #MESSAGE(STATUS "  sub2list === ${sub2list}")
	  #MESSAGE(STATUS "  dirlist  === ${dirlist}")
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
  
  #MESSAGE(STATUS "###########")
  #MESSAGE(STATUS "==========${dirlist}======")
  #return()
ENDMACRO()




# macro(GET_FILES_FROM_DIR_LIST result dir_list cpp_flags c_flags mas_flags gas_flags)
# 	set(files "")
# 	foreach(dir ${dir_list})
# 		file(GLOB asm_files ${dir}/*.asm)
# 		file(GLOB cpp_files ${dir}/*.cpp)
# 		file(GLOB c_files ${dir}/*.c)
# 		file(GLOB s_files ${dir}/*.s)
# 		set_source_files_properties(${cpp_files} PROPERTIES COMPILE_OPTIONS "${cpp_flags}")
# 		set_source_files_properties(${c_files}   PROPERTIES COMPILE_OPTIONS "${c_flags}")
# 		set_source_files_properties(${asm_files} PROPERTIES COMPILE_OPTIONS "${mas_flags}")
# 		set_source_files_properties(${s_files}   PROPERTIES COMPILE_OPTIONS "${gas_flags}")
# 		list(APPEND files ${asm_files} ${cpp_files} ${s_files} ${c_files})
# 	endforeach()
# 	set(${result} ${files})
# endmacro()

# macro(SET_FILES_OPTIONS target src_files)
#   set(extra_args ${ARGN})
#   set_property(SOURCE ${src_files}
#  			 TARGET ${target}			 
# 			 PROPERTY
# 			 COMPILE_FLAGS "${extra_args}")
# endmacro()
# base_dir = app/test/float/nmblas/level1
function(GENERATE_TESTS_MC12101 dir_list  test_prefix ld_script board_core test_lib)
    set(extra_args "${ARGN}")	
    foreach(dir ${dir_list})
	
		get_filename_component(basename ${dir} NAME)
	    set(TEST_NAME ${test_prefix}_${basename}_${board_core}_test)
        
		MESSAGE(STATUS "###### ${TEST_NAME} #####")

  
		add_executable(${TEST_NAME} ${dir}/main.cpp)
        add_dependencies(${TEST_NAME} ${test_lib})
        target_link_directories(${TEST_NAME} PUBLIC
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/lib
            ${MC12101}/lib)
        target_link_libraries(${TEST_NAME} ${test_lib} ${extra_args})
        target_include_directories(${TEST_NAME} PUBLIC            
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/include
			${MC12101}/include
            )
		
        target_link_options(${TEST_NAME} PUBLIC
            -T${ld_script}
            -Wl,--whole-archive -lmc12101load_nm -lnm6407_io_nmc -Wl,--no-whole-archive)
        add_test(NAME ${TEST_NAME}
            COMMAND mc12101run $<TARGET_FILE:${TEST_NAME}> -a${board_core} -p -v)
    endforeach()
endfunction()

function(GENERATE_TESTS_MC11101 dir_list  test_prefix ld_script board_core test_lib)
    set(extra_args "${ARGN}")	
    foreach(dir ${dir_list})
	
		get_filename_component(basename ${dir} NAME)
	    set(TEST_NAME ${test_prefix}_${basename}_${board_core}_test)
        
		MESSAGE(STATUS "###### ${TEST_NAME} #####")
  
		add_executable(${TEST_NAME} ${dir}/main.cpp)
        add_dependencies(${TEST_NAME} ${test_lib})
        target_link_directories(${TEST_NAME} PUBLIC
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/lib
            ${MC11101}/lib
            ${MC12101}/lib
			)
        target_link_libraries(${TEST_NAME} ${test_lib} ${extra_args})
        target_include_directories(${TEST_NAME} PUBLIC            
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/include
			${MC11101}/include
            )
		
        target_link_options(${TEST_NAME} PUBLIC
            -T${ld_script}
            -Wl,--whole-archive -lmc11101load_nm -lnm6407_io_nmc -Wl,--no-whole-archive)
        add_test(NAME ${TEST_NAME}
            COMMAND mc11101run $<TARGET_FILE:${TEST_NAME}> -p -v)
    endforeach()
endfunction()


function(GENERATE_TESTS_NM_CARD dir_list  test_prefix ld_script cluster core test_lib)
    set(extra_args "${ARGN}")	
    foreach(dir ${dir_list})
	
		get_filename_component(basename ${dir} NAME)
	    set(TEST_NAME ${test_prefix}_${basename}_${board_core}_test)
        
		MESSAGE(STATUS "###### ${TEST_NAME} #####")

  
		add_executable(${TEST_NAME} ${dir}/main.cpp)
        add_dependencies(${TEST_NAME} ${test_lib})
        target_link_directories(${TEST_NAME} PUBLIC
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/lib
            ${NM_CARD}/lib
            ${MC12101}/lib
			)
        target_link_libraries(${TEST_NAME} ${test_lib} ${extra_args})
        target_include_directories(${TEST_NAME} PUBLIC            
            ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/include
			${NM_CARD}/include
            )
		target_compile_options(${TEST_NAME} PUBLIC -include nmc_printf.h)
        target_link_options(${TEST_NAME} PUBLIC
            -T${ld_script}
            -Wl,--whole-archive -lnm6408load_nmc -lnmc_io -Wl,--no-whole-archive)
        add_test(NAME ${TEST_NAME}
            COMMAND nm_card_run $<TARGET_FILE:${TEST_NAME}> -c${cluster} -n${core} -v -p)
			

    endforeach()
endfunction()



