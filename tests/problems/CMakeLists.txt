# Automatically discover all test files
file(GLOB TEST_FILES *.cpp)

foreach(TEST_FILE ${TEST_FILES})
    # Get filename without extension
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    
    # Extract problem name from test filename (e.g., test_001_two_sum -> 001_two_sum)
    string(REGEX REPLACE "^test_(.+)$" "\\1" PROBLEM_NAME ${TEST_NAME})
    
    # Create executable for this test
    add_executable(${TEST_NAME} ${TEST_FILE})
    
    # Try to link with the corresponding problem library
    set(PROBLEM_LIB_NAME "leetcode_${PROBLEM_NAME}")
    
    # Check if the target exists before linking
    if(TARGET ${PROBLEM_LIB_NAME})
        target_link_libraries(${TEST_NAME} ${PROBLEM_LIB_NAME})
        target_include_directories(${TEST_NAME} PRIVATE
            ${CMAKE_SOURCE_DIR}/src/problems/${PROBLEM_NAME}
        )
    else()
        message(WARNING "Library ${PROBLEM_LIB_NAME} not found for test ${TEST_NAME}")
    endif()
endforeach()
