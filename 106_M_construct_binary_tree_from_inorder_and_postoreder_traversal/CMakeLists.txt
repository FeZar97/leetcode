cmake_minimum_required(VERSION 3.10.2)

project(106_M_construct_binary_tree_from_inorder_and_postoreder_traversal)

add_executable(
	${PROJECT_NAME}
	main.cpp
)

target_link_libraries(
	${PROJECT_NAME} 
	..\\..\\${GTEST_LIBRARIES}
)
