cmake_minimum_required(VERSION 3.10.2)

project(959_M_regions_cut_by_slashes)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
