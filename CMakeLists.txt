cmake_minimum_required(VERSION 3.10)
project(parse_xsd)

set(CMAKE_CXX_STANDARD 14)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/repo/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()


set(CMAKE_MACOSX_RPATH 1)
add_subdirectory(lib/tinyxml2)



add_executable(parse_xsd src/main.cpp src/functions.h)
target_link_libraries(parse_xsd tinyxml2)

install(TARGETS parse_xsd DESTINATION bin)



add_library(odr STATIC test/OpenDRIVE_1.5M.h test/OpenDRIVE_1.5M.cpp test/lib/Attribute.h)
target_include_directories(odr PRIVATE test/lib)
target_link_libraries(odr tinyxml2)
set_target_properties(odr PROPERTIES LINKER_LANGUAGE CXX)
