cmake_minimum_required(VERSION 3.9)

project(sequences)

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/../googletest"
    "googletest"
    )

# Test target
add_executable(
    test_lists
    test/test_linked_list.cpp
    )

# Add src to the include directories for the test target
target_include_directories(
    test_lists PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )
# Link test target against gtest libraries
target_link_libraries(
    test_lists PRIVATE
    gtest gtest_main
    )
add_test(test test_lists)
