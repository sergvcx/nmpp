
#execute_process(COMMAND ${ROOT}/script.bat)

function(configure_common_config)
	set(config_dst ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/../lib/cmake/nmpp)
	set(INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
	#configure_package_config_file(${CMAKE_CURRENT_FUNCTION_LIST_DIR}/nmpp-config.cmake.in 
	#			${config_dst}/nmpp-config.cmake
	#			INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/nmpp
	#			PATH_VARS INSTALL_LIBDIR)
	#write_basic_package_version_file(
	#			${config_dst}/nmpp-config-version.cmake
	#			VERSION "${PROJECT_VERSION}"
	#			COMPATIBILITY SameMajorVersion)
	#install(FILES
	#			"${config_dst}/nmpp-config.cmake"
	#			"${config_dst}/nmpp-config-version.cmake"
	#			COMPONENT nmpp-dev
	#			DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/nmpp")
endfunction()

macro(add_nm_build_target board nm_generator)

	set(destination_binary_dir ${CMAKE_CURRENT_BINARY_DIR}/nmpp_${board})
	execute_process(
		COMMAND ${CMAKE_COMMAND} 
		-B ${destination_binary_dir} 
		${CMAKE_CURRENT_LIST_DIR}/target/${board}
		-G ${nm_generator}
		COMMENT "Building nm part for ${board}")

	if(WIN32)
		add_custom_target(nmpp_${board}_build ALL $ENV{NMC_GCC_TOOLPATH}/nmc4cmd.bat
			COMMAND ${CMAKE_COMMAND} --build ${destination_binary_dir} )
	else()
		add_custom_target(nmpp_${board}_build ALL COMMAND ${CMAKE_COMMAND} --build ${destination_binary_dir} )
	endif()
	add_custom_target(nmpp_${board}_clean COMMAND ${CMAKE_COMMAND} --build ${destination_binary_dir} --target clean)
	include(${destination_binary_dir}/nmpp_${board}-targets.cmake)
	include(${CMAKE_CURRENT_LIST_DIR}/target/${board}/${board}-sources.cmake)
	target_sources(nmpp_${board}_build PRIVATE ${${board}_sources})

	install(FILES 
    	"$<TARGET_PROPERTY:nmpp::nmpp_${board},IMPORTED_LOCATION_NOCONFIG>"
    	COMPONENT nmpp_${board}-dev
	    DESTINATION lib)
	install(FILES
		"${destination_binary_dir}/nmpp_${board}-targets.cmake"
	    "${destination_binary_dir}/nmpp_${board}-config.cmake"
	    "${destination_binary_dir}/nmpp_${board}-config-version.cmake"
	    COMPONENT nmpp_${board}-dev
	    DESTINATION "lib/cmake/nmpp_${board}")
endmacro()


macro(install_board_rules board config_template)
	string(TOUPPER ${board} BOARD)
	if(nmpp_${BOARD}_INSTALL AND NOT CMAKE_SKIP_INSTALL_RULES)
		configure_package_config_file(${config_template} nmpp_${board}-config.cmake
	    	INSTALL_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
		write_basic_package_version_file(nmpp_${board}-config-version.cmake
	    	COMPATIBILITY SameMajorVersion)
	    install(TARGETS nmpp_${board} EXPORT nmpp_${board}_export
	    	ARCHIVE 
	    		COMPONENT nmpp_${board}-dev
	    		DESTINATION lib
	    	PUBLIC_HEADER 
	    		COMPONENT nmpp_${board}-dev
		        DESTINATION include)
	    install(EXPORT nmpp_${board}_export
	    	COMPONENT nmpp_${board}-dev
	    	FILE nmpp_${board}-targets.cmake
	    	DESTINATION lib/cmake/nmpp_${board}
	    	NAMESPACE nmpp::)
		export(TARGETS nmpp_${board}
			FILE ${CMAKE_CURRENT_BINARY_DIR}/nmpp_${board}-targets.cmake
			NAMESPACE nmpp::)
		install(FILES
		    "${CMAKE_CURRENT_BINARY_DIR}/nmpp_${board}-config.cmake"
		    "${CMAKE_CURRENT_BINARY_DIR}/nmpp_${board}-config-version.cmake"
		    COMPONENT nmpp_${board}-dev
		    DESTINATION "lib/cmake/nmpp_${board}")
	endif()
	unset(BOARD)
endmacro()

macro(add_nmc_compiler_type_option sources)
	foreach(file ${sources})
		get_filename_component(extension ${file} EXT)
		if(extension STREQUAL .asm)
			list(APPEND asm_files ${file})
		elseif(extension STREQUAL .S)
			list(APPEND s_files ${file})
		elseif(extension STREQUAL .s)
			list(APPEND s_files ${file})
		endif()
	endforeach()

	set_source_files_properties( ${asm_files} PROPERTY COMPILE_FLAGS "-mmas" )
	set_source_files_properties( ${s_files}   PROPERTY COMPILE_FLAGS "-mgas" )
endmacro()
