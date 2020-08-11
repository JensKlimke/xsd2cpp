# library files
set(SOURCE_FILES
        functions.h
        comment.h
        code_generator.h
        XSDParser.h
        DataType.h
        DataType.cpp)

# create library
add_library(xsd2cpp_lib ${SOURCE_FILES})