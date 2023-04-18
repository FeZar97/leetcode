cmake_minimum_required(VERSION 3.10.2)

project(1768_E_merge_strings_alternately)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
