cmake_minimum_required(VERSION 3.10.2)

project(59_M_spiral_matrix_II)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
