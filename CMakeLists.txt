cmake_minimum_required(VERSION 3.10.2)

project(leetcode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(GTEST_INCLUDE_DIR ..\\googletest\\googletest\\include)
set(GTEST_LIBRARY ..\\googletest\\build\\lib\\Debug\\gtest.lib)
set(GTEST_MAIN_LIBRARY ..\\googletest\\build\\lib\\Debug\\gtest_main.lib)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

find_package(GTest REQUIRED)

string(REPLACE "/MDd" "/MTd" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

include_directories(
    ${GTEST_INCLUDE_DIRS}
)

add_subdirectory(23_H_merge_K_sorted_lists)
add_subdirectory(28_M_needle_in_haystack)
add_subdirectory(101_E_symmetric_tree)
add_subdirectory(1521_H_val_myesterious_func_closest2target)
add_subdirectory(1539_E_Kth_Missing_Positive_Number)
add_subdirectory(2187_M_min_time_to_complete_trips)


add_subdirectory(YandexCup_mashup_test_A_A_plus_B)

