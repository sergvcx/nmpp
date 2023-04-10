include("build_x64/CPackConfig.cmake")

MESSAGE("########### PACK_SUFFIX = ${PACK_SUFFIX}         ") 
MESSAGE("########### CPACK_PACK = ${CPACK_PACK_SUFFIX}         ") 


if (CPACK_PACK_SUFFIX STREQUAL nm6407)
	set(CPACK_INSTALL_CMAKE_PROJECTS
		"build_x64;nmpp;ALL;/"
		"build_${CPACK_PACK_SUFFIX}_debug;nmpp;ALL;/"
		"build_${CPACK_PACK_SUFFIX}_release;nmpp;ALL;/"
    )
#if (CPACK_PACK_SUFFIX STREQUAL nm6407)
#	set(CPACK_INSTALL_CMAKE_PROJECTS
#		"build_x64;nmpp;ALL;/"
#		"build_${CPACK_PACK_SUFFIX}i_debug;nmpp;ALL;/"
#		"build_${CPACK_PACK_SUFFIX}i_release;nmpp;ALL;/"
#		"build_${CPACK_PACK_SUFFIX}f_debug;nmpp;ALL;/"
#		"build_${CPACK_PACK_SUFFIX}f_release;nmpp;ALL;/"
#    )

#elseif (CPACK_PACK_SUFFIX STREQUAL nm6476)
#	set(CPACK_INSTALL_CMAKE_PROJECTS
#		"build_x64;nmpp;ALL;/"
#		"build_${CPACK_PACK_SUFFIX}i_debug;nmpp;ALL;/"
#		"build_${CPACK_PACK_SUFFIX}i_release;nmpp;ALL;/"
#		"build_${CPACK_PACK_SUFFIX}f_debug;nmpp;ALL;/"
#		"build_${CPACK_PACK_SUFFIX}f_release;nmpp;ALL;/"
#    )
else ()
	set(CPACK_INSTALL_CMAKE_PROJECTS
		"build_x64;nmpp;ALL;/"
		"build_${CPACK_PACK_SUFFIX}_debug;nmpp;ALL;/"
		"build_${CPACK_PACK_SUFFIX}_release;nmpp;ALL;/"
    )
endif()
	
MESSAGE("########### CPACK_INSTALL_CMAKE_PROJECTS = ${CPACK_INSTALL_CMAKE_PROJECTS}         ") 	
    
#
#	set(CPACK_INSTALL_CMAKE_PROJECTS
#		"build_x64;nmpp;ALL;/"
#		"build_nm6408_debug;nmpp;ALL;/"
#		"build_nm6408_release;nmpp;ALL;/"
#   )
#

	