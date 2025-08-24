# Automatically discover all problem subdirectories
file(GLOB PROBLEM_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

foreach(PROBLEM_DIR ${PROBLEM_DIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${PROBLEM_DIR})
        # Check if the subdirectory contains a CMakeLists.txt
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${PROBLEM_DIR}/CMakeLists.txt)
            add_subdirectory(${PROBLEM_DIR})
        else()
            # If no CMakeLists.txt exists, create a simple library for this problem
            file(GLOB PROBLEM_SOURCES ${PROBLEM_DIR}/*.cpp)
            if(PROBLEM_SOURCES)
                string(REPLACE "/" "_" LIB_NAME ${PROBLEM_DIR})
                add_library(leetcode_${LIB_NAME} ${PROBLEM_SOURCES})
                target_include_directories(leetcode_${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/${PROBLEM_DIR})
            endif()
        endif()
    endif()
endforeach()