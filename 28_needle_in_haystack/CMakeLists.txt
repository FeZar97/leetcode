cmake_minimum_required(VERSION 3.10.2)

project(28_needle_in_haystack)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
