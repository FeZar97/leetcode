cmake_minimum_required(VERSION 3.10.2)

project(1192_H_critical_connection_in_a_network)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
