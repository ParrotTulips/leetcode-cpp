include(CTest)                       # 开启 CTest 集成

# 自动发现当前目录下所有测试源文件
file(GLOB TEST_FILES *.cpp)

foreach(TEST_FILE ${TEST_FILES})
    # e.g. tests/test_0001_two_sum.cpp -> test_0001_two_sum
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    # e.g. test_0001_two_sum -> 0001_two_sum
    string(REGEX REPLACE "^test_(.+)$" "\\1" PROBLEM_NAME ${TEST_NAME})

    # 为这个测试编译一个可执行文件
    add_executable(${TEST_NAME} ${TEST_FILE})

    # 链接对应题目的被测库（若存在）
    set(PROBLEM_LIB_NAME "leetcode_${PROBLEM_NAME}")
    if(TARGET ${PROBLEM_LIB_NAME})
        target_link_libraries(${TEST_NAME} PRIVATE ${PROBLEM_LIB_NAME})
        target_include_directories(${TEST_NAME} PRIVATE
            ${CMAKE_SOURCE_DIR}/src/problems/${PROBLEM_NAME})
    else()
        message(WARNING "Library ${PROBLEM_LIB_NAME} not found for test ${TEST_NAME}")
    endif()

    # 链接 GTest（使用带 main 的目标，测试文件里无需自定义 main）
    target_link_libraries(${TEST_NAME} PRIVATE gtest_main)

    # 让 CTest 自动发现测试
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
