include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(binary_search_tree binary_search_tree.cpp)
target_link_libraries(binary_search_tree IncludeLib)

add_executable(binary_tree_traverse binary_tree_traverse.cpp)
target_link_libraries(binary_tree_traverse IncludeLib)

add_executable(string_match string_match.cpp)
