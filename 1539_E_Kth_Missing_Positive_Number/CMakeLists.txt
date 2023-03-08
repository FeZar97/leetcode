cmake_minimum_required(VERSION 3.10.2)

project(1539_E_Kth_Missing_Positive_Number)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
