cmake_minimum_required(VERSION 3.10)
project(parse_xsd)

# setup
set(CMAKE_CXX_STANDARD 14)

# options
option(BUILD_TESTS "Sets or unsets the option to generate the test target" OFF)
option(BUILD_APP "Sets or unsets the option to generate the executable" ON)


# unix install dir
include(GNUInstallDirs)

# add ./cmake to CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# setup for tinyxml2
set(BUILD_SHARED_LIBS OFF CACHE BOOL "disable shared" FORCE)
set(BUILD_STATIC_LIBS ON CACHE BOOL "enable static" FORCE)
set(BUILD_TESTING off CACHE BOOL "disable tests" FORCE)

# add tinyxml2 sources
add_subdirectory(lib/tinyxml2)


# add xsd2cpp_lib sources
add_subdirectory(src/xsd2cpp_lib)

# add app
if (BUILD_APP)
    add_subdirectory(src/app)
endif ()

# add test
if (BUILD_TESTS)

    # load module for testing
    include(ModuleGtest)

    # add test directory
    add_subdirectory(test)

endif ()



