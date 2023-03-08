cmake_minimum_required(VERSION 3.10.2)

project(1521_H_val_myesterious_func_closest2target)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
