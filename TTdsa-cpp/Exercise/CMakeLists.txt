include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(N01 array/N01.cpp)
target_link_libraries(N01 IncludeLib)
