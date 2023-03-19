cmake_minimum_required(VERSION 3.10.2)

project(211_M_design_add_and_search_words_data_structure)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
