cmake_minimum_required(VERSION 3.10)
project(leetcode-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files
file(GLOB_RECURSE SOURCES "src/**/*.cpp")

# Create library for solutions
add_library(leetcode_solutions ${SOURCES})

# 新增第二题库
add_subdirectory(src/problems/002_add_two_numbers)

# 新增第二题测试
add_subdirectory(tests/problems)

# Test executables
## 002题测试已由add_subdirectory(tests/problems)管理，避免重复添加

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
