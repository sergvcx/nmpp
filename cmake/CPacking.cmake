include(CMakePackageConfigHelpers)
include(GNUInstallDirs)
include(${CMAKE_CURRENT_LIST_DIR}/utils.cmake)

configure_common_config()

set(CPACK_PACKAGE_NAME nmpp-${PACK_SUFFIX} CACHE STRING "Package Name")
  
  

#set(CPACK_PACKAGE_FILE_NAME  ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION})
  
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/..)
set(CPACK_NSIS_INSTALL_ROOT "C:\\\\Program Files\\\\Module")
set(CPACK_PACKAGE_VENDOR "RC Module")
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})

#set(boards "mc12101;mc7601;mc5103;mb7707")
#foreach(board ${boards})
#	string(TOUPPER ${board} BOARD)
if (CMAKE_HOST_WIN32)
		list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
		"${CMAKE_SOURCE_DIR}/build/build_x64_mingw;nmpp-x64;ALL;/"
		)
endif()
		
if (PACK_SUFFIX STREQUAL nm6407)
		list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
			"${CMAKE_SOURCE_DIR}/build/build_nm6407_debug;nmpp-nm6407;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6407_release;nmpp-nm6407;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_x64;nmpp-x64;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_x64_mingw;nmpp-x64;ALL;/"
			)
endif()

if (PACK_SUFFIX STREQUAL nm6476i)
		list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
			"${CMAKE_SOURCE_DIR}/build/build_nm6476i_debug;nmpp-nm6476i;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6476i_release;nmpp-nm6476i;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_x64;nmpp-x64;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_x64_mingw;nmpp-x64;ALL;/"
			)
endif()

if (PACK_SUFFIX STREQUAL nm6476f)
		list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
			"${CMAKE_SOURCE_DIR}/build/build_nm6476f_debug;nmpp-nm6476f;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6476f_release;nmpp-nm6476f;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_x64;nmpp-x64;ALL;/"
			"{CMAKE_SOURCE_DIR}./build/build_x64_mingw;nmpp-x64;ALL;/"
			)
endif()

if (PACK_SUFFIX STREQUAL nm6408)
		#message("NM6408 PCK")
		list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
			"${CMAKE_SOURCE_DIR}/build/build_nm6408_debug;nmpp-nm6408;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6408_release;nmpp-nm6408;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_x64;nmpp-x64;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_x64_mingw;nmpp-x64;ALL;/"
			)
endif()

if (PACK_SUFFIX STREQUAL nmc4)
		#message("NM6408 PCK")
		list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
			"${CMAKE_SOURCE_DIR}/build/build_nm6407f_debug;nmpp-nm6407f;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6407f_release;nmpp-nm6407f;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6407i_debug;nmpp-nm6407i;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6407i_release;nmpp-nm6407i;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6408_debug;nmpp-nm6408;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6408_release;nmpp-nm6408;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6476i_debug;nmpp-nm6476i;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6476i_release;nmpp-nm6476i;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6476f_debug;nmpp-nm6476f;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_nm6476f_release;nmpp-nm6476f;ALL;/"
			"${CMAKE_SOURCE_DIR}/build/build_x64;nmpp-x64;ALL;/"
		)

	
endif()



#endforeach()
message("${CPACK_INSTALL_CMAKE_PROJECTS}")

# list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
# 	"${CMAKE_CURRENT_LIST_DIR}/../build/${board}/virtual/release;hal-virtaul;ALL;/"
# 	)



include(CPack)