cmake_minimum_required(VERSION 3.10.2)

project(2348_M_number_of_zero_filled_subarrays)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
