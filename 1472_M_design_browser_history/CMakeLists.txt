cmake_minimum_required(VERSION 3.10.2)

project(1472_M_design_browser_history)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
