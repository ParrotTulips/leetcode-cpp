# Get current directory name
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Create library name: leetcode_ + directory name
add_library(leetcode_${DIR_NAME}
    solution.cpp
)
target_include_directories(leetcode_${DIR_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
