cmake_minimum_required(VERSION 3.10.2)

project(958_M_check_completness_of_a_binary_tree)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
