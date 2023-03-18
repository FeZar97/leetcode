cmake_minimum_required(VERSION 3.10.2)

project(23_H_merge_K_sorted_lists)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
