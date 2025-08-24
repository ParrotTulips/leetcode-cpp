include(CTest)                       # 开启 CTest 集成
include(FetchContent)                # 用于拉取 Catch2

# ----- 获取 Catch2 v3（推荐固定一个稳定 tag）-----
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.6.0
)
FetchContent_MakeAvailable(Catch2)   # 提供 Catch2::Catch2 / ::Catch2WithMain 以及 Catch.cmake

# 可选：让测试“在运行前”再做一次发现（对某些生成器更稳）
# 需在第一次调用 catch_discover_tests 之前设置
set(CMAKE_CATCH_DISCOVER_TESTS_DISCOVERY_MODE PRE_TEST)

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

    # 链接 Catch2（使用带 main 的目标，测试文件里无需自定义 main）
    target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2WithMain)

    # 让 CTest 自动把每个 TEST_CASE 注册为独立测试
    include(Catch)  # 来自 Catch2，提供 catch_discover_tests
    catch_discover_tests(${TEST_NAME}
        TEST_PREFIX "${TEST_NAME}::"   # 测试名前缀（便于区分不同文件）
        # 可选：输出格式、工作目录等高级参数见文档
        # REPORTER junit OUTPUT_DIR ${CMAKE_BINARY_DIR}/test-reports OUTPUT_SUFFIX .xml
    )
endforeach()
