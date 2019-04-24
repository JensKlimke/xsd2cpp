cmake_minimum_required(VERSION 3.9)
project(parse_xsd)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_MACOSX_RPATH 1)
add_subdirectory(lib/tinyxml2)



add_executable(parse_xsd src/main.cpp src/functions.h)
target_link_libraries(parse_xsd tinyxml2)

install(TARGETS parse_xsd DESTINATION bin)



add_library(odr STATIC test/parser.cpp test/OpenDRIVE_1.5M.h test/lib/Attribute.h)
target_include_directories(odr PRIVATE test/lib)
target_link_libraries(odr tinyxml2)
set_target_properties(odr PROPERTIES LINKER_LANGUAGE CXX)
