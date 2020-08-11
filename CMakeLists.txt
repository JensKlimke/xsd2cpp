cmake_minimum_required(VERSION 3.10)
project(parse_xsd)

# setup
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MACOSX_RPATH 1)

# setup for tinyxml2
set(BUILD_SHARED_LIBS OFF CACHE BOOL "disable shared" FORCE)
set(BUILD_STATIC_LIBS ON CACHE BOOL "enable static" FORCE)
set(BUILD_TESTING off CACHE BOOL "disable tests" FORCE)

# add tinyxml2 sources
add_subdirectory(lib/tinyxml2)

# add library sources
add_subdirectory(src/library)

# create executable
add_executable(xsd2cpp
        src/main.cpp
        )

# link tinyxml2
target_link_libraries(xsd2cpp PRIVATE
        xsd2cpp_lib
        tinyxml2
        )


