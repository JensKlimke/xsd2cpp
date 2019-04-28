cmake_minimum_required(VERSION 3.10)
project(parse_xsd)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_MACOSX_RPATH 1)


set(BUILD_SHARED_LIBS OFF CACHE BOOL "disable shared" FORCE)
set(BUILD_STATIC_LIBS ON CACHE BOOL "enable static" FORCE)
set(BUILD_TESTS OFF CACHE BOOL "disable tests" FORCE)
add_subdirectory(lib/tinyxml2)

add_executable(parse_xsd src/main.cpp src/functions.h src/XSDParser.h src/DataType.h)
target_link_libraries(parse_xsd tinyxml2)


