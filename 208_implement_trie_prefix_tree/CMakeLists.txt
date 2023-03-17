cmake_minimum_required(VERSION 3.10.2)

project(208_implement_trie_prefix_tree)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
