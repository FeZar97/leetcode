cmake_minimum_required(VERSION 3.10.2)

project(2492_M_minimum_score_of_a_path_between_two_cities)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
