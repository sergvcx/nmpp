include("build_x64/CPackConfig.cmake")


set(CPACK_INSTALL_CMAKE_PROJECTS
    "build_x64;nmpp;ALL;/"
    "build_nmc_debug;nmpp;ALL;/"
    "build_nmc_release;nmpp;ALL;/"
    )
    