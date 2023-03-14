cmake_minimum_required(VERSION 3.10.2)

project(129_M_sum_root_to_leaf_numbers)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
