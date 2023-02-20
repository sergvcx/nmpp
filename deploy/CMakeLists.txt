cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

project(nmpp-deploy)

set(ROOT ${CMAKE_CURRENT_LIST_DIR}/..)

set(NM6407F_BINARY_DIR ${ROOT}/build_nm6407f CACHE STRING "Build dir of nm6407f")
set(NM6407I_BINARY_DIR ${ROOT}/build_nm6407i CACHE STRING "Build dir of nm6407i")
set(NM6408_BINARY_DIR  ${ROOT}/build_nm6408  CACHE STRING "Build dir of nm6408")
set(NM6476F_BINARY_DIR ${ROOT}/build_nm6476f CACHE STRING "Build dir of nm6476f")
set(NM6476I_BINARY_DIR ${ROOT}/build_nm6476i CACHE STRING "Build dir of nm6476i")
set(x64_BINARY_DIR ${ROOT}/build_x64 CACHE STRING "Build dir of x64")

include(${NM6407F_BINARY_DIR}/nmpp-nm6407f-targets.cmake)
include(${NM6407F_BINARY_DIR}/nmpp-nm6407i-targets.cmake)
include(${NM6407F_BINARY_DIR}/nmpp-nm6476f-targets.cmake)
include(${NM6407F_BINARY_DIR}/nmpp-nm6476i-targets.cmake)
include(${NM6407F_BINARY_DIR}/nmpp-nm6408-targets.cmake)
include(${NM6407F_BINARY_DIR}/nmpp-x64-targets.cmake)

install(FILES 
   	"$<TARGET_PROPERTY:nmpp-nm6407f,IMPORTED_LOCATION_RELEASE>"
   	COMPONENT nmpp-nm6407f-dev
    DESTINATION lib)
install(FILES 
   	"$<TARGET_PROPERTY:nmpp-nm6407i,IMPORTED_LOCATION_RELEASE>"
   	COMPONENT nmpp-nm6407i-dev
    DESTINATION lib)
install(FILES 
   	"$<TARGET_PROPERTY:nmpp-nm6476f,IMPORTED_LOCATION_RELEASE>"
   	COMPONENT nmpp-nm6476f-dev
    DESTINATION lib)
install(FILES 
   	"$<TARGET_PROPERTY:nmpp-nm6476i,IMPORTED_LOCATION_RELEASE>"
   	COMPONENT nmpp-nm6476i-dev
    DESTINATION lib)
install(FILES 
   	"$<TARGET_PROPERTY:nmpp-nm6408,IMPORTED_LOCATION_RELEASE>"
   	COMPONENT nmpp-nm6408-dev
    DESTINATION lib)
install(FILES 
   	"$<TARGET_PROPERTY:nmpp-nm6408,IMPORTED_LOCATION_RELEASE>"
   	COMPONENT nmpp-x64-dev
    DESTINATION lib)
install(DIRECTORY ${ROOT}/include 
    DESTINATION .)

include(Packing.cmake)