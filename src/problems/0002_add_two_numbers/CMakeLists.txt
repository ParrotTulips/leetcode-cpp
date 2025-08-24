# 获取当前目录名
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# 创建库名：leetcode_ + 目录名
add_library(leetcode_${DIR_NAME}
    solution.cpp
)
target_include_directories(leetcode_${DIR_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
