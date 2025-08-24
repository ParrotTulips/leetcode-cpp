cmake_minimum_required(VERSION 3.10)
project(leetcode-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add problems subdirectory - it will automatically discover all problems
add_subdirectory(src/problems)

# Add tests subdirectory - it will automatically discover all tests
add_subdirectory(tests/problems)
