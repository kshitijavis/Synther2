cmake_minimum_required(VERSION 3.10)
project(synther VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_NAME synther)
set(LOGIC_LIBRARY_NAME logic)

configure_file(synther.h.in synther.h)

# Libraries
add_subdirectory(app)
add_subdirectory(src)

target_include_directories(synther PUBLIC 
    "${PROJECT_BINARY_DIR}"
)