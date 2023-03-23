cmake_minimum_required(VERSION 3.10.2)

project(1319_M_number_of_operations_to_make_network_connected)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
