cmake_minimum_required(VERSION 3.10.2)

project(983_M_minimum_cost_for_tickets)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
