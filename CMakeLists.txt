# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Set the project name
project(ARGB)

# Add all source files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Add the include directories
include_directories(src/Include src/Include/Driver)

# Set the optimization flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os")

# Create the shared library
add_library(ARGB_shared SHARED ${SOURCES})

# Create the static library
add_library(ARGB_static STATIC ${SOURCES})

# Set the output names for the libraries
set_target_properties(ARGB_shared PROPERTIES OUTPUT_NAME "ARGB")
set_target_properties(ARGB_static PROPERTIES OUTPUT_NAME "ARGB")

# Set the output directories for the libraries
set_target_properties(ARGB_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set_target_properties(ARGB_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Add strip step for all libraries
if (UNIX)
    add_custom_command(TARGET ARGB_shared POST_BUILD
        COMMAND strip $<TARGET_FILE:ARGB_shared>
        COMMENT "Stripping shared library"
    )
    add_custom_command(TARGET ARGB_static POST_BUILD
        COMMAND strip $<TARGET_FILE:ARGB_static>
        COMMENT "Stripping static library"
    )
endif()

