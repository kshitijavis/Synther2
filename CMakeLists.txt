cmake_minimum_required(VERSION 3.10)
project(synther VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_NAME synther)
set(LOGIC_LIBRARY_NAME logic)

option(ENABLE_TESTING "Enable a Unit Testing build" ON)

# Directories
add_subdirectory(app)
add_subdirectory(src)
add_subdirectory(configured)

# Includes
include(FetchContent)

# Dependencies
if(ENABLE_TESTING)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v3.5.3
        GIT_SHALLOW TRUE 
    )
    FetchContent_MakeAvailable(Catch2)
endif()

if(ENABLE_TESTING)
    include(CTest)
    add_subdirectory(tests)
    enable_testing()
endif()