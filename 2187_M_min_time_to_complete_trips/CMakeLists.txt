cmake_minimum_required(VERSION 3.10.2)

project(2187_M_min_time_to_complete_trips)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
