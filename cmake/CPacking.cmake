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
if (PACK_SUFFIX STREQUAL nm6407)
		list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
			"c:/git/nmpp/build/build_nm6407_debug;nmpp-nm6407;ALL;/"
			"c:/git/nmpp/build/build_nm6407_release;nmpp-nm6407;ALL;/"
			"c:/git/nmpp/build/build_x64;nmpp-x64;ALL;/"
			"c:/git/nmpp/build/build_x64_mingw;nmpp-x64;ALL;/"
			)
endif()

if (PACK_SUFFIX STREQUAL nm6408)
		list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
			"c:/git/nmpp/build/build_nm6408_debug;nmpp-nm6408;ALL;/"
			"c:/git/nmpp/build/build_nm6408_release;nmpp-nm6408;ALL;/"
			"c:/git/nmpp/build/build_x64;nmpp-x64;ALL;/"
			"c:/git/nmpp/build/build_x64_mingw;nmpp-x64;ALL;/"
			)
endif()
	
#endforeach()
message("${CPACK_INSTALL_CMAKE_PROJECTS}")

# list(APPEND CPACK_INSTALL_CMAKE_PROJECTS 
# 	"${CMAKE_CURRENT_LIST_DIR}/../build/${board}/virtual/release;hal-virtaul;ALL;/"
# 	)



include(CPack)