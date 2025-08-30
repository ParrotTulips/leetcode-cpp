include(FetchContent)

# Fetch and make GTest available
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# Automatically discover all test source files in current directory
file(GLOB TEST_FILES *.cpp)

foreach(TEST_FILE ${TEST_FILES})
    # e.g. tests/test_0001_two_sum.cpp -> test_0001_two_sum
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    # e.g. test_0001_two_sum -> 0001_two_sum
    string(REGEX REPLACE "^test_(.+)$" "\\1" PROBLEM_NAME ${TEST_NAME})

    # Compile an executable for this test
    add_executable(${TEST_NAME} ${TEST_FILE})

    # Link the corresponding problem library (if exists)
    set(PROBLEM_LIB_NAME "leetcode_${PROBLEM_NAME}")
    if(TARGET ${PROBLEM_LIB_NAME})
        target_link_libraries(${TEST_NAME} PRIVATE ${PROBLEM_LIB_NAME})
         # Link GTest (using target with main, no need to define main in test files)
        target_link_libraries(${TEST_NAME} PRIVATE gtest_main)

        target_include_directories(${TEST_NAME} PRIVATE
            ${CMAKE_SOURCE_DIR}/src/problems/${PROBLEM_NAME})

        gtest_discover_tests(${TEST_NAME})
    else()
        message(WARNING "Library ${PROBLEM_LIB_NAME} not found for test ${TEST_NAME}")
    endif()

endforeach()
