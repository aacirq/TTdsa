include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(testSolution testSolution.cpp)
target_link_libraries(testSolution IncludeLib)
