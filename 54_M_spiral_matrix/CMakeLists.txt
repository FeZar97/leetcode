cmake_minimum_required(VERSION 3.10.2)

project(54_M_spiral_matrix)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
