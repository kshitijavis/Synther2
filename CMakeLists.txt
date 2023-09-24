cmake_minimum_required(VERSION 3.10)
project(synther VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

configure_file(synther.h.in synther.h)

# Libraries
add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(src)

target_include_directories(synther PUBLIC 
    "${PROJECT_BINARY_DIR}"
)