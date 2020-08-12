# create executable
add_executable(xsd2cpp main.cpp)

# link tinyxml2
target_link_libraries(xsd2cpp PRIVATE
        xsd2cpp_lib
        tinyxml2
        )