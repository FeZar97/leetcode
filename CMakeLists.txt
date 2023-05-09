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
add_subdirectory(54_M_spiral_matrix)
add_subdirectory(64_M_minimum_path_sum)
add_subdirectory(101_E_symmetric_tree)
add_subdirectory(106_M_construct_binary_tree_from_inorder_and_postoreder_traversal)
add_subdirectory(129_M_sum_root_to_leaf_numbers)
add_subdirectory(208_implement_trie_prefix_tree)
add_subdirectory(211_M_design_add_and_search_words_data_structure)
add_subdirectory(605_E_can_place_flowers)
add_subdirectory(958_M_check_completness_of_a_binary_tree)
add_subdirectory(959_M_regions_cut_by_slashes)
add_subdirectory(983_M_minimum_cost_for_tickets)
add_subdirectory(1192_H_critical_connection_in_a_network)
add_subdirectory(1319_M_number_of_operations_to_make_network_connected)
add_subdirectory(1472_M_design_browser_history)
add_subdirectory(1521_H_val_myesterious_func_closest2target)
add_subdirectory(1539_E_Kth_Missing_Positive_Number)
add_subdirectory(1572_E_matrix_diagonal_sum)
add_subdirectory(1768_E_merge_strings_alternately)
add_subdirectory(2187_M_min_time_to_complete_trips)
add_subdirectory(2348_M_number_of_zero_filled_subarrays)
add_subdirectory(2492_M_minimum_score_of_a_path_between_two_cities)



