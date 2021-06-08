include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(testSolution testSolution.cpp)
target_link_libraries(testSolution IncludeLib)

add_executable(testListNode testListNode.cpp)
target_link_libraries(testListNode IncludeLib)

add_executable(testTreeNode testTreeNode.cpp)
target_link_libraries(testTreeNode IncludeLib)

add_executable(testVectorPrint testVectorPrint.cpp)
target_link_libraries(testVectorPrint IncludeLib)
