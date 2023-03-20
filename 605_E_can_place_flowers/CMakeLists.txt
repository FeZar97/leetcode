cmake_minimum_required(VERSION 3.10.2)

project(605_E_can_place_flowers)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
