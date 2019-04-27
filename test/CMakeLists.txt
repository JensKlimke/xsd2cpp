cmake_minimum_required(VERSION 3.10)
project(odr)

set(CMAKE_CXX_STANDARD 14)

add_library(odr STATIC generated.h generated.cc lib/Attribute.h)
target_include_directories(odr PRIVATE lib)
target_link_libraries(odr tinyxml2)
set_target_properties(odr PROPERTIES LINKER_LANGUAGE CXX)

add_executable(parser main.cpp)
target_link_libraries(parser odr tinyxml2)
target_include_directories(parser PRIVATE lib)